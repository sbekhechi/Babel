#include "rusnoundialog.h"
#include "ui_rusnoundialog.h"
#include <QMessageBox>

RusNounDialog::RusNounDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RusNounDialog)
{
    ui->setupUi(this);
    ui->correctlabel->setVisible(false);
    ui->wronglabel->setVisible(false);
    ui->correctword->setVisible(false);
    startpressed=false;
    MyTimer = new QTimer(this);
    fred = new QTime(0,5,0,0);
    n = 300;
    connect(MyTimer,SIGNAL(timeout()),this,SLOT(runOnTick()));
}

RusNounDialog::~RusNounDialog()
{
    delete ui;
    delete words;
}

void RusNounDialog::runOnTick()
{
    n-=1;
    int m=n/60;
    int s=n-m*60;
    ui->TimeBox->setText(QString::number(m)+":"+QString::number(s));
    if (m<=0 & s<=0)
        ui->Stop->clicked();
}

void RusNounDialog::on_Start_clicked()
{
    if (ui->DontTime->isChecked());

    else
    {
    QString b = ui->Minutes->displayText();
    int m= b[0].digitValue();
    int s=0;
    fred->setHMS(0,m,s,0);
    n=m*60+s;
    MyTimer->start(1000);
    }

    words->setrandomnoun();
    qDebug()<<QString::number(words->getrl());
    qDebug()<<QString::number(words->getrc());
    ui->Case->setText(words->Case());

    if (ui->GiveMeEnglish->isChecked())
    {
        ui->NomNoun->setText(words->word[words->getrl()][0]);
    }

    else
    {
        ui->NomNoun->setText(words->word[words->getrl()][1]);
    }

    words->sc=0;
    words->tot=0;
    ui->Score->setText(QString::number(words->sc)+"/"+QString::number(words->tot));
    startpressed=true;
}

void RusNounDialog::on_Answer_returnPressed()
{
    if (startpressed)
    {
        QString b = ui->Answer->displayText();
        ui->correctword->setText(words->verify(b));

        if (words->correct)
        {
            ui->correctlabel->setVisible(true);
            ui->wronglabel->setVisible(false);
            ui->correctword->setVisible(false);
            words->sc+=1;
            words->tot++; //increases the total number of questions answered for this excercise
            ui->Score->setText(QString::number(words->sc)+"/"+QString::number(words->tot)); //puts text into the questions answered portion
            ui->Answer->clear(); //clears the line
            words->setrandomnoun(); //gives a new word to test
        }

        else
        {
            ui->wronglabel->setVisible(true);
            ui->correctword->setVisible(true);
            ui->correctlabel->setVisible(false);
            words->tot++; //increases the total number of questions answered for this excercise
            ui->Score->setText(QString::number(words->sc)+"/"+QString::number(words->tot)); //puts text into the questions answered portion
            ui->Answer->clear(); //clears the line
        }

        ui->Case->setText(words->Case());

        if (ui->GiveMeEnglish->checkState())
        {
        ui->NomNoun->setText(words->word[words->getrl()][0]);
        }

        else
        {
        ui->NomNoun->setText(words->word[words->getrl()][1]);
        }
    }

    else
    {
        QMessageBox::information(this,"", "Please press Start");
    }
}

void RusNounDialog::on_GiveMeEnglish_stateChanged(int arg1)
{
    if (arg1)
    ui->GiveMeRussian->setChecked(false);
}

void RusNounDialog::on_GiveMeRussian_stateChanged(int arg1)
{
    if (arg1)
        ui->GiveMeEnglish->setChecked(false);
}

void RusNounDialog::on_Stop_clicked()
{
    QMessageBox::information(this,"", "Your Score is: "+ui->Score->text());
    words->sc=0;
    words->tot=0;
    MyTimer->stop();
}

void RusNounDialog::on_check_clicked()
{
    ui->Answer->returnPressed();
}

void RusNounDialog::on_Define_clicked()
{
    QMessageBox::information(this,"Definition",words->word[words->getrl()][1]+" means "+ words->word[words->getrl()][0]);
}

void RusNounDialog::on_Decline_clicked()
{
    QMessageBox::information(this,"Declensions","Nominative: "+words->word[words->getrl()][1]+"\n"
                                        "Genetive: " +words->word[words->getrl()][2]+"\n"
                                        "Dative: " +words->word[words->getrl()][3]+"\n"
                                        "Accusative: " +words->word[words->getrl()][4]+"\n"
                                        "Instrumental: " +words->word[words->getrl()][5]+"\n"
                                        "Prepositional: " +words->word[words->getrl()][6]);
}

void RusNounDialog::on_GoldSheet_clicked()
{
    QMessageBox Gold(this);
    Gold.setText("Gold Sheet");
    QPixmap sheet(":/new/babelpic/goldsheet.png",0,Qt::MonoOnly);
    sheet.scaled(200,150);
    Gold.setIconPixmap(sheet);
    Gold.exec();
}
