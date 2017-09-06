#ifndef CHPT3DIALOG_H
#define CHPT3DIALOG_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class chpt3Dialog;
}

class chpt3Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chpt3Dialog(QWidget *parent = 0);
    ~chpt3Dialog();

private slots:
    void on_Next_clicked();

private:
    Ui::chpt3Dialog *ui;
    chpt3Dialog *chp3;
    QFile* vocab3File;
    QTextStream* vocab3;
};

#endif // CHPT3DIALOG_H
