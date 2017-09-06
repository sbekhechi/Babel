#ifndef RUSADJDIALOG_H
#define RUSADJDIALOG_H

#include <QDialog>
#include "wordarray.h"
#include <QtCore>

namespace Ui {
class RusAdjDialog;
}

class RusAdjDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RusAdjDialog(QWidget *parent = 0);
    wordArray *words;
    bool startpressed;
    ~RusAdjDialog();

private slots:
    void runOnTick();

    void on_Answer_returnPressed();

    void on_Start_clicked();

    void on_GiveMeEnglish_stateChanged(int arg1);

    void on_GiveMeRussian_stateChanged(int arg1);

    void on_Stop_clicked();

    void on_check_clicked();

    void on_Define_clicked();

    void on_Decline_clicked();

    void on_GoldSheet_clicked();



private:
    Ui::RusAdjDialog *ui;
    QTimer *MyTimer;
    QTime *fred;
    int n;
};

#endif // RUSADJDIALOG_H
