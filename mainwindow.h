#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QtCore>
#include <Qfile>
#include <QUrl>
#include <QDesktopServices>
#include <rusnoundialog.h>
#include <rusverbdialog.h>
#include <rusadjdialog.h>
#include <arvocabdialog.h>
#include <arconjdialog.h>
#include <arvostudy.h>
#include <chapter1dialog.h>
#include <chpt2dialog.h>
#include <chpt3dialog.h>
#include <chpt4dialog.h>
#include <chpt5dialog.h>
#include <wordarray.h>
#include <jpchpt1test.h>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    QString filereturned;
    ~MainWindow();

private slots:

    //void on_vocab_clicked();

    void on_NounTreeWidget_clicked(const QModelIndex &index);

    void on_VerbTreeWidget_clicked(const QModelIndex &index);

    void on_AdjTreeWidget_clicked(const QModelIndex &index);


    void on_JapaneseStudymode_clicked(const QModelIndex &index);


    void on_Mac_clicked();

    void on_Windows_clicked();

    void on_Ubuntun_clicked();

 //   void on_vowelstress_clicked(bool checked);

    void on_treeWidget_clicked(const QModelIndex &index);


//    void on_vocab_clicked(const QModelIndex &index);

  //  void on_conj_clicked(const QModelIndex &index);

    void on_treeWidget_2_clicked(const QModelIndex &index);

    void on_treeWidget_3_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    RusNounDialog *rusnouns; //Russian
    RusVerbDialog *rusverbs;
    RusAdjDialog *rusadjs;

    arvocabdialog *archap; //Arabic

    Chapter1Dialog *chp1; //Japanese ch1 tree widgets
    Chpt2Dialog *chp2; //Japanese ch2 tree widgets
    chpt3Dialog *chp3; //Japanese ch3 tree widgets
    Chpt4Dialog *chp4; //Japanese ch4 tree widgets
    chpt5Dialog *chp5; // Japanese ch5 tree widgets

    JPchpt1Test *t1; // Japanese Test
    arvocabdialog *arvo; //Arabic Game
    arvostudy *arvos; //Arabic Study

    arconjdialog *arconj;


};

#endif // MAINWINDOW_H
