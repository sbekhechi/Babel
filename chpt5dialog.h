#ifndef CHPT5DIALOG_H
#define CHPT5DIALOG_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class chpt5Dialog;
}

class chpt5Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit chpt5Dialog(QWidget *parent = 0);
    ~chpt5Dialog();

private slots:
    void on_Next_clicked();

private:
    Ui::chpt5Dialog *ui;
    chpt5Dialog *chp5;
    QFile* vocab5File;
    QTextStream* vocab5;
};

#endif // CHPT5DIALOG_H
