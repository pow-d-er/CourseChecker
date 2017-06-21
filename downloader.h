#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QWidget>
#include<QRegularExpression>
#include<QNetworkAccessManager>
#include<QNetworkRequest>
#include<QNetworkReply>
#include <QUrl>
#include<QMessageBox>
#include <QListWidget>
#include <QTreeWidget>

namespace Ui {
class Downloader;
}

class Downloader : public QWidget
{
    Q_OBJECT
    QRegularExpression date;
    QRegularExpression teamVsTeam;
    QRegularExpression win1;
    QRegularExpression draw;
    QRegularExpression win2;
    QRegularExpressionMatch match;
    QString line;
    QStringList captured;
    QString Date;

    double i;
    QStringList labels;
    QStringList List;
    int which;
    QString when;
    QTreeWidgetItem *topItem;
public:

    Downloader(int &howMuch, QWidget *parent = 0);
    ~Downloader();
    void AddMatch(QStringList captured, QString date);
    void GetList(QStringList list);
    int returnWhich();


 QVector<QTreeWidget*> treeWidget;



signals:


public slots:
    void GetData(QString uurl, QStringList list);
    void onResult(QNetworkReply *reply);


private:
    Ui::Downloader *ui;
    QNetworkAccessManager *manager;



};

#endif // DOWNLOADER_H
