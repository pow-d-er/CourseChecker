#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
     setWindowTitle("Course Checker");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::CreateList()
{
    new QListWidgetItem("Anglia 1. Liga",ui->listWidget);
    new QListWidgetItem("Niemcy 1. liga",ui->listWidget);
    new QListWidgetItem("Hiszpania 1. liga",ui->listWidget);
    new QListWidgetItem(tr("Włochy 1. liga"),ui->listWidget);

    Lotto.resize(ui->listWidget->count());
    Efortuna.resize(ui->listWidget->count());

    return ui->listWidget->count();

}

QVector<QString> MainWindow::WhichLeague(int i)
{
    league.resize(2);
    league[0] = ui->listWidget->item(i)->text();
    listLotto<<"\\d\\d\\d\\d-\\d\\d-\\d\\d"
        <<tr("(?<=</td><td title=\")(\\w+\\.*\\s*\\w*)(.*;\">)(\\w+\\.*\\s*\\w*)")
        <<"(?<=_1\").*>(\\d+,\\d+)"
        <<"(?<=_2\").*>(\\d+,\\d+)"
        <<"(?<=_3\").*>(\\d+,\\d+)";
    Lotto[i] = listLotto;

    if (league[0] == "Anglia 1. Liga")     league[1] = "premier-league-premiership";
    if (league[0] == "Niemcy 1. liga")     league[1] = "bundesliga";
    if (league[0] == tr("Włochy 1. liga")) league[1] = "serie-a";
    if (league[0] == "Hiszpania 1. liga")  league[1] = "primera-division";

    listEfortuna<<"(?<=\" href=\"/pl/strona_glowna/pilka-nozna/)(\\d\\d\\d\\d-\\d\\d-\\d\\d)"
        <<tr("(?<=data-gtm-enhanced-ecommerce-match=\")(\\S*\\s*\\w*)\\s-\\s(\\S*\\s*\\w*)\"")
        <<"(?<=data-rate=\")(\\d{1,2}\\.{0,1}\\d{0,2})";
    Efortuna[i] = listEfortuna;
    return league;
}

QStringList MainWindow::GiveEfortunaList(int i)
{
    return Efortuna[i];

}

QStringList MainWindow::GiveLottoList(int i)
{
    return Lotto[i];
}

void MainWindow::SetPointer(Storage &s)
{
    storage =&s;
}



void MainWindow::ClearLists()
{
  listLotto.clear();
  listEfortuna.clear();
}

void MainWindow::on_listWidget_doubleClicked(const QModelIndex &index)
{
    storage->TreeToTab(index.row(),ui->listWidget->item(index.row())->text());
    storage->show();
}

void MainWindow::delay()
{
    QTime dieTime= QTime::currentTime().addSecs(2);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}
