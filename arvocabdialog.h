#ifndef ARVOCABDIALOG_H
#define ARVOCABDIALOG_H

#include <QDialog>
#include <QTCore>


namespace Ui {
class arvocabdialog;
}

class arvocabdialog : public QDialog
{
    Q_OBJECT

public:
    explicit arvocabdialog(QWidget *parent = 0);
    ~arvocabdialog();

private slots:
    void on_pushButton_clicked();

private:
    Ui::arvocabdialog *ui;
    arvocabdialog* chaptfile;
    QFile* arFile;
    QTextStream* ar;
};

#endif // ARVOCABDIALOG_H
