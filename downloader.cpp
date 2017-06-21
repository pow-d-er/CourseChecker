#include "downloader.h"
#include "ui_downloader.h"

Downloader::Downloader(int &howMuch, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Downloader),
    manager(new QNetworkAccessManager)
{
    ui->setupUi(this);
    connect(manager, SIGNAL(finished(QNetworkReply*)), this, SLOT(onResult(QNetworkReply*)));
    labels<<"Team 1"<<" - "<<"Team 2"<<"1"<<"X"<<"2";

    treeWidget.resize(howMuch);

    for(int i = 0; i<howMuch; i++){
    treeWidget[i] = new QTreeWidget();

        treeWidget[i]->header()->resizeSection(0,130);
        treeWidget[i]->header()->resizeSection(1,10);
        treeWidget[i]->header()->resizeSection(2,130);
        treeWidget[i]->header()->resizeSection(3,35);
        treeWidget[i]->header()->resizeSection(4,35);
        treeWidget[i]->header()->resizeSection(5,35);
    }
    which = 0;
    when ="";
}

void Downloader::GetData(QString uurl, QStringList list)
{

    List = list;
    QUrl url(uurl);
    QNetworkRequest request;
    request.setUrl(url);
    manager->get(request);



}

void Downloader::onResult(QNetworkReply *reply)
{

    if (reply -> error()) {
        qDebug() << "ERROR";
        qDebug() << reply->errorString();

    }
    else{
        qDebug()<<"Downloading is completed";
        i=5;
        Date = "";
        treeWidget[which]->setHeaderLabels(labels);

        GetList(List);
        if(win1.pattern() == "(?<=data-rate=\")(\\d{1,2}\\.{0,1}\\d{0,2})"){
            while(!reply->atEnd()){
                line = reply->readLine();
                match = date.match(line);
                if (match.hasMatch() && i == 0) Date = match.captured(1);

                match = teamVsTeam.match(line);
                if (match.hasMatch()){i = 0; captured += match.captured(1);}

                match = teamVsTeam.match(line);
                if (match.hasMatch()) captured += match.captured(2);

                match = win1.match(line);
                if (match.hasMatch() && i<3){
                    captured += match.captured(1);
                    i++;

                }
                if (i>2 && Date.length()>0){
                    AddMatch(captured,Date);
                    captured.clear();
                    Date ="";
                }

              }
          }
         else{

                while(!reply->atEnd()){
                    line = reply->readLine();

                        match = date.match(line);
                        if (match.hasMatch()) Date = match.captured(0);

                        match = teamVsTeam.match(line);
                        if (match.hasMatch()) captured += match.captured(1);

                        match = teamVsTeam.match(line);
                        if (match.hasMatch()) captured += match.captured(3);

                        match = win1.match(line);
                        if (match.hasMatch()) captured += match.captured(1).replace(",",".");

                        match = draw.match(line);
                        if (match.hasMatch()) captured += match.captured(1).replace(",",".");

                        match = win2.match(line);
                        if (match.hasMatch()){
                            captured += match.captured(1).replace(",",".");
                            AddMatch(captured,Date);
                            captured.clear();

                        }
                    }
          }
    treeWidget[which]->sortItems(0,Qt::AscendingOrder);
    which++;
    }

}




Downloader::~Downloader()
{
    delete ui;
}

void Downloader::AddMatch(QStringList captured, QString date)
{



    if (when != date){
    topItem = new QTreeWidgetItem(treeWidget[which]);
    treeWidget[which]->addTopLevelItem(topItem);
    topItem->setText(0,date);
    when = date;
    }

    QTreeWidgetItem *item = new QTreeWidgetItem(topItem);
    item->setText(0,captured[0]);
    item->setText(1," - ");
    item->setTextAlignment(1, Qt::AlignHCenter | Qt::AlignVCenter);
    item->setText(2,captured[1]);

    for(int j = 3; j<6; j++){
    item->setText(j,captured[j-1]);
    item->setTextAlignment(j, Qt::AlignHCenter | Qt::AlignVCenter);
    }


}

void Downloader::GetList(QStringList list)
{
    teamVsTeam.setPatternOptions(QRegularExpression::CaseInsensitiveOption);
    QStringList List = list;
    date.setPattern(list.at(0));
    teamVsTeam.setPattern(list.at(1));
    win1.setPattern(list.at(2));
    if(list.size()>3){
    draw.setPattern(list.at(3));
    win2.setPattern(list.at(4));
    }


}

int Downloader::returnWhich()
{
     return which;
}

