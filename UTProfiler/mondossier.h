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
#include "utprofilerexception.h"

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

private:
    QString numerodossier;
    Ui::mondossier *ui;
    Connexion *c;
    dbmanager *db;
    Branches *branches;
    Filieres *filieres;
    Cursus *cursus;
    Semestre *semestres;
    uvmnger *uvm;
    map<QString,QString> map_pos_uv;
    map<QString, map<QString, QString> > uvsuivies;


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
