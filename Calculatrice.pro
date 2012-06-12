#-------------------------------------------------
#
# Project created by QtCreator 2012-05-09T17:38:46
#
#-------------------------------------------------

QT       += core gui
QT += xml
TARGET = Calculatrice
TEMPLATE = app


SOURCES += main.cpp\
        calculatrice.cpp \
    pile.cpp \
    constante.cpp \
    commande.cpp \
    ecrituredom.cpp \
    xml_dom.cpp

HEADERS  += calculatrice.h \
    pile.h \
    constante.h \
    commande.h \
    ecrituredom.h \
    xml_dom.h

FORMS    += calculatrice.ui
