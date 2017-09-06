#ifndef JPCHPT1TEST_H
#define JPCHPT1TEST_H

#include <QDialog>
#include <QtCore>

namespace Ui {
class JPchpt1Test;
}

class JPchpt1Test : public QDialog
{
    Q_OBJECT

public:
    explicit JPchpt1Test(QWidget *parent = 0);
    ~JPchpt1Test();

private slots:
    void on_A_clicked();
    void on_B_clicked();
    void on_C_clicked();
    void on_D_clicked();
    void on_Next_clicked();

private:
    Ui::JPchpt1Test *ui;
    JPchpt1Test *chptest1;
    QFile* vocabFile;
    QTextStream* vocab;
};

#endif // JPCHPT1TEST_H
