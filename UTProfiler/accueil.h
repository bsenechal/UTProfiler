/**
 * \file accueil.h
 *
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
#include "utprofilerexception.h"
#include "formulaire.h"
#include "mondossier.h"
#include "cursus.h"
#include "administration.h"

/**
 *\file accueil.h
 *\brief Interface d'accueil de l'application
 *\class Fenêtre principal de l'appliacation. Elle permet de se connecter mais également de consulter la liste des UV en triant par cursus et par branche
*/

namespace Ui {
class Accueil;
}

class Accueil : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * \fn Accueil::Accueil(QWidget *parent)
     * \param QWidget *parent
     * \brief Constructeur de la classe Accueil
     */
    explicit Accueil(QWidget *parent = 0);
    /**
     * \fn Accueil::~Accueil()
     * \brief Destructeur de la classe Accueil
     *
    */
    ~Accueil();

private:
    Connexion *c;
    dbmanager *db;
    Cursus *cursus;
    QStringList branches;
    Administration admin;
    mondossier dossier;
    Ui::Accueil *ui;
    QMap<QString, QPushButton*> boutons;
    QMap<QString, QMap<QString, QCheckBox*> >cbox;
    QMap<QString, QListWidget*> liste;

private slots:
    /**
     * \fn Accueil::connexionUser()
     * \brief Permet la connexion d'un utilisateur
     * \return void
     */
    void connexionUser();
    /**
     * \fn Accueil::inscriptionUser()
     * \brief Lance le formulaire d'inscription
     * \return void
     */
    void inscriptionUser();
    /**
     * \fn void Accueil::affiche_uv()
     * \brief Affiche les UV selon le cursus et les branches selectionnées
     * \return void
     */
    void affiche_uv();

};
#endif // ACCUEIL_H
