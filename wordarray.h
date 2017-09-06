#ifndef WORDARRAY_H
#define WORDARRAY_H
#include <QtCore>
//#include <mytextstream.h>

class wordArray
{
    int l;      //lines in the array
    int c;      //columns in the aray
    int rl;     //random line in array
    int rc;     //random column in array
    public:
        QString ** word;
        int tot;    //total number answered in game
        int sc;     //total number correct in game
        bool correct;
        int getl() {return l;}
        int getrl() {return rl;}
        int getrc() {return rc;}
        void setrandomnoun();
        void setrandomadj();
        void setrandomverb();
        //wordArray(QString, int); //
        wordArray(QString); //constructs word array from given file with first line:   (int # of lines) _tab_ (int # of columns)
        wordArray(); //default constructor
        QString Case(); //used for russian. outputs case for given random word.
        QString adjCase(); //used for russian. outputs case for given random word.
        QString adjGender();
        QString pronoun();
        QString transl(); //gives english word or first word in array of given random word.
        QString verify(QString); //verifies that the typed word is correct.
        ~wordArray (); //deconstructor
};

#endif // WORDARRAY_H
