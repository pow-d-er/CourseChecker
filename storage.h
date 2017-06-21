#ifndef STORAGE_H
#define STORAGE_H

#include <QWidget>
#include <QDate>
#include<QTreeWidget>
#include<QTreeWidgetItem>
#include<QTabWidget>
#include "form.h"
#include "downloader.h"


namespace Ui {
class Storage;
}


class Storage : public QWidget
{

    Q_OBJECT
    QList<QTreeWidgetItem*> downloaded1;
    QList<QTreeWidgetItem*> downloaded2;
    QVector<QTreeWidget*> treeWidgets;
    int which;
    int tabWidgetCount;
    double lotto,fortuna;
    QString lottoTeam1,fortunaTeam1,lottoTeam2,fortunaTeam2;

public:
    explicit Storage(QWidget *parent = 0);
    ~Storage();
    void HowMuch(int t);
    void TreeToTab(int i, QString text);
    void SetPointers(Downloader &d1,Downloader &d2);


private:
    Ui::Storage *ui;
    Downloader *downloader1;
    Downloader *downloader2;

};


#endif // STORAGE_H
