#include "chpt3dialog.h"
#include "ui_chpt3dialog.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>

chpt3Dialog::chpt3Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chpt3Dialog)
{
    ui->setupUi(this);

    vocab3File = new QFile(":/JapaneseText/chpt3vocab.txt");
    vocab3File->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab3 = new QTextStream( vocab3File );

    this->on_Next_clicked();
}

chpt3Dialog::~chpt3Dialog()
{
    delete ui;
}

void chpt3Dialog::on_Next_clicked()
{
    if (!vocab3->atEnd()) {
        QString content = vocab3->readLine();
        QStringList l = content.split("	");
        ui -> Japanese3 -> setText(l[2]);
        ui -> English3 -> setText(l[3]);
    }
}
