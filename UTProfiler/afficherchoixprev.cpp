#include "afficherchoixprev.h"
#include "ui_afficherchoixprev.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>


afficherchoixprev::afficherchoixprev(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::afficherchoixprev)
{
    ui->setupUi(this);
}

afficherchoixprev::~afficherchoixprev()
{
    delete ui;
}

void afficherchoixprev::ajoutprev(Mapsugg_UV2 mapsuggestion) {
//map_suggestion_nb [semestre][Categorie] first=nbUv  second=credits
//On parcour notre map

    QHBoxLayout *layout = new QHBoxLayout;
    QHBoxLayout *layout_final = new QHBoxLayout;
    QVBoxLayout *colonne = new QVBoxLayout;
    QListWidget *l = new QListWidget;
    colonne->addWidget(new QLabel (""));
    colonne->addWidget(l);
    colonne->addWidget(new QLabel ("Total CS"));
    colonne->addWidget(new QLabel ("Total TM"));
    colonne->addWidget(new QLabel ("Total TSH"));
    colonne->addWidget(new QLabel ("Total "));

    layout->addLayout(colonne);
    Mapsugg_UV2 ::iterator p;
    for(p = mapsuggestion.begin(); p != mapsuggestion.end(); p++)
    {
        QString sem = QString::number(p->first);
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
        map_liste[sem].credits->setMaximumWidth(25);

        colonne1->addWidget(map_liste[sem].uv);
        colonne2->addWidget(map_liste[sem].categorie);
        colonne3->addWidget(map_liste[sem].credits);

        //qDebug()<<"Semestre "<<p->first;
        std::map<QString, std::pair<QString, int> >::iterator r;
        for(r = p->second.begin(); r != p->second.end(); r++){
            //qDebug()<<"uv "<<r->first;
            QString uv=r->first;
            QString type=r->second.first;
            QString nbcd=QString::number(r->second.second);

            map_liste[sem].uv->addItem(uv);
            map_liste[sem].credits->addItem(nbcd);
            map_liste[sem].categorie->addItem(type);

            if (type == "CS")
                total_cs += r->second.second;
            else if (type == "TM")
                total_tm += r->second.second;
            else if (type == "TSH")
                total_tsh += r->second.second;

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
    }

    this->setLayout(layout);
}
