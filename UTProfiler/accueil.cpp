/**
 *\file accueil.cpp
*/

#include "accueil.h"
#include "ui_accueil.h"


/**
 * \fn Accueil::Accueil(QWidget *parent)
 * \param QWidget *parent
 * \brief Constructeur de la classe Accueil
 */

Accueil::Accueil(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Accueil)
{  
    ui->setupUi(this);

    c = Connexion::getInstance();
    db = dbmanager::getInstance();
    cursus = Cursus::getInstance();

    /*! Création d'un nouvel onglet dans le tabWidget pour chaque cursus.
      * Chaque onglet est composé d'un Groupbox pour la selection des critères de tri et d'un listWidget pour l'affichage des UV
      */
    for (QStringList::iterator it=cursus->getListe_cursus().begin(); it!=cursus->getListe_cursus().end(); ++it) {
        QWidget *tmp = new QWidget();
        QVBoxLayout *VLayout = new QVBoxLayout;
        QVBoxLayout *VLayout_group = new QVBoxLayout;
        QHBoxLayout *couche1_critere = new QHBoxLayout;
        QHBoxLayout *couche2_critere = new QHBoxLayout;
        QGroupBox *group = new QGroupBox;
        group->setTitle("Critères de recherche :");
        boutons[*it] = new QPushButton("Rechercher");
        couche2_critere->addWidget(boutons[*it]);
        branches = db->getColonne("SELECT nom FROM branche WHERE nom_cursus = '" + *it +"';");
        VLayout->addWidget(group);

        for (QStringList::iterator it_branche=branches.begin(); it_branche!=branches.end(); ++it_branche) {
            QCheckBox *cb = new QCheckBox (*it_branche);
            cbox[*it][*it_branche] = cb;
            couche1_critere->addWidget(cb);
        }

        VLayout_group->addLayout(couche1_critere);
        VLayout_group->addLayout(couche2_critere);
        group->setLayout(VLayout_group);

        liste[*it] = new QListWidget;
        VLayout->addWidget(liste[*it]);

        QObject::connect(boutons[*it], SIGNAL(clicked()), this, SLOT(affiche_uv()));
        tmp->setLayout(VLayout);
        ui->tabWidget->addTab(tmp, *it);
    }

    QObject::connect(ui->connexion, SIGNAL(clicked()), this, SLOT(connexionUser()));
    QObject::connect(ui->inscription, SIGNAL(clicked()), this, SLOT(inscriptionUser()));
}


/**
 * \fn Accueil::~Accueil()
 * \brief Destructeur de la classe Accueil
 *
*/

Accueil::~Accueil()
{
    delete ui;
}


/**
 * \fn void Accueil::affiche_uv()
 * \brief Affiche les UV selon le cursus et les branches selectionnées
 * \return void
 */

void Accueil::affiche_uv() {
    QSqlQuery query;
    QString nom_cursus = cursus->getListe_cursus()[ui->tabWidget->currentIndex()-1];
    QString res;
    liste[nom_cursus]->clear();

    for (QMap<QString, QCheckBox*>::iterator it=cbox[nom_cursus].begin(); it!=cbox[nom_cursus].end(); ++it){
        if (it.value()->isChecked())
            res.append("'" + it.key() + "',");
    }

   query = db->execute("SELECT u.code, u.description, b.nom FROM UV u, branche b, assoc_branche_uv a WHERE a.code_uv = u.code AND a.nom_branche = b.nom AND b.nom IN (" + res.left(res.size()-1) + ");");
qDebug()<<"voici le contenu de IN : " << res.left(res.size()-1);

   while (query.next()){
       QStringList dispo = db->getColonne("SELECT nom_disponibilite FROM assoc_disponibilite_uv WHERE code_uv  = '" + query.value(0).toString() + "';");
       QString d;
       for (QStringList::iterator it = dispo.begin() ; it != dispo.end() ; ++it)
           d.append(*it + " & ");

       liste[nom_cursus]->addItem(query.value(0).toString() + "    -    "  + query.value(1).toString() + "    -    " + query.value(2).toString() + "    - Disponible en : " + d.left(d.size()-3));
   }
}

void Accueil::connexionUser() {
        QSqlQuery query;

        QString res = c->connexion(ui->input_login->text(), ui->input_mdp->text());

        if (res != "ok") {
            ui->label_erreur->setText(res);
        }
        else {
            query = db->execute("SELECT admin FROM Etudiant WHERE nom = '" + c->getNom() + "';");


            if (query.next()) {
                if (query.value(0).toString() == "true") {
                    admin.show();
                    dossier.show();
                }
                else
                    dossier.exec();


            }

        }
}


void Accueil::inscriptionUser() {
    Inscription i;
    i.exec();
}
