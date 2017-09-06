#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_NounTreeWidget_clicked(const QModelIndex &index)                 //Russian Tree Widgets
{
    if (index.row()==0) //Masculine Nouns
    {
    rusnouns = new RusNounDialog;
    rusnouns->show();
    rusnouns->setFixedHeight(490);
    if (ui->stressbox->isChecked())
       rusnouns->words= new wordArray(":/new/rustext/table2.txt"   );// ":/rustextstress/table2.txt");
    else
        rusnouns->words= new wordArray(":/new/rustext/table.txt");
    }
}


void MainWindow::on_VerbTreeWidget_clicked(const QModelIndex &index)
{
    if (index.row()==0 & index.parent().row()==0)//All Imperfective Verbs
    {
    rusverbs = new RusVerbDialog;
    rusverbs->show();
    rusverbs->setFixedHeight(490);
    rusverbs->words= new wordArray(":/new/rustext/verbs1.txt");
    }
}



void MainWindow::on_AdjTreeWidget_clicked(const QModelIndex &index)
{
    if (index.row()==0)
    {
    rusadjs = new RusAdjDialog;
    rusadjs->show();
    rusadjs->setFixedHeight(490);
    rusadjs->words= new wordArray(":/new/rustext/colors.txt");
    }
}


void MainWindow::on_JapaneseStudymode_clicked(const QModelIndex &index)
{
   if (index.row()==0 )
   {   chp1 = new Chapter1Dialog;
       chp1->show();
   }
   if (index.row() ==1){
       chp2 = new Chpt2Dialog;
       chp2 -> show();
   }
   if (index.row() ==2){
       chp3 = new chpt3Dialog;
       chp3 -> show();
   }
   if (index.row() ==3){
       chp4 = new Chpt4Dialog;
       chp4 -> show();
   }
   if (index.row()==4){
       chp5 = new chpt5Dialog;
       chp5 -> show();
   }

}
void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    if (index.row()==0 )
    {   t1 = new JPchpt1Test;
        t1->show();
    }
    /*
    if (index.row() ==1){
        chp2 = new Chpt2Dialog;
        chp2 -> show();
    }
    if (index.row() ==2){
        chp3 = new chpt3Dialog;
        chp3 -> show();
    }
    if (index.row() ==3){
        chp4 = new Chpt4Dialog;
        chp4 -> show();
    }
    if (index.row()==4){
        chp5 = new chpt5Dialog;
        chp5 -> show();
        */
}


void MainWindow::on_Mac_clicked()
{
    QString link = "http://m.wikihow.com/Change-the-Keyboard-Language-of-a-Mac";
    QDesktopServices :: openUrl (QUrl(link));
}

void MainWindow::on_Windows_clicked()
{
    QString link2 = "https://support.microsoft.com/en-us/kb/258824";
    QDesktopServices ::openUrl(QUrl(link2));
}

void MainWindow::on_Ubuntun_clicked()
{
    QString link3 = "http://m.wikihow.com/Change-Keyboard-Layout-in-Ubuntu";
    QDesktopServices::openUrl(QUrl(link3));
}

/*void MainWindow::on_vowelstress_clicked(bool checked)
{
    //idk
}
*/




void MainWindow::on_treeWidget_2_clicked(const QModelIndex &index)
{
    if (index.row()==1)
    {
    arvo = new arvocabdialog;
    arvo->show();
    }
    if(index.row()==0)
    {
    arvos = new arvostudy;
    arvos->show();
    }
}

void MainWindow::on_treeWidget_3_clicked(const QModelIndex &index)
{
    if (index.row()==0)
    {
    arconj = new arconjdialog;
    arconj->show();
    }
}
