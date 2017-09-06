#include "arvocabdialog.h"
#include "ui_arvocabdialog.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>


arvocabdialog::arvocabdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::arvocabdialog)
{
    ui->setupUi(this);
 /*   arFile = new QFile ("://ArCh1Vocab.txt");
    arFile -> open(QIODevice::ReadOnly| QIODevice::Text);
    ar = new QTextStream (arFile);

    this -> on_pushButton_clicked();

    if (!ar -> atEnd()) {
        QString content = ar ->readLine();
      //  QStringList list = content.split("");
        ui -> Translate -> setText("work");
    } */
}

arvocabdialog::~arvocabdialog()
{
    delete ui;
    delete ar;
    delete arFile;
}

void arvocabdialog::on_pushButton_clicked()
{
    arFile = new QFile (":/../../babel/B.txt");

    arFile -> open(QIODevice::ReadOnly| QIODevice::Text);
    ar = new QTextStream (arFile);
    if (!ar -> atEnd()) {
        QString content = ar ->readLine();
        QStringList list = content.split("");
        ui -> Translate -> setText(list[0]);
        ui -> Arabic -> setText("work");
    }
}

