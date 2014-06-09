#include "viewuv.h"
#include "ui_viewuv.h"
#include "dbmanager.h"
#include "utprofilerexception.h"
#include "formulaire.h"
#include <QLayout>
#include <QListWidget>
#include <QLabel>
#include <QDebug>
#include "fenetreplus.h"
#include <QPushButton>

ViewUv::ViewUv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewUv)
{
    {
        ui->setupUi(this);
        QSqlQuery query;

        ////////////TOUT MES UV POUR LA 1er FENETRE
        query.prepare("SELECT DISTINCT code, description FROM info_uv;");

        if (!query.exec()) {

                qDebug() << "Erreur de la BDD : "<< query.lastError();
        }
        else {
            while(query.next()){
                QString UV;
                UV = query.value(0).toString() + " - " + query.value(1).toString() + " - dispo en : " + query.value(2).toString();
                ui->allUv->addItem(UV);
            }
        }
      /////////FIN TOUT

/*
        QStringList cursus = db;
        QString moncursus;

        for (std::map<std::string, std::string>::iterator it=cursus.begin(); it!=cursus.end(); ++it) {
            moncursus = QString::fromStdString(it->first);
            QWidget *tmp = new QWidget();
            QVBoxLayout *VLayout = new QVBoxLayout;
            QLabel *lab = new QLabel;                           //Label marqué "liste des UV de, juste au dessus de la liste"
            QListWidget* listWidget = new QListWidget;          //Liste des UV (le tableau)
            QPushButton *derouler = new QPushButton;
            QString titre;

            fenetreplus *fenchoix= new fenetreplus(tmp);
            //fenchoix->show();

            titre = QString::fromStdString("Liste des UV de " + it->first);
            lab->setText(titre);
            derouler->setText("Derouler");

            VLayout->addWidget(derouler);
            VLayout->addWidget(fenchoix);
            VLayout->addWidget(lab);
            VLayout->addWidget(listWidget);

            query.prepare("SELECT * FROM info_uv WHERE nom_cursus=:cursus;");
            query.bindValue(":cursus", moncursus);

            if (!query.exec()) {

                    qDebug() << "Erreur de la BDD : "<< query.lastError();
            }
            else {
                while(query.next()){
                    QString UV;
                    UV = query.value(0).toString() + " - " + query.value(1).toString() + " - dispo en : " + query.value(2).toString();
                    listWidget->addItem(UV);
                }
            }


            tmp->setLayout(VLayout);
            ui->tabWidget->addTab(tmp, moncursus);

        }*/
    }
}

ViewUv::~ViewUv()
{
    delete ui;
}
