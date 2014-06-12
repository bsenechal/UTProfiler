#include "afficherchoixprev.h"
#include "ui_afficherchoixprev.h"


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
ui->uv_1->clear();
ui->uv_2->clear();
ui->uv_3->clear();
ui->uv_4->clear();
ui->uv_5->clear();
ui->uv_6->clear();
ui->uv_7->clear();
ui->uv_8->clear();

    Mapsugg_UV2 ::iterator p;
    for(p = mapsuggestion.begin(); p != mapsuggestion.end(); p++)
    {
        //qDebug()<<"Semestre "<<p->first;
        std::map<QString, std::pair<QString, int> >::iterator r;
        for(r = p->second.begin(); r != p->second.end(); r++){
            //qDebug()<<"uv "<<r->first;

        QString uv=r->first;
        QString type=r->second.first;
        QString nbcd=QString::number(r->second.second);

        //qDebug()<<p->first;
                switch (p->first)
                {
                    case 1: {
                          ui->uv_1->addItem(uv+" as "+type+" cred : "+nbcd);
                          break;
                    }
                    case 2:
                   {
                          ui->uv_2->addItem(uv+" as "+type+" cred : "+nbcd);
                          break;
                    }
                    case 3:
                   {
                          ui->uv_3->addItem(uv+" as "+type+" cred : "+nbcd);
                          break;
                    }
                    case 4:
                    {
                         ui->uv_4->addItem(uv+" as "+type+" cred : "+nbcd);
                         break;
                    }
                    case 5:
                   {
                         ui->uv_5->addItem(uv+" as "+type+" cred : "+nbcd);
                         break;
                   }
                    case 6:
                   {
                         ui->uv_6->addItem(uv+" as "+type+" cred : "+nbcd);
                         break;
                   }
                    case 7:
                   {
                         ui->uv_7->addItem(uv+" as "+type+" cred : "+nbcd);
                         break;
                   }
                    case 8:
                   {
                         ui->uv_8->addItem(uv+" as "+type+" cred : "+nbcd);
                         break;
                   }
               }

        }
    }



}
