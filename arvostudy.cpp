#include "arvostudy.h"
#include "ui_arvostudy.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>


arvostudy::arvostudy(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arvostudy)
{
    ui->setupUi(this);

    arFile = new QFile (":/arabic/ArCh1Vocab.txt");
    arFile -> open(QIODevice::ReadOnly| QIODevice::Text);
    ar = new QTextStream (arFile);

    this->on_Next_clicked();
}

arvostudy::~arvostudy()
{
    delete ui;
    delete arFile;
    delete ar;
};



void arvostudy::on_Next_clicked()
{
    if(!ar -> atEnd()) {
        QString content = ar -> readLine();
        QStringList list = content.split(" ");
        ui-> English -> setText(list[0]);
        ui-> Arabic -> setText(list[1]);
    }
}
