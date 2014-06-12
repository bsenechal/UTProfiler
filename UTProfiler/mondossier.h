#ifndef MONDOSSIER_H
#define MONDOSSIER_H

#include <QDialog>
#include "connexion.h"
#include "dbmanager.h"
#include "filieres.h"
#include "cursus.h"
#include "branches.h"
#include "semestre.h"
#include "uvmnger.h"
#include "tools.h"
#include <QMessageBox>
#include <QPair>
#include "afficherchoixprev.h"

namespace Ui {
class mondossier;
}

class mondossier : public QDialog
{
    Q_OBJECT

public:
    explicit mondossier(QWidget *parent = 0);
    ~mondossier();
    void remplirchoix();
    void rempliruvsuivies();
    void initdossier();

private:
    QString numerodossier="0";
    Ui::mondossier *ui;
    Connexion *c;
    dbmanager *db;
    Branches *branches;
    Filieres *filieres;
    Cursus *cursus;
    Semestre *semestres;
    uvmnger *uvm;
    afficherchoixprev choixprev;

    void remplirlistesolutions();

    map<QString,QString> map_pos_uv;
    map<QString, map<QString, QString> > uvsuivies;

    typedef std::map<QString, std::pair<int, QString> > Mapalgo;
    Mapalgo map_algo;

    typedef std::map<QString, std::pair<QString, int> > Mapcred;
    Mapcred map_credits;

    typedef std::map<int, std::map<QString, std::pair<int, int> > > Mapsugg_nbtype2;
    Mapsugg_nbtype2 map_suggestion_nb2;
    //[Semestre][Cate]  : first= nbUV   second=nbcredits

    typedef std::map<int, std::map<QString, QString> > Mapsugg_UV;
    Mapsugg_UV map_suggestion_uv;

    typedef std::map<int, std::map<QString, std::pair<QString, int> > > Mapsugg_UV2;
    //[S1]["LO21"].first=categ [S1]["LO21"].second=nbcredit
    Mapsugg_UV2 map_suggestion_uv2;

    typedef struct   {
         QString categorie;
         int credit;
         int obligation;
        }detailuv;
    typedef std::map<QString, detailuv > Map_of_Uv;
    Map_of_Uv map_all_uv;

private slots:
    void ajoutUV();
    void sauvegarder_choix();
    void ajoutPreference();
    void ajoutRejet();
    void ajoutExigence();
    void supprPreference();
    void supprRejet();
    void supprExigence();
    void sauvegarder_modif();
    void modifier_infos();
    void enable_branche();
    void enable_credits();
    void add_critere_branche();
    void add_critere_filiere();
    void add_critere_cursus();
    void sauvegarder_dossier();
    void suppr_UV_suivies();
    void generer_suggestion();

public slots :
    void maj_dossier();
};



#endif // MONDOSSIER_H
