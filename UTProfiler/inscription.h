/**
  * @file inscription.h
  */

#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>
#include "dbmanager.h"
#include "formulaire.h"
#include "connexion.h"
#include "mondossier.h"
#include "cursus.h"
#include "filieres.h"
#include "branches.h"
#include "semestre.h"
#include "tools.h"

namespace Ui {
class Inscription;
}

class Inscription : public QDialog
{
    Q_OBJECT

public:
    explicit Inscription(QWidget *parent = 0);
    ~Inscription();


private:
    dbmanager *db;
    Connexion *c;
    Cursus *cursus;
    Branches *branches;
    Filieres *filieres;
    Semestre *semestres;
    Ui::Inscription *ui;

private slots :
    void inscriptionUser();
    void enable_branche();
    void enable_cursus();
};

#endif // INSCRIPTION_H
