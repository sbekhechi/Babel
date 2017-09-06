#include "arconjdialog.h"
#include "ui_arconjdialog.h"

arconjdialog::arconjdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arconjdialog)
{
    ui->setupUi(this);
}

arconjdialog::~arconjdialog()
{
    delete ui;
}
