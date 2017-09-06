#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T14:18:36
#
#-------------------------------------------------

QT       += core gui

CONFIG += c++11

# LIBS += -L/path/to -lpsapi

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tab
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    chapter1dialog.cpp \
    chpt2dialog.cpp \
    chpt3dialog.cpp \
    chpt4dialog.cpp \
    chpt5dialog.cpp \
    rusverbdialog.cpp \
    rusnoundialog.cpp \
    rusadjdialog.cpp \
    wordarray.cpp \
    jpchpt1test.cpp \
    arvocabdialog.cpp \
    arvostudy.cpp \
    arconjdialog.cpp


HEADERS  += mainwindow.h \
    chapter1dialog.h \
    chpt2dialog.h \
    chpt3dialog.h \
    chpt4dialog.h \
    chpt5dialog.h \
    rusverbdialog.h \
    rusnoundialog.h \
    rusadjdialog.h \
    wordarray.h \
    jpchpt1test.h \
    arconjdialog.h \
    arvocabdialog.h \
    arvostudy.h

FORMS    += mainwindow.ui \
    chapter1dialog.ui \
    chpt2dialog.ui \
    chpt3dialog.ui \
    chpt4dialog.ui \
    chpt5dialog.ui \
    rusverbdialog.ui \
    rusnoundialog.ui \
    rusadjdialog.ui \
    jpchpt1test.ui \
    arvocabdialog.ui \
    arvostudy.ui \
    arconjdialog.ui


RESOURCES += \
    BabelResources.qrc \

DISTFILES += \
    blah.txt

