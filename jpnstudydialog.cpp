#include "chapter1dialog.h"
#include "jpnstudydialog.h"
#include "ui_jpnstudydialog.h"

JpnstudyDialog::JpnstudyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JpnstudyDialog)
{
    ui->setupUi(this);
}

JpnstudyDialog::~JpnstudyDialog()
{
    delete ui;
}

void JpnstudyDialog::on_Chapter1_clicked()
{
    chp1 = new Chapter1Dialog;
    chp1 -> show();
    //chapter 1 vocab

}

void JpnstudyDialog::on_Chapter2_clicked()
{
    // chapter 2 vocab
}

void JpnstudyDialog::on_Chapter3_clicked()
{
    // chapter 3 vocab

}

void JpnstudyDialog::on_Chapter4_clicked()
{
    // chapter 4 vocab ughgh jhgnajh u kjut jsie ejtn jhgaaaaaa

}

void JpnstudyDialog::on_Chapter5_clicked()
{
    // chapter 5 vocab
}
