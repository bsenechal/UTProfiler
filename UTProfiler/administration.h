/**
  *\file administration.h
  *
  */

#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include <QFrame>
#include "dbmanager.h"
#include "formulaire.h"
#include <QListWidget>
#include "utprofilerexception.h"
#include "cursus.h"
#include "branches.h"
#include "filieres.h"
#include "categorie.h"
#include "disponibilites.h"
#include "etudiants.h"
#include "utprofilerexception.h"
#include <QMessageBox>
#include "tools.h"

namespace Ui {
class Administration;
}

class Administration : public QFrame
{
    Q_OBJECT

public:
    explicit Administration(QWidget *parent = 0);
    ~Administration();

private:
    Ui::Administration *ui;
    dbmanager *db;
    QStringList uvs;
    Cursus* cursus;
    Filieres *filieres;
    Branches *branches;
    Disponibilites *dispo;
    Etudiants *etudiants;
    Categorie *categories;
    QMessageBox msgBox;
    /**
     * \fn remove_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget  *liste_credits)
     * \param QListWidget *liste1
     * \param QListWidget *liste2
     * \param QListWidget *liste_credits
     * \param QString const nb_credits
     * \brief Supprime l'item selectionné de liste1 et l'ajoute dans la liste2. Cette fonction supprime également le nombre de crédit correspondant à l'index selectionné de la liste1 dans la liste_credits
     * \return void
     */
    void remove_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget *liste_credits);

    /**
     * \fn Administration::add_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget *liste_credits, QString const nb_credits)
     * \param QListWidget *liste1
     * \param QListWidget *liste2
     * \param QListWidget *liste_credits
     * \param QString const nb_credits
     * \brief Ajoute l'item selectionné de liste1 à la fin de liste2 tout en le retirant de liste1. Cette fonction ajoute également le nombre de crédits nb_credits à la fin de la liste liste_credits
     * \return void
     */
    void add_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget *liste_credits, QString const nb_credits);

private slots:
    void modif_ajout_dispo_uv();
    void modif_retire_dispo_uv();
    void modif_ajout_branche_uv();
    void modif_retire_branche_uv();
    void modif_ajout_filiere_uv();
    void modif_retire_filiere_uv();
    void modif_retire_categorie_uv();
    void modif_ajout_categorie_uv();

    /* Gestion des uv */
    void sauvegarde_ajout_uv();
    void sauvegarde_modif_uv();
    void modifier_uv();
    void ajout_categorie_uv();
    void retire_categorie_uv();
    void ajout_filiere_uv();
    void retire_filiere_uv();
    void ajout_branche_uv();
    void retire_branche_uv();
    void ajout_dispo_uv();
    void retire_dispo_uv();
    void maj_uv();
    void supprimer_uv();

    /* Gestion des utilisateurs */
    void sauvegarder_role();
    void retire_administrateur();
    void ajout_administrateur();
    void maj_role();

    /* Gestion des filieres */
    void sauvegarde_ajout_filiere();
    void sauvegarde_modif_filiere();
    void modifier_filiere();
    void supprimer_filiere();   
    void ajout_branche_filiere();
    void retire_branche_filiere();
    void modif_ajout_branche_filiere();
    void modif_retire_branche_filiere();
    void maj_filiere();

    /* Gestion des disponibilités */
    void sauvegarde_ajout_dispo();
    void sauvegarde_modif_dispo();
    void modifier_dispo();
    void supprimer_dispo();
    void maj_dispo();

    /* Gestion des branches */
    void sauvegarde_ajout_branche();
    void sauvegarde_modif_branche();
    void modifier_branche();
    void supprimer_branche();
    void maj_branche();

    /* Gestion des cursus */
    void sauvegarde_ajout_cursus();
    void sauvegarde_modif_cursus();
    void modifier_cursus();
    void supprimer_cursus();
    void maj_admin();
    void maj_cursus();

    /* Gestion des étudiants */
    void sauvegarder_ajout_etudiant();
    void supprimer_etudiant();
    void sauvegarder_modif_etudiant();
    void maj_etudiant();
    void modifier_etudiant();
};

#endif // ADMINISTRATION_H
