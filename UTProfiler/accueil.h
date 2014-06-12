/**
  * @file accueil.h
  */

#ifndef ACCUEIL_H
#define ACCUEIL_H

#include <QLayout>
#include <QMainWindow>
#include <QListWidget>
#include <QCheckBox>
#include <QGroupBox>
#include <QPushButton>
#include <QMap>
#include "connexion.h"
#include "inscription.h"
#include "dbmanager.h"
#include "formulaire.h"
#include "mondossier.h"
#include "cursus.h"
#include "administration.h"
#include "semestre.h"

/**
 * @brief Interface d'accueil de l'application
 * @class Fenêtre principal de l'appliacation. Elle permet de se connecter mais également de consulter la liste des UV en triant par cursus et par branche
*/

namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:

    explicit Accueil(QWidget *parent = 0);
    ~Accueil();

private:
    Connexion *c;
    dbmanager *db;
    Cursus *cursus;
    QStringList branches;
    Administration admin;
    mondossier dossier;
    Disponibilites *dispos;
    Ui::Accueil *ui;
    QMap<QString, QPushButton*> boutons;
    QMap<QString, QMap<QString, QMap<QString, QCheckBox*> > >cbox;
    QMap<QString, QListWidget*> liste;

private slots:
    void connexionUser();
    void inscriptionUser();
    void affiche_uv();

};
#endif // ACCUEIL_H
