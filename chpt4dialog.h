#ifndef CHPT4DIALOG_H
#define CHPT4DIALOG_H

#include <QDialog>
#include <Qtcore>

namespace Ui {
class Chpt4Dialog;
}

class Chpt4Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Chpt4Dialog(QWidget *parent = 0);
    ~Chpt4Dialog();

private slots:
    void on_Next_clicked();

private:
    Ui::Chpt4Dialog *ui;
    Chpt4Dialog *chp4;
    QFile* vocab4File;
    QTextStream* vocab4;
};

#endif // CHPT4DIALOG_H
