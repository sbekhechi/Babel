#include "chpt5dialog.h"
#include "ui_chpt5dialog.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>


chpt5Dialog::chpt5Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::chpt5Dialog)
{
    ui->setupUi(this);
    vocab5File = new QFile(":/JapaneseText/chpt4vocab.txt");
    vocab5File->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab5 = new QTextStream( vocab5File );

    this->on_Next_clicked();
}

chpt5Dialog::~chpt5Dialog()
{
    delete ui;
}

void chpt5Dialog::on_Next_clicked()
{
    if (!vocab5->atEnd()) {
        QString content = vocab5->readLine();
        QStringList l = content.split("	");
        ui -> Japanese5 -> setText(l[2]);
        ui -> English5 -> setText(l[3]);
    }

}
