#include "afficherchoixprev.h"
#include "ui_afficherchoixprev.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QGroupBox>


afficherchoixprev::afficherchoixprev(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::afficherchoixprev)
{
    ui->setupUi(this);
    this->setWindowTitle("UTProfiler : Génération de choix d'UV");
    db = dbmanager::getInstance();
    btn_sauvegarder = new QPushButton("Sauvegarder");
    QObject::connect(btn_sauvegarder, SIGNAL(clicked()), this, SLOT(sauvegarde_solutions()));
}

afficherchoixprev::~afficherchoixprev()
{
    delete ui;
}

void afficherchoixprev::ajoutprev(Mapsugg_UV2 mapsuggestion) {
//map_suggestion_nb [semestre][Categorie] first=nbUv  second=credits
//On parcour notre map
    int cred_cs = 0;
    int cred_tm = 0;
    int cred_tsh = 0;
    int cred_tot = 0;
    QHBoxLayout *layout = new QHBoxLayout;
    QHBoxLayout *layout_sauvegarder = new QHBoxLayout;
    QVBoxLayout *colonne = new QVBoxLayout;
    QHBoxLayout *l = new QHBoxLayout;
    QGroupBox *group = new QGroupBox;
    colonne->addWidget(new QLabel (""));
    colonne->addWidget(new QLabel (""));
    colonne->addSpacerItem(new QSpacerItem(50,202));
    colonne->addWidget(new QLabel ("Total CS"));
    colonne->addWidget(new QLabel ("Total TM"));
    colonne->addWidget(new QLabel ("Total TSH"));
    colonne->addWidget(new QLabel ("Total "));

    layout->addLayout(colonne);
    group->setLayout(layout);
    l->addWidget(group);
    Mapsugg_UV2 ::iterator p;

    for(p = mapsuggestion.begin(); p != mapsuggestion.end(); p++)
    {
        QString sem = QString::number(p->first);
        group = new QGroupBox;
        group->setTitle("Semestre n°" + sem);
        layout = new QHBoxLayout;
        int total_cs = 0;
        int total_tm = 0;
        int total_credits = 0;
        int total_tsh = 0;


        QVBoxLayout *colonne1 = new QVBoxLayout;
        QVBoxLayout *colonne2 = new QVBoxLayout;
        QVBoxLayout *colonne3 = new QVBoxLayout;

        colonne1->addWidget(new QLabel ("UV"));
        colonne2->addWidget(new QLabel ("Categorie"));
        colonne3->addWidget(new QLabel ("Credits"));

        map_liste[sem].uv = new QListWidget;
        map_liste[sem].categorie = new QListWidget;
        map_liste[sem].credits = new QListWidget;

        map_liste[sem].uv->setMaximumHeight(200);
        map_liste[sem].categorie->setMaximumHeight(200);
        map_liste[sem].credits->setMaximumHeight(200);
        map_liste[sem].uv->setMaximumWidth(60);
        map_liste[sem].categorie->setMaximumWidth(60);
        map_liste[sem].credits->setMaximumWidth(30);

        colonne1->addWidget(map_liste[sem].uv);
        colonne2->addWidget(map_liste[sem].categorie);
        colonne3->addWidget(map_liste[sem].credits);

        std::map<QString, std::pair<QString, int> >::iterator r;
        for(r = p->second.begin(); r != p->second.end(); r++){
            QString uv=r->first;
            QString type=r->second.first;
            QString nbcd=QString::number(r->second.second);

            map_liste[sem].uv->addItem(uv);
            map_liste[sem].credits->addItem(nbcd);
            map_liste[sem].categorie->addItem(type);

            if (type == "CS") { total_cs += r->second.second; cred_cs += r->second.second; }

            else if (type == "TM") { total_tm += r->second.second; cred_tm  += r->second.second; }

            else if (type == "TSH") { total_tsh += r->second.second; cred_tsh += r->second.second; }

            cred_tot += r->second.second;
            total_credits += r->second.second;
        }

        colonne1->addWidget(new QLabel (QString::number(total_cs)));
        colonne1->addWidget(new QLabel (QString::number(total_tm)));
        colonne1->addWidget(new QLabel (QString::number(total_tsh)));
        colonne1->addWidget(new QLabel (QString::number(total_credits)));

        for (unsigned int i = 0; i < 4 ; i++){
            colonne2->addWidget(new QLabel (""));
            colonne3->addWidget(new QLabel (""));
        }

        layout->addLayout(colonne1);
        layout->addLayout(colonne2);
        layout->addLayout(colonne3);

        group->setLayout(layout);
        l->addWidget(group);
  }
    group = new QGroupBox;
    colonne = new QVBoxLayout;
    layout = new QHBoxLayout;
    colonne->addWidget(new QLabel (""));
    colonne->addWidget(new QLabel (""));
    colonne->addSpacerItem(new QSpacerItem(50,82));
    colonne->addWidget(btn_sauvegarder);
    colonne->addSpacerItem(new QSpacerItem(50,82));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_cs)));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_tm)));
    colonne->addWidget(new QLabel ("Total :" + QString::number(cred_tsh)));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_tot)));

    layout->addLayout(colonne);
    group->setLayout(layout);
    l->addWidget(group);

    this->setLayout(l);
}








void afficherchoixprev::sauvegarde_solutions(){
    QString id_dossier;
    QString id_solution;
    Connexion *c = Connexion::getInstance();

    QSqlQuery query;
    query = db->execute("SELECT id_dossier FROM Dossier WHERE login_etudiant='" + c->getLogin() + "';");
    if(query.next()) {
        id_dossier=query.value(0).toString();
    }


    try {
        query = db->execute("SELECT MAX(id_solution)+1 From assoc_solution_dossier WHERE id_dossier="+id_dossier+" ");

        if (query.next()){
            id_solution = query.value(0).toString();
        }
        if (id_solution=="") id_solution="0";


        db->execute("INSERT INTO assoc_solution_dossier(id_solution, id_dossier) VALUES("+id_solution+", "+id_dossier+");");

        db->execute("BEGIN;");
        int cpt_sem=0;
        for (auto it = map_liste.begin(); it !=map_liste.end(); ++it) {
            cpt_sem++;
            QString mycpt=QString::number(cpt_sem);
            for (int i = 0 ; i < it->second.uv->count(); i++) {
                db->execute("INSERT INTO solution_semestre(num_semestre, uv, categorie, credits, id_solution) VALUES ("+ mycpt +",'"+ it->second.uv->item(i)->text() + "','" + it->second.categorie->item(i)->text() + "'," + it->second.credits->item(i)->text() + ", "+id_solution+");");
            }
        }
        db->execute("COMMIT;");

        QMessageBox msgBox;
        msgBox.setText("Vous avez bien sauvegardé ce choix !");
        msgBox.exec();
    }
    catch (UTProfilerException u) {
            QMessageBox msgBox;
            db->execute("ROLLBACK");
            msgBox.setText(u.getInfo());
            msgBox.exec();
   }
}


void afficherchoixprev::afficherfrombase(QString solution) {
//map_suggestion_nb [semestre][Categorie] first=nbUv  second=credits
//On parcour notre map
    int cred_cs = 0;
    int cred_tm = 0;
    int cred_tsh = 0;
    int cred_tot = 0;
    QHBoxLayout *layout = new QHBoxLayout;
    QVBoxLayout *colonne = new QVBoxLayout;
    QHBoxLayout *l = new QHBoxLayout;
    QGroupBox *group = new QGroupBox;
    colonne->addWidget(new QLabel (""));
    colonne->addWidget(new QLabel (""));
    colonne->addSpacerItem(new QSpacerItem(50,202));
    colonne->addWidget(new QLabel ("Total CS"));
    colonne->addWidget(new QLabel ("Total TM"));
    colonne->addWidget(new QLabel ("Total TSH"));
    colonne->addWidget(new QLabel ("Total "));

    layout->addLayout(colonne);
    group->setLayout(layout);
    l->addWidget(group);


    QSqlQuery query;
    query = db->execute("select distinct num_semestre from solution_semestre where id_solution="+solution+"");

    while (query.next()) {
        QString sem = query.value(0).toString();
        group = new QGroupBox;
        group->setTitle("Semestre n°" + sem);
        layout = new QHBoxLayout;
        int total_cs = 0;
        int total_tm = 0;
        int total_credits = 0;
        int total_tsh = 0;



        QVBoxLayout *colonne1 = new QVBoxLayout;
        QVBoxLayout *colonne2 = new QVBoxLayout;
        QVBoxLayout *colonne3 = new QVBoxLayout;

        colonne1->addWidget(new QLabel ("UV"));
        colonne2->addWidget(new QLabel ("Categorie"));
        colonne3->addWidget(new QLabel ("Credits"));

        map_liste[sem].uv = new QListWidget;
        map_liste[sem].categorie = new QListWidget;
        map_liste[sem].credits = new QListWidget;

        map_liste[sem].uv->setMaximumWidth(50);
        map_liste[sem].categorie->setMaximumWidth(50);
        map_liste[sem].credits->setMaximumWidth(30);

        colonne1->addWidget(map_liste[sem].uv);
        colonne2->addWidget(map_liste[sem].categorie);
        colonne3->addWidget(map_liste[sem].credits);

        QSqlQuery query2;
        query2 = db->execute("select uv, categorie, credits from solution_semestre where id_solution="+solution+" AND num_semestre="+sem+";");
        while (query2.next()){
            QString uv=query2.value(0).toString();
            QString type=query2.value(1).toString();
            QString nbcd=query2.value(2).toString();

            map_liste[sem].uv->addItem(uv);
            map_liste[sem].credits->addItem(nbcd);
            map_liste[sem].categorie->addItem(type);

            if (type == "CS") { total_cs += nbcd.toInt(); cred_cs += nbcd.toInt(); }

            else if (type == "TM") { total_tm += nbcd.toInt(); cred_tm += nbcd.toInt(); }

            else if (type == "TSH") { total_tsh += nbcd.toInt(); cred_tsh += nbcd.toInt(); }

            cred_tot += nbcd.toInt();
            total_credits += nbcd.toInt();
        }

        colonne1->addWidget(new QLabel (QString::number(total_cs)));
        colonne1->addWidget(new QLabel (QString::number(total_tm)));
        colonne1->addWidget(new QLabel (QString::number(total_tsh)));
        colonne1->addWidget(new QLabel (QString::number(total_credits)));

        for (unsigned int i = 0; i < 4 ; i++){
            colonne2->addWidget(new QLabel (""));
            colonne3->addWidget(new QLabel (""));
        }
        layout->addLayout(colonne1);
        layout->addLayout(colonne2);
        layout->addLayout(colonne3);

        group->setLayout(layout);
        l->addWidget(group);
  }

    group = new QGroupBox;
    colonne = new QVBoxLayout;
    layout = new QHBoxLayout;
    colonne->addWidget(new QLabel (""));
    colonne->addWidget(new QLabel (""));
    colonne->addSpacerItem(new QSpacerItem(50,200));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_cs)));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_tm)));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_tsh)));
    colonne->addWidget(new QLabel ("Total : " + QString::number(cred_tot)));


    layout->addLayout(colonne);
    group->setLayout(layout);
    l->addWidget(group);

    this->setLayout(l);
}
