#include "chapter1dialog.h"
#include "ui_chapter1dialog.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>


Chapter1Dialog::Chapter1Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Chapter1Dialog)
{
    ui->setupUi(this);
    vocabFile = new QFile(":/JapaneseText/chpt1vocab.txt");
    vocabFile->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab = new QTextStream( vocabFile );

    this->on_Next_clicked();

}

Chapter1Dialog::~Chapter1Dialog()
{
    delete ui;
    delete vocab;
    delete vocabFile;
}


void Chapter1Dialog::on_Next_clicked() {
    if (!vocab->atEnd()) {
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> Japanese -> setText(l[2]);
        ui -> English -> setText(l[3]);
    }
}
