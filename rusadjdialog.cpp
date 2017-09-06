#include "rusadjdialog.h"
#include "ui_rusadjdialog.h"
#include <QMessageBox>

RusAdjDialog::RusAdjDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RusAdjDialog)
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

RusAdjDialog::~RusAdjDialog()
{
    delete ui;
    delete words;
}

void RusAdjDialog::runOnTick()
{
    n-=1;
    int m=n/60;
    int s=n-m*60;
    ui->TimeBox->setText(QString::number(m)+":"+QString::number(s));
    if (m<=0 & s<=0)
        ui->Stop->clicked();
}

void RusAdjDialog::on_Start_clicked()
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
    ui->Case->setText(words->adjCase());
    ui->Gender->setText(words->adjGender());

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

void RusAdjDialog::on_Answer_returnPressed()
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

        ui->Case->setText(words->adjCase());
        ui->Gender->setText(words->adjGender());

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

void RusAdjDialog::on_GiveMeEnglish_stateChanged(int arg1)
{
    if (arg1)
    ui->GiveMeRussian->setChecked(false);
}

void RusAdjDialog::on_GiveMeRussian_stateChanged(int arg1)
{
    if (arg1)
        ui->GiveMeEnglish->setChecked(false);
}

void RusAdjDialog::on_Stop_clicked()
{
    QMessageBox::information(this,"", "Your Score is: "+ui->Score->text());
    words->sc=0;
    words->tot=0;
    MyTimer->stop();
}

void RusAdjDialog::on_check_clicked()
{
    ui->Answer->returnPressed();
}

void RusAdjDialog::on_Define_clicked()
{
    QMessageBox::information(this,"Definition",words->word[words->getrl()][1]+" means "+ words->word[words->getrl()][0]);
}

void RusAdjDialog::on_Decline_clicked()
{
    QMessageBox::information(this,"Declensions",
                                        "Masculine \n"
                                        "Nominative: "+words->word[words->getrl()][1]+"\n"
                                        "Genetive: " +words->word[words->getrl()][2]+"\n"
                                        "Dative: " +words->word[words->getrl()][3]+"\n"
                                        "Accusative animate: " +words->word[words->getrl()][4]+"\n"
                                        "Accusative inanimate: " +words->word[words->getrl()][5]+"\n"
                                        "Instrumental: " +words->word[words->getrl()][6]+"\n"
                                        "Prepositional: " +words->word[words->getrl()][7]+"\n"
            "Neuter \n"
            "Nominative: "+words->word[words->getrl()][8]+"\n"
            "Genetive: " +words->word[words->getrl()][9]+"\n"
            "Dative: " +words->word[words->getrl()][10]+"\n"
            "Accusative: " +words->word[words->getrl()][11]+"\n"
            "Instrumental: " +words->word[words->getrl()][12]+"\n"
            "Prepositional: " +words->word[words->getrl()][13]+"\n"
            "Feminine \n"
            "Nominative: "+words->word[words->getrl()][14]+"\n"
            "Genetive: " +words->word[words->getrl()][15]+"\n"
            "Dative: " +words->word[words->getrl()][16]+"\n"
            "Accusative: " +words->word[words->getrl()][17]+"\n"
            "Instrumental: " +words->word[words->getrl()][18]+"\n"
            "Prepositional: " +words->word[words->getrl()][19]+"\n"
                                                               "Plural \n"
                                                               "Nominative: "+words->word[words->getrl()][20]+"\n"
                                                               "Genetive: " +words->word[words->getrl()][21]+"\n"
                                                               "Dative: " +words->word[words->getrl()][22]+"\n"
                                                               "Accusative animate: " +words->word[words->getrl()][23]+"\n"
                                                               "Accusative inanimate: " +words->word[words->getrl()][24]+"\n"
                                                               "Instrumental: " +words->word[words->getrl()][25]+"\n"
                                                               "Prepositional: " +words->word[words->getrl()][26]+"\n");

}

void RusAdjDialog::on_GoldSheet_clicked()
{
    QMessageBox Gold(this);
    Gold.setText("Gold Sheet");
    QPixmap sheet(":/new/babelpic/goldsheet.png",0,Qt::MonoOnly);
    sheet.scaled(200,150);
    Gold.setIconPixmap(sheet);
    Gold.exec();
}
