/**
 *@file accueil.cpp
*/

#include "accueil.h"
#include "ui_accueil.h"


/**
 * @fn Accueil::Accueil(QWidget *parent)
 * @param QWidget *parent
 * @brief Constructeur de la classe Accueil. Il génére également les onglets permettant la consulation d'UV par cursus
 */

Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{  
    ui->setupUi(this);
    this->setWindowTitle("UTProfiler");
    c = Connexion::getInstance();
    db = dbmanager::getInstance();
    cursus = Cursus::getInstance();
    dispos = Disponibilites::getInstance();

    for (QStringList::iterator it=cursus->getListe_cursus().begin(); it!=cursus->getListe_cursus().end(); ++it) {
        QWidget *tmp = new QWidget();
        QVBoxLayout *VLayout = new QVBoxLayout;
        QVBoxLayout *VLayout_group = new QVBoxLayout;
        QHBoxLayout *couche1_critere = new QHBoxLayout;
        QHBoxLayout *couche2_critere = new QHBoxLayout;
        QHBoxLayout *couche3_critere = new QHBoxLayout;
        QHBoxLayout *couche4_critere = new QHBoxLayout;
        QHBoxLayout *couche5_critere = new QHBoxLayout;
        QGroupBox *group = new QGroupBox;
        group->setTitle("Critères de recherche :");
        boutons[*it] = new QPushButton("Rechercher");
        couche1_critere->addWidget(new QLabel("Branches :"));
        couche3_critere->addWidget(new QLabel("Disponibilités :"));
        couche5_critere->addWidget(boutons[*it]);
        branches = db->getColonne("SELECT nom FROM branche WHERE nom_cursus = '" + *it +"';");
        VLayout->addWidget(group);

        for (QStringList::iterator it_branche=branches.begin(); it_branche!=branches.end(); ++it_branche) {
            QCheckBox *cb = new QCheckBox (*it_branche);
            cbox[*it]["branches"][*it_branche] = cb;
            couche2_critere->addWidget(cb);
        }
        if (!cbox[*it]["branches"].isEmpty())
                VLayout_group->addLayout(couche1_critere);

        for (QStringList::iterator it_dispos = dispos->getListe_dispos().begin() ; it_dispos != dispos->getListe_dispos().end() ; ++it_dispos){
            QCheckBox *cb = new QCheckBox (*it_dispos);
            cbox[*it]["dispos"][*it_dispos] = cb;
            couche4_critere->addWidget(cb);
        }

        VLayout_group->addLayout(couche2_critere);
        VLayout_group->addLayout(couche3_critere);
        VLayout_group->addLayout(couche4_critere);
        VLayout_group->addLayout(couche5_critere);
        group->setLayout(VLayout_group);

        liste[*it] = new QListWidget;
        VLayout->addWidget(liste[*it]);

        QObject::connect(boutons[*it], SIGNAL(clicked()), this, SLOT(affiche_uv()));
        tmp->setLayout(VLayout);
        ui->tabWidget->addTab(tmp, *it);
    }

    QObject::connect(ui->connexion, SIGNAL(clicked()), this, SLOT(connexionUser()));
    QObject::connect(ui->input_mdp, SIGNAL(returnPressed()), this, SLOT(connexionUser()));
    QObject::connect(ui->inscription, SIGNAL(clicked()), this, SLOT(inscriptionUser()));
}


/**
 * @fn Accueil::~Accueil()
 * @brief Destructeur de la classe Accueil
 *
*/

Accueil::~Accueil()
{
    delete ui;
}


/**
 * @fn void Accueil::affiche_uv()
 * @brief Affiche les UV selon le cursus et les branches selectionnées
 * @return void
 */

void Accueil::affiche_uv() {
    QSqlQuery query;

    QString nom_cursus = cursus->getListe_cursus()[ui->tabWidget->currentIndex()-1];
    QString res, res2;
    liste[nom_cursus]->clear();

    for (auto it = cbox[nom_cursus]["branches"].begin(); it!= cbox[nom_cursus]["branches"].end(); ++it){
        if (it.value()->isChecked())
            res.append("'" + it.key() + "',");
    }

    for (auto it=cbox[nom_cursus]["dispos"].begin(); it!=cbox[nom_cursus]["dispos"].end(); ++it){
        if (it.value()->isChecked())
            res2.append("'" + it.key() + "',");
    }

    try {
        if (!res2.isNull() && !res.isNull())
            query = db->execute("SELECT DISTINCT u.code, u.description, a.nom_branche FROM UV u, assoc_branche_uv a, assoc_disponibilite_uv ad WHERE ad.code_uv = u.code AND ad.nom_disponibilite IN ("+ res2.left(res2.size()-1) +") AND a.code_uv = u.code AND a.nom_branche IN (" + res.left(res.size()-1) + ");");
        else if (res2.isNull() && !res.isNull())
            query = db->execute("SELECT DISTINCT u.code, u.description, a.nom_branche FROM UV u, assoc_branche_uv a WHERE a.code_uv = u.code AND a.nom_branche IN (" + res.left(res.size()-1) + ");");
        else if (!res2.isNull() && res.isNull())
            query = db->execute("SELECT DISTINCT u.code, u.description, a.nom_branche FROM UV u, assoc_branche_uv a, assoc_disponibilite_uv ad WHERE a.code_uv = u.code AND ad.code_uv = u.code AND ad.nom_disponibilite IN ("+ res2.left(res2.size()-1) +");");
        else
            query = db->execute("SELECT DISTINCT u.code, u.description, a.nom_branche FROM UV u, assoc_branche_uv a, branche b WHERE u.code=a.code_uv AND a.nom_branche = b.nom AND b.nom_cursus = '" + nom_cursus + "';");

   while (query.next()){
       QStringList dispo = db->getColonne("SELECT DISTINCT nom_disponibilite FROM assoc_disponibilite_uv WHERE code_uv  = '" + query.value(0).toString() + "';");
       QString d;
       for (QStringList::iterator it = dispo.begin() ; it != dispo.end() ; ++it)
           d.append(*it + " & ");

       liste[nom_cursus]->addItem(query.value(0).toString() + "    -    "  + query.value(1).toString() + "    -    " + query.value(2).toString() + "    - Disponible en : " + d.left(d.size()-3));
   }
    }
    catch (UTProfilerException u) {
        QMessageBox msgBox;
        msgBox.setText(u.getInfo());
        msgBox.exec();
    }
}

/**
 * @fn void Accueil::connexionUser()
 * @brief Permet la connexion d'un utilisateur
 * @return void
 */
void Accueil::connexionUser() {
        QSqlQuery query;


        QString res = c->connexion(ui->input_login->text(), ui->input_mdp->text());

        if (res != "ok") {
            ui->label_erreur->setText(res);
        }
        else {
            query = db->execute("SELECT admin FROM Etudiant WHERE nom = '" + c->getNom() + "';");


            if (query.next()) {
                dossier.maj_dossier();
                dossier.initdossier();
                if (query.value(0).toString() == "true") {
                    admin.show();
                    dossier.show();
                }
                else
                    dossier.exec();
            }

        }
}

/**
 * @fn void Accueil::inscriptionUser()
 * @brief Ouvre la fenêtre d'inscription
 * @return void
 */
void Accueil::inscriptionUser() {
    Inscription i;
    i.exec();
}
