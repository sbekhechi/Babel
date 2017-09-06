#ifndef CHAPTER1DIALOG_H
#define CHAPTER1DIALOG_H

#include <QDialog>
#include <QtCore>


namespace Ui {
class Chapter1Dialog;
}

class Chapter1Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Chapter1Dialog(QWidget *parent = 0);
    ~Chapter1Dialog();

private slots:
    void on_Next_clicked();



private:
    Ui::Chapter1Dialog *ui;
    Chapter1Dialog *chp1;
    QFile* vocabFile;
    QTextStream* vocab;
  //  void wordarray();
};

#endif // CHAPTER1DIALOG_H
