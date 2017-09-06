#include "wordarray.h"

wordArray::wordArray (QString filename)
{
    tot=0;
    rl=0;
    rc=0;
    QFile file(filename);

    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
            stream >> l >> c;
            word = new QString*[l];

        for (int i=0; i<l; i++)
         {

            word[i] = new QString[c];

            for (int j=0; j<c; j++)
            {
                stream >> word[i][j];
            }
         }
    }
    file.close();
    srand(time(NULL));
}

wordArray::wordArray()
{
    word = new QString*;
    word[0][0][0] = 0;
    l=0;
    c=0;
    rl=0;
    rc=0;

}

wordArray::~wordArray()
{
 delete [] word;
}

void wordArray::setrandomnoun()
{
    // this makes rc and rl random.
    int j=c-2; //define j to represent the index of the column
    rc = rand () % j + 2; //specifically so that the first two words in each line are not tested

    rl = rand () % l ;
}

void wordArray::setrandomadj()
{
    // this makes rc and rl random.
    int j=c-2; //define j to represent the index of the column
    rc = rand () % j + 2; //specifically so that the first two words in each line are not tested

    rl = rand () % l ;
}

QString wordArray::adjCase()
{
    QString h;

    if (rc==8 or rc==14 or rc==20)
        h="Nominative";
    if (rc==2 or rc==9 or rc==15 or rc==21)
        h="Genitive";
    if (rc==3 or rc==10 or rc==16 or rc==22)
        h="Dative";
    if (rc==4 or rc==5 or rc==11 or rc==17 or rc==23 or rc==24)
        h="Accusative";
    if (rc==6 or rc==12 or rc==18 or rc==25)
        h="Instrumental";
    if (rc==7 or rc==13 or rc==19 or rc==26)
        h="Prepositional";
    return h;
}
QString wordArray::pronoun()
{
    QString h;
    if (rc==2)
        h="я";
    if (rc==3)
        h="ты";
    if (rc==4)
        h="он/она/оно";
    if (rc==5)
        h="мы";
    if (rc==6)
        h="вы";
    if (rc==7)
        h="они";
    if (rc==8)
        h="ты (imperaative mood)";
    if (rc==9)
        h="вы (imperative mood)";
    if (rc==10)
        h="он (past tense)";
    if (rc==11)
        h="она (past tense)";
    if (rc==12)
        h="оно (past tense)";
    if (rc==13)
        h="они (past tense)";

    return h;
}

QString wordArray::adjGender()
{
    QString h;
    if (rc>=2 & rc<=7)
        h="Masculine";
    if (rc>=8 & rc<=13)
        h="Neuter";
    if (rc>=14 & rc<=19)
        h="Feminine";
    if (rc>=20 & rc<=26)
        h="Plural";

   return h;
}


QString wordArray::Case ()
{
    QString h;

    if (rc==2)
        h="Genitive";
    if (rc==3)
        h="Dative";
    if (rc==4)
        h="Accusative";
    if (rc==5)
        h="Instrumental";
    if (rc==6)
        h="Prepositional";
    return h;
}

QString wordArray::transl()
{
    return word[rl][0];
}

QString wordArray::verify(QString x) //verifies whether or not a typed word is correct. x, in this case, is the word typed.
{
    correct = true;
    QString b;
    b="The correct answer is: "+word[rl][rc];
    if (x==0)
    {
        correct=false;
    }

    if (x!=word[rl][rc])
    {
        correct=false;
    }
    return b;
}
