#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QTreeWidget>
#include "downloader.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(Downloader &d, int i, QWidget *parent = 0);
    ~Form();

private:
    Ui::Form *ui;
};

#endif // FORM_H
