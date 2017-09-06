#ifndef JPNSTUDYDIALOG_H
#define JPNSTUDYDIALOG_H

#include <QDialog>
#include <chapter1dialog.h>

namespace Ui {
class JpnstudyDialog;
}

class JpnstudyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit JpnstudyDialog(QWidget *parent = 0);
    ~JpnstudyDialog();

private slots:
    void on_Chapter1_clicked();

    void on_Chapter2_clicked();

    void on_Chapter3_clicked();

    void on_Chapter4_clicked();

    void on_Chapter5_clicked();

private:
    Ui::JpnstudyDialog *ui;
    Chapter1Dialog *chp1;
};

#endif // JPNSTUDYDIALOG_H
