#include "inscription.h"
#include "ui_inscription.h"



Inscription::Inscription(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Inscription)
{
    ui->setupUi(this);
    db = dbmanager::getInstance();
    c = Connexion::getInstance();
    cursus = Cursus::getInstance();
    branches = Branches::getInstance();
    filieres = Filieres::getInstance();
    semestres = Semestre::getInstance();

    ui->comboBox_branche->setEnabled(false);
    ui->comboBox_filiere->setEnabled(false);

    ui->comboBox_branche->addItem("");
    ui->comboBox_branche->addItems(branches->getListe_branches());
    ui->comboBox_cursus->addItem("");
    ui->comboBox_cursus->addItems(cursus->getListe_cursus());
    ui->comboBox_semestre->addItem("");
    ui->comboBox_semestre->addItems(semestres->getListe_semestres());
    ui->comboBox_filiere->addItem("");
    ui->comboBox_filiere->addItems(filieres->getListe_filieres());

    QObject::connect(ui->valider, SIGNAL(clicked()), this, SLOT(inscriptionUser()));
    QObject::connect(ui->comboBox_cursus, SIGNAL(currentIndexChanged(int)), this, SLOT(enable_cursus()));
    QObject::connect(ui->comboBox_branche, SIGNAL(currentIndexChanged(int)), this, SLOT(enable_branche()));
}

void Inscription::enable_cursus() {
    Tools::enable_combobox(ui->comboBox_branche, branches->getBranchesFromCursus(ui->comboBox_cursus->currentText()));
    ui->comboBox_branche->setEnabled(true);
}

void Inscription::enable_branche(){
    Tools::enable_combobox(ui->comboBox_filiere, filieres->getFilieresFromBranche(ui->comboBox_branche->currentText()));
    ui->comboBox_filiere->setEnabled(true);
}

Inscription::~Inscription()
{
    delete ui;
}

void Inscription::inscriptionUser(){
    QMessageBox msgBox;

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
        msgBox.setText(e.getinfo());
        msgBox.exec();
    }

    if (!error) {
        try {
            db->execute("BEGIN;");
            db->execute("INSERT INTO Etudiant (login, passwd, nom, prenom, sexe, date_naissance, email) VALUES ('" + ui->input_login->text() + "','" + ui->input_mdp->text() + "','" + ui->input_nom->text() + "','" + ui->input_prenom->text() + "','" + ui->comboBox->currentText() + "','" + ui->input_date_naiss->text() + "','" + ui->input_email->text() + "');");
            qDebug() << ui->comboBox_branche->currentText();
            db->execute("INSERT INTO Dossier (login_etudiant, nom_filiere, nom_cursus, nom_branche, num_semestre_actuel) VALUES ('" + ui->input_login->text() + "','" + ui->comboBox_filiere->currentText() + "','" + ui->comboBox_cursus->currentText() + "','" + ui->comboBox_branche->currentText() + "','" + ui->comboBox_semestre->currentText() + "');");
            c->setLogin(ui->input_login->text());
            c->setPasswd(ui->input_mdp->text());
            c->setNom(ui->input_nom->text());
            c->setPrenom(ui->input_prenom->text());
            c->setSexe(ui->comboBox->currentText());
            c->setDate_naissance(ui->input_date_naiss->text());
            c->setEmail(ui->input_email->text());
            db->execute("COMMIT;");
            msgBox.setText("Votre compte a correctement été créé");
            msgBox.exec();
            QDialog::done(1);
        }
        catch (UTProfilerException u){
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}
