#ifndef ARCONJDIALOG_H
#define ARCONJDIALOG_H

#include <QDialog>

namespace Ui {
class arconjdialog;
}

class arconjdialog : public QDialog
{
    Q_OBJECT

public:
    explicit arconjdialog(QWidget *parent = 0);
    ~arconjdialog();

private:
    Ui::arconjdialog *ui;
};

#endif // ARCONJDIALOG_H
