      #ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "storage.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT


QVector<QStringList> Lotto;
QVector<QStringList> Efortuna;
QStringList listLotto;
QStringList listEfortuna;
QVector<QString> league;

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int CreateList();
    QVector<QString> WhichLeague(int i);

    QStringList GiveEfortunaList(int i);
    QStringList GiveLottoList(int i);
    void SetPointer(Storage &s);

    void ClearLists();
    void delay();

private slots:
    void on_listWidget_doubleClicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    Storage *storage;
};

#endif // MAINWINDOW_H
