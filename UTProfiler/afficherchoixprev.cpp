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

void afficherchoixprev::ajoutprev(Mapsugg_UV mapsuggestion) {
//On parcour notre map

    std::map<int, std::map<QString, QString> > ::iterator p;
    for(p = mapsuggestion.begin(); p != mapsuggestion.end(); p++)
    {
        qDebug()<<"Semestre "<<p->first;
        std::map<QString, QString>::iterator r;
        for(r = p->second.begin(); r != p->second.end(); r++){
            qDebug()<<"uv "<<r->first;

        QString uv=r->first;
        QString type=r->second;

        qDebug()<<p->first;
                switch (p->first)
                {
                    case 1: {
                          ui->uv_1->addItem(uv+" as "+type);
                          break;
                    }
                    case 2:
                   {
                          ui->uv_2->addItem(uv+" as "+type);
                          break;
                    }
                    case 3:
                   {
                          ui->uv_3->addItem(uv+" as "+type);
                          break;
                    }
                    case 4:
                    {
                         ui->uv_4->addItem(uv+" as "+type);
                         break;
                    }
                    case 5:
                   {
                         ui->uv_5->addItem(uv+" as "+type);
                         break;
                   }
                    case 6:
                   {
                         ui->uv_6->addItem(uv+" as "+type);
                   }
                    case 7:
                   {
                         ui->uv_7->addItem(uv+" as "+type);
                         break;
                   }
                    case 8:
                   {
                         ui->uv_8->addItem(uv+" as "+type);
                         break;
                   }
               }

        }
    }
}