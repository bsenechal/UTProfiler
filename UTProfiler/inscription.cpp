#include "inscription.h"
#include "ui_inscription.h"



Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{
    c = Connexion::getInstance();
    ui->setupUi(this);
    QObject::connect(ui->valider, SIGNAL(clicked()), this, SLOT(inscriptionUser()));
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::inscriptionUser(){
    db = dbmanager::getInstance();

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
        try {
            db->execute("BEGIN;");
            db->execute("INSERT INTO Etudiant (login, passwd, nom, prenom, sexe, date_naissance, email) VALUES ('" + ui->input_login->text() + "','" + ui->input_mdp->text() + "','" + ui->input_nom->text() + "','" + ui->input_prenom->text() + "','" + ui->comboBox->currentText() + "','" + ui->input_date_naiss->text() + "','" + ui->input_email->text() + "');");
            c->setLogin(ui->input_login->text());
            c->setPasswd(ui->input_mdp->text());
            c->setNom(ui->input_nom->text());
            c->setPrenom(ui->input_prenom->text());
            c->setSexe(ui->comboBox->currentText());
            c->setDate_naissance(ui->input_date_naiss->text());
            c->setEmail(ui->input_email->text());
            db->execute("COMMIT;");
            QDialog::done(1);
        }
        catch (UTProfilerException u){
            QMessageBox msgBox;
            db->execute("ROLLBACK;");
            msgBox.setText("Erreur lors de la création de votre compte, veuillez contacter un administrateur");
            msgBox.exec();
        }
    }
}
