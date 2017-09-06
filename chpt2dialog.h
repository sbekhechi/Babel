#ifndef CHPT2DIALOG_H
#define CHPT2DIALOG_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class Chpt2Dialog;
}

class Chpt2Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Chpt2Dialog(QWidget *parent = 0);
    ~Chpt2Dialog();

private slots:
    void on_Next_clicked();

private:
    Ui::Chpt2Dialog *ui;
    Chpt2Dialog *chp2;
    QFile* vocab2File;
    QTextStream* vocab2;
};

#endif // CHPT2DIALOG_H
