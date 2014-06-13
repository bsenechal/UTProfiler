#-------------------------------------------------
#
# Project created by QtCreator 2014-05-02T09:08:31
#
#-------------------------------------------------
QT       += core
QT       += core gui
QT       += sql # On rajoute SQL

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
#QMAKE_CXXFLAGS += -std=c++11

TARGET = UTProfiler
TEMPLATE = app


SOURCES += \
    main.cpp \
    dbmanager.cpp \
    accueil.cpp \
    mondossier.cpp \
    inscription.cpp \
    connexion.cpp \
    administration.cpp \
    cursus.cpp \
    branches.cpp \
    filieres.cpp \
    categorie.cpp \
    disponibilites.cpp \
    etudiants.cpp \
    semestre.cpp \
    uvmnger.cpp \
    tools.cpp \
    afficherchoixprev.cpp

HEADERS  += \
    dbmanager.h \
    utprofilerexception.h \
    connexion.h \
    accueil.h \
    mondossier.h \
    inscription.h \
    formulaire.h \
    singleton.h \
    administration.h \
    cursus.h \
    branches.h \
    filieres.h \
    categorie.h \
    disponibilites.h \
    etudiants.h \
    semestre.h \
    uvmnger.h \
    tools.h \
    afficherchoixprev.h

FORMS    += \
    accueil.ui \
    mondossier.ui \
    inscription.ui \
    administration.ui \
    afficherchoixprev.ui

OTHER_FILES += \
    UTProfiler

RESOURCES += \
    ../images/Utc.qrc
