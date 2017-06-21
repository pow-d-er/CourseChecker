#include "mainwindow.h"
#include "downloader.h"
#include "storage.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    Storage s;
    int x;
    QVector<QString> league;

    x = w.CreateList();
    s.HowMuch(x);
    Downloader d1(x);
    Downloader d2(x);

    w.SetPointer(s);
    s.SetPointers(d1,d2);
       for (int i=0; i<x; i++){

          league = w.WhichLeague(i);
        d1.GetData("https://www.efortuna.pl/pl/strona_glowna/pilka-nozna/" + league[1],w.GiveEfortunaList(i));
         w.ClearLists();
        d2.GetData("https://www.totolotek.pl/zaklady-sportowe?CMP=" + league[0],w.GiveLottoList(i));
        w.ClearLists();

            w.delay();

       }
        w.show();
        return a.exec();
}
