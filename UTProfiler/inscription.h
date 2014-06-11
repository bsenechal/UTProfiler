#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QDialog>
#include "dbmanager.h"
#include "formulaire.h"
#include "connexion.h"
#include "mondossier.h"
#include "utprofilerexception.h"

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
    Ui::Inscription *ui;

public slots :
    void inscriptionUser();
};

#endif // INSCRIPTION_H
