#-------------------------------------------------
#
# Project created by QtCreator 2014-05-02T09:08:31
#
#-------------------------------------------------
QT       += core
QT       += core gui
QT       += sql # On rajoute SQL
QT       -= gui # On enlève la GUI

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = UTProfiler
TEMPLATE = app


SOURCES += \
    main.cpp \
    dbmanager.cpp \
    uv.cpp \
    accueil.cpp \
    mondossier.cpp \
    inscription.cpp \
    viewuv.cpp \
    fenetreplus.cpp \
    detailuv.cpp \
    insertuv.cpp \
    connexion.cpp \
    administration.cpp \
    cursus.cpp \
    branches.cpp \
    filieres.cpp \
    categorie.cpp \
    disponibilites.cpp \
    etudiants.cpp \
    semestre.cpp \
    uvmnger.cpp

HEADERS  += \
    dbmanager.h \
    uv.h \
    utprofilerexception.h \
    connexion.h \
    accueil.h \
    mondossier.h \
    inscription.h \
    formulaire.h \
    singleton.h \
    viewuv.h \
    fenetreplus.h \
    detailuv.h \
    insertuv.h \
    administration.h \
    cursus.h \
    branches.h \
    filieres.h \
    categorie.h \
    disponibilites.h \
    etudiants.h \
    semestre.h \
    uvmnger.h

FORMS    += \
    accueil.ui \
    mondossier.ui \
    inscription.ui \
    viewuv.ui \
    fenetreplus.ui \
    detailuv.ui \
    insertuv.ui \
    administration.ui

OTHER_FILES += \
    UTProfiler

RESOURCES += \
    ../images/Utc.qrc
