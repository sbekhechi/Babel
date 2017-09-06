#include "chpt4dialog.h"
#include "ui_chpt4dialog.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>

Chpt4Dialog::Chpt4Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chpt4Dialog)
{
    ui->setupUi(this);
    vocab4File = new QFile(":/JapaneseText/chpt4vocab.txt");
    vocab4File->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab4 = new QTextStream( vocab4File );

    this->on_Next_clicked();
}

Chpt4Dialog::~Chpt4Dialog()
{
    delete ui;
}

void Chpt4Dialog::on_Next_clicked()
{
    if (!vocab4->atEnd()) {
        QString content = vocab4->readLine();
        QStringList l = content.split("	");
        ui -> Japanese4 -> setText(l[2]);
        ui -> English4 -> setText(l[3]);
    }
}
