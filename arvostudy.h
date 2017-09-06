#ifndef ARVOSTUDY_H
#define ARVOSTUDY_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class arvostudy;
}

class arvostudy : public QDialog
{
    Q_OBJECT

public:
    explicit arvostudy(QWidget *parent = 0);
    ~arvostudy();

private slots:
    void on_Next_clicked();

private:
    Ui::arvostudy *ui;
    arvostudy* chaptfile;
    QFile* arFile;
    QTextStream* ar;
};

#endif // ARVOSTUDY_H
