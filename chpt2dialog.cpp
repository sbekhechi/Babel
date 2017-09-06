#include "chpt2dialog.h"
#include "ui_chpt2dialog.h"
#include "wordarray.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>

Chpt2Dialog::Chpt2Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chpt2Dialog)
{
    ui->setupUi(this);

    vocab2File = new QFile(":/JapaneseText/chpt2vocab.txt");
    vocab2File->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab2 = new QTextStream( vocab2File );

    this->on_Next_clicked();

}

Chpt2Dialog::~Chpt2Dialog()
{
    delete ui;
}

void Chpt2Dialog::on_Next_clicked()
{
    if (!vocab2->atEnd()) {
        QString content = vocab2->readLine();
        QStringList l = content.split("	");
        ui -> Japanese2 -> setText(l[2]);
        ui -> English2 -> setText(l[3]);
    }
}

