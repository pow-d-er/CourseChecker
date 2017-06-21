#include "form.h"
#include "ui_form.h"


Form::Form(Downloader &d,int i, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    ui->gridLayout->addWidget(d.treeWidget[i]);
}

Form::~Form()
{
    delete ui;
}
