#include "jpchpt1test.h"
#include "ui_jpchpt1test.h"
#include <Qstring>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <string>

JPchpt1Test::JPchpt1Test(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::JPchpt1Test)
{
    ui->setupUi(this);

    vocabFile = new QFile(":/JapaneseText/chpt1vocab.txt");
    vocabFile->open(QIODevice::ReadOnly|QIODevice::Text);
    vocab = new QTextStream( vocabFile );

    this->on_A_clicked();
    this->on_B_clicked();
    this->on_C_clicked();
    this->on_D_clicked();
    this->on_Next_clicked();

}

JPchpt1Test::~JPchpt1Test()
{
    delete ui;
    vocabFile->close();
}

void JPchpt1Test::on_Next_clicked()
{
    if(!vocab->atEnd()){
        srand(time(NULL));
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> JapaneseTest1 -> setText(l[2]);
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> A -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> B -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> C -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> D -> setText(l[3]);
        }
    }
    }



void JPchpt1Test::on_A_clicked()
{
    if (!vocab->atEnd()) {
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> JapaneseTest1 -> setText(l[2]);
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> A -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> B -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> C -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> D -> setText(l[3]);
        }
    }
//    else{
//        vocabFile = new QFile(":/JapaneseText/chpt1vocab.txt");
//        vocabFile->open(QIODevice::ReadOnly|QIODevice::Text);
//        vocab = new QTextStream( vocabFile );
//    }
}

void JPchpt1Test::on_B_clicked()
{
    if (!vocab->atEnd()) {
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> JapaneseTest1 -> setText(l[2]);
        for (int i = 0; i < 1 + qrand() % (112 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> A -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> B -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> C -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> D -> setText(l[3]);
        }
    }
}

void JPchpt1Test::on_C_clicked()
{
    srand(time(NULL));
    if (!vocab->atEnd()) {
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> JapaneseTest1 -> setText(l[2]);
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> A -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> B -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> C -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> D -> setText(l[3]);
        }
    }
}

void JPchpt1Test::on_D_clicked()
{
    if (!vocab->atEnd()) {
        QString content = vocab->readLine();
        QStringList l = content.split("	");
        ui -> JapaneseTest1 -> setText(l[2]);
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> A -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> B -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> C -> setText(l[3]);
        }
        for (int i = 0; i < 1 + qrand() % (5 - 1); ++i){
            QString content = vocab->readLine();
            QStringList l = content.split("	");
            ui -> D -> setText(l[3]);
        }
    }
}
