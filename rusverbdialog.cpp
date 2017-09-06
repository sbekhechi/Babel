#include "rusverbdialog.h"
#include "ui_rusverbdialog.h"
#include <QMessageBox>

RusVerbDialog::RusVerbDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RusVerbDialog)
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

RusVerbDialog::~RusVerbDialog()
{
    delete ui;
    delete words;
}

void RusVerbDialog::runOnTick()
{
    n-=1;
    int m=n/60;
    int s=n-m*60;
    ui->TimeBox->setText(QString::number(m)+":"+QString::number(s));
    if (m<=0 & s<=0)
        ui->Stop->clicked();
}

void RusVerbDialog::on_Start_clicked()
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
    ui->Case->setText(words->pronoun());

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

void RusVerbDialog::on_Answer_returnPressed()
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

        ui->Case->setText(words->pronoun());

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

void RusVerbDialog::on_GiveMeEnglish_stateChanged(int arg1)
{
    if (arg1)
    ui->GiveMeRussian->setChecked(false);
}

void RusVerbDialog::on_GiveMeRussian_stateChanged(int arg1)
{
    if (arg1)
        ui->GiveMeEnglish->setChecked(false);
}

void RusVerbDialog::on_Stop_clicked()
{
    QMessageBox::information(this,"", "Your Score is: "+ui->Score->text());
    words->sc=0;
    words->tot=0;
    MyTimer->stop();
}

void RusVerbDialog::on_check_clicked()
{
    ui->Answer->returnPressed();
}

void RusVerbDialog::on_Define_clicked()
{
    QMessageBox::information(this,"Definition",words->word[words->getrl()][1]+" means to "+ words->word[words->getrl()][0]);
}

void RusVerbDialog::on_Decline_clicked()
{
    QMessageBox::information(this,"Declensions",
                                        "Infinitive: "+words->word[words->getrl()][1]+"\n"
                                        "Я "+words->word[words->getrl()][2]+"\n"
                                        "Ты " +words->word[words->getrl()][3]+"\n"
                                        "он/она/оно " +words->word[words->getrl()][4]+"\n"
                                        "мы " +words->word[words->getrl()][5]+"\n"
                                        "вы " +words->word[words->getrl()][6]+"\n"
                                        "они " +words->word[words->getrl()][7]+"\n"
                                          "ты (imperaative mood) " +words->word[words->getrl()][8]+"\n"
                                          "вы (imperative mood) " +words->word[words->getrl()][9]+"\n"
                                        "он (past tense) " +words->word[words->getrl()][10]+"\n"
                                              "она (past tense) " +words->word[words->getrl()][11]+"\n"
                                               "оно (past tense) " +words->word[words->getrl()][12]+"\n"
                                               "они (past tense) " +words->word[words->getrl()][13]);
}

void RusVerbDialog::on_GoldSheet_clicked()
{
    QMessageBox Gold(this);
    Gold.setText("Gold Sheet");
    QPixmap sheet(":/new/babelpic/conjugation.gif",0,Qt::MonoOnly);
    sheet.scaled(200,150);
    Gold.setIconPixmap(sheet);
    Gold.exec();
}
