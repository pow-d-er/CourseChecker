#include "storage.h"
#include "ui_storage.h"
#include <QDebug>

Storage::Storage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Storage)
{
    ui->setupUi(this);

}

Storage::~Storage()
{
    delete ui;
}

void Storage::HowMuch(int t)
{
    tabWidgetCount = t;
    treeWidgets.resize(t*2);

}


void Storage::TreeToTab(int i, QString text)
{
    ui->tabWidget->clear();
    setWindowTitle(text);


        for(int j=0; j<downloader1->treeWidget[i]->topLevelItemCount(); j++){
        fortunaTeam1 = downloader1->treeWidget[i]->topLevelItem(j)->text(0);
            for (int a=0; a<downloader2->treeWidget[i]->topLevelItemCount(); a++){
            lottoTeam1 = downloader2->treeWidget[i]->topLevelItem(a)->text(0);

                if ((fortunaTeam1.contains(lottoTeam1) || lottoTeam1.contains(fortunaTeam1))){

                    for(int h=0; h<downloader1->treeWidget[i]->topLevelItem(j)->childCount(); h++){

                        fortunaTeam1 = downloader1->treeWidget[i]->topLevelItem(j)->child(h)->text(0);
                        fortunaTeam2 = downloader1->treeWidget[i]->topLevelItem(j)->child(h)->text(2);

                        for(int g=0; g<downloader2->treeWidget[i]->topLevelItem(a)->childCount(); g++){

                            lottoTeam1 = downloader2->treeWidget[i]->topLevelItem(a)->child(g)->text(0);
                            lottoTeam2 = downloader2->treeWidget[i]->topLevelItem(a)->child(g)->text(2);

                            if ((fortunaTeam1.contains(lottoTeam1) || lottoTeam1.contains(fortunaTeam1) || fortunaTeam2.contains(lottoTeam2) || lottoTeam2.contains(fortunaTeam2))){

                                for(int b=3; b<6; b++){
                                    fortuna = downloader1->treeWidget[i]->topLevelItem(j)->child(h)->text(b).toDouble();
                                    lotto = downloader2->treeWidget[i]->topLevelItem(a)->child(g)->text(b).toDouble();
                                    if (fortuna > lotto){
                                    downloader1->treeWidget[i]->topLevelItem(j)->child(h)->setForeground(b,Qt::green);
                                    downloader2->treeWidget[i]->topLevelItem(a)->child(g)->setForeground(b,Qt::red);
                                    }
                                    else if (fortuna < lotto){
                                    downloader2->treeWidget[i]->topLevelItem(a)->child(g)->setForeground(b,Qt::green);
                                    downloader1->treeWidget[i]->topLevelItem(j)->child(h)->setForeground(b,Qt::red);
                                    }

                                  }
                            }
                        }
                     }
                 }
            }
         }


    ui->tabWidget->addTab(new Form(*downloader1,i),"EFORTUNA");
    ui->tabWidget->addTab(new Form(*downloader2,i),"TOTOLOTEK");




}

void Storage::SetPointers(Downloader &d1, Downloader &d2)
{
    downloader1 = &d1;
    downloader2 = &d2;
}







