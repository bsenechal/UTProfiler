#include "inscription.h"
#include "ui_inscription.h"
#include "dbmanager.h"
#include "formulaire.h"
#include "connexion.h"
#include "mondossier.h"


Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{

    ui->setupUi(this);
    QObject::connect(ui->valider, SIGNAL(clicked()), this, SLOT(inscriptionUser()));
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::inscriptionUser(){
    QSqlDatabase db = QSqlDatabase::database();
    QSqlQuery query(db);
    Connexion *c = Connexion::getInstance();
    ui->label_erreur->setText("");
    bool error = true;
    try {
        formulaire<QString>::verif_text(ui->input_login->text(), "login");
        formulaire<QString>::verif_text(ui->input_nom->text(), "nom");
        formulaire<QString>::verif_text(ui->input_prenom->text(), "prenom");
        formulaire<QString>::verif_pass(ui->input_mdp->text(), ui->input_mdp2->text());
        formulaire<QString>::verif_text(ui->input_email->text(), "email");
        error = false;
    }
    catch (FormulaireException e) {
        ui->label_erreur->setText(e.getinfo());
    }

    if (!error) {
        query.prepare("INSERT INTO Etudiant (login, passwd, nom, prenom, sexe, date_naissance, email) VALUES (:login, :passwd, :nom, :prenom, :sexe, :date_naiss, :email);");
        query.bindValue(":login", ui->input_login->text());
        query.bindValue(":passwd", ui->input_mdp->text());
        query.bindValue(":nom", ui->input_nom->text());
        query.bindValue(":prenom", ui->input_prenom->text());
        query.bindValue(":sexe", ui->comboBox->currentText());
        query.bindValue(":date_naiss", ui->input_date_naiss->text());
        query.bindValue(":email", ui->input_email->text());

        if (!query.exec()) {

                qDebug() << "Erreur de la BDD : "<< query.lastError();
        }
        else {
            c->setLogin(ui->input_login->text());
            c->setPasswd(ui->input_mdp->text());
            c->setNom(ui->input_nom->text());
            c->setPrenom(ui->input_prenom->text());
            c->setSexe(ui->comboBox->currentText());
            c->setDate_naissance(ui->input_date_naiss->text());
            c->setEmail(ui->input_email->text());
            QDialog::done(1);
        }
    }
}
