#include "administration.h"
#include "ui_administration.h"


Administration::Administration(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::Administration)
{
    ui->setupUi(this);
    db = dbmanager::getInstance();
    uvs = db->getColonne("SELECT code FROM uv;"); 
    cursus = Cursus::getInstance();
    filieres = Filieres::getInstance();
    branches = Branches::getInstance();
    categories = Categorie::getInstance();

    dispo = Disponibilites::getInstance();
    etudiants = Etudiants::getInstance();

    ui->liste_modif_uv->addItems(uvs);
    ui->liste_suppr_uv->addItems(uvs);
    ui->liste_ajout_branche_dispo_uv->addItems(branches->getListe_branches());
    ui->liste_ajout_filiere_dispo_uv->addItems(filieres->getListe_filieres());
    ui->liste_ajout_categorie_dispo_uv->addItems(categories->getListe_categories());
    ui->liste_modif_dispo_dispo_uv->addItems(dispo->getListe_dispos());
    ui->liste_ajout_dispo_dispo_uv->addItems(dispo->getListe_dispos());

    ui->liste_modif_filiere->addItems(filieres->getListe_filieres());
    ui->liste_ajout_branche_dispo->addItems(branches->getListe_branches());
    ui->liste_suppr_filiere->addItems(filieres->getListe_filieres());

    ui->liste_modif_branche->addItems(branches->getListe_branches());
    ui->ajout_cursus_branche->addItems(cursus->getListe_cursus());
    ui->liste_suppr_branche->addItems(branches->getListe_branches());
    ui->modif_cursus_branche->addItems(cursus->getListe_cursus());
    ui->group_modifier_branche->setEnabled(false);

    ui->liste_suppr_etudiant->addItems(etudiants->getListe_etudiants());

    QObject::connect(ui->onglets_admin, SIGNAL(currentChanged(int)), this, SLOT(maj_admin()));

    /* ----- Gestion des UV ----- */
    QObject::connect(ui->toolBox_uv, SIGNAL(currentChanged(int)), this, SLOT(maj_uv()));

    /* Ajout des UV */
    QObject::connect(ui->sauvegarder_ajout_uv, SIGNAL(clicked()), this, SLOT(sauvegarde_ajout_uv()));
    QObject::connect(ui->sauvegarder_modif_uv, SIGNAL(clicked()), this, SLOT(sauvegarde_modif_uv()));
    QObject::connect(ui->ajout_branche_uv, SIGNAL(clicked()), this, SLOT(ajout_branche_uv()));
    QObject::connect(ui->retire_branche_uv, SIGNAL(clicked()), this, SLOT(retire_branche_uv()));
    QObject::connect(ui->ajout_filiere_uv, SIGNAL(clicked()), this, SLOT(ajout_filiere_uv()));
    QObject::connect(ui->retire_filiere_uv, SIGNAL(clicked()), this, SLOT(retire_filiere_uv()));
    QObject::connect(ui->ajout_categorie_uv, SIGNAL(clicked()), this, SLOT(ajout_categorie_uv()));
    QObject::connect(ui->retire_categorie_uv, SIGNAL(clicked()), this, SLOT(retire_categorie_uv()));
    QObject::connect(ui->ajout_dispo_uv, SIGNAL(clicked()), this, SLOT(ajout_dispo_uv()));
    QObject::connect(ui->retire_dispo_uv, SIGNAL(clicked()), this, SLOT(retire_dispo_uv()));


    /* Modification des UV */
    QObject::connect(ui->modif_uv, SIGNAL(clicked()), this, SLOT(modifier_uv()));
    QObject::connect(ui->modif_ajout_branche_uv, SIGNAL(clicked()), this, SLOT(modif_ajout_branche_uv()));
    QObject::connect(ui->modif_retire_branche_uv, SIGNAL(clicked()), this, SLOT(modif_retire_branche_uv()));
    QObject::connect(ui->modif_ajout_filiere_uv, SIGNAL(clicked()), this, SLOT(modif_ajout_filiere_uv()));
    QObject::connect(ui->modif_retire_filiere_uv, SIGNAL(clicked()), this, SLOT(modif_retire_filiere_uv()));
    QObject::connect(ui->modif_ajout_categorie_uv, SIGNAL(clicked()), this, SLOT(modif_ajout_categorie_uv()));
    QObject::connect(ui->modif_retire_categorie_uv, SIGNAL(clicked()), this, SLOT(modif_retire_categorie_uv()));
    QObject::connect(ui->modif_ajout_dispo_uv, SIGNAL(clicked()), this, SLOT(modif_ajout_dispo_uv()));
    QObject::connect(ui->modif_retire_dispo_uv, SIGNAL(clicked()), this, SLOT(modif_retire_dispo_uv()));

    /* Suppression des UV */
    QObject::connect(ui->supprimer_uv_2, SIGNAL(clicked()), this, SLOT(supprimer_uv()));

    /* Gestion des branches */
    QObject::connect(ui->sauvegarder_ajout_branche, SIGNAL(clicked()), this, SLOT(sauvegarde_ajout_branche()));
    QObject::connect(ui->modif_branche, SIGNAL(clicked()), this, SLOT(modifier_branche()));
    QObject::connect(ui->toolBox_branche, SIGNAL(currentChanged(int)), this, SLOT(maj_branche()));
    QObject::connect(ui->supprimer_branche_2, SIGNAL(clicked()), this, SLOT(supprimer_branche()));
    QObject::connect(ui->sauvegarder_modif_branche, SIGNAL(clicked()), this, SLOT(sauvegarde_modif_branche()));

    /* Gestion des filieres */
    QObject::connect(ui->sauvegarder_ajout_filiere, SIGNAL(clicked()), this, SLOT(sauvegarde_ajout_filiere()));
    QObject::connect(ui->modif_filiere, SIGNAL(clicked()), this, SLOT(modifier_filiere()));
    QObject::connect(ui->toolBox_filiere, SIGNAL(currentChanged(int)), this, SLOT(maj_filiere()));
    QObject::connect(ui->supprimer_filiere_2, SIGNAL(clicked()), this, SLOT(supprimer_filiere()));
    QObject::connect(ui->sauvegarder_modif_filiere, SIGNAL(clicked()), this, SLOT(sauvegarde_modif_filiere()));
    QObject::connect(ui->ajout_branche_filiere, SIGNAL(clicked()), this, SLOT(ajout_branche_filiere()));
    QObject::connect(ui->retire_branche_filiere, SIGNAL(clicked()), this, SLOT(retire_branche_filiere()));
    QObject::connect(ui->modif_retire_branche_filiere, SIGNAL(clicked()), this, SLOT(modif_retire_branche_filiere()));
    QObject::connect(ui->modif_ajout_branche_filiere, SIGNAL(clicked()), this, SLOT(modif_ajout_branche_filiere()));

    /* Gestion des cursus */
    QObject::connect(ui->sauvegarder_ajout_cursus, SIGNAL(clicked()), this, SLOT(sauvegarde_ajout_cursus()));
    QObject::connect(ui->modif_cursus, SIGNAL(clicked()), this, SLOT(modifier_cursus()));
    QObject::connect(ui->toolBox_cursus, SIGNAL(currentChanged(int)), this, SLOT(maj_cursus()));
    QObject::connect(ui->supprimer_cursus_2, SIGNAL(clicked()), this, SLOT(supprimer_cursus()));
    QObject::connect(ui->sauvegarder_modif_cursus, SIGNAL(clicked()), this, SLOT(sauvegarde_modif_cursus()));

    /* Gestion des etudiants */
    QObject::connect(ui->sauvegarder_ajout_etudiant, SIGNAL(clicked()), this, SLOT(sauvegarder_ajout_etudiant()));
    QObject::connect(ui->sauvegarder_modif_etudiant, SIGNAL(clicked()), this, SLOT(sauvegarder_modif_etudiant()));
    QObject::connect(ui->supprimer_etudiant, SIGNAL(clicked()), this, SLOT(supprimer_etudiant()));
    QObject::connect(ui->toolBox_etudiant, SIGNAL(currentChanged(int)), this, SLOT(maj_etudiant()));
    QObject::connect(ui->modif_etudiant, SIGNAL(clicked()), this, SLOT(modifier_etudiant()));

    /* Gestion des disponibilités */
    QObject::connect(ui->sauvegarder_ajout_dispo, SIGNAL(clicked()), this, SLOT(sauvegarde_ajout_dispo()));
    QObject::connect(ui->modif_dispo, SIGNAL(clicked()), this, SLOT(modifier_dispo()));
    QObject::connect(ui->toolBox_dispo, SIGNAL(currentChanged(int)), this, SLOT(maj_dispo()));
    QObject::connect(ui->supprimer_disponibilite, SIGNAL(clicked()), this, SLOT(supprimer_dispo()));
    QObject::connect(ui->sauvegarder_modif_dispo, SIGNAL(clicked()), this, SLOT(sauvegarde_modif_dispo()));

    /* Gestion des utilisateurs */
    QObject::connect(ui->sauvegarder_role, SIGNAL(clicked()), this, SLOT(sauvegarder_role()));
    QObject::connect(ui->ajout_administrateur, SIGNAL(clicked()), this, SLOT(ajout_administrateur()));
    QObject::connect(ui->retire_administrateur, SIGNAL(clicked()), this, SLOT(retire_administrateur()));
}


void Administration::add_to_list(QListWidget *liste1,  QListWidget *liste2) {
    if (liste1->currentItem() != NULL) {
            liste2->addItem(liste1->currentItem()->text());
            delete liste1->currentItem();
        }
}

void Administration::add_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget *liste_credits, QString const nb_credits){
    if (liste1->currentItem() != NULL) {
        add_to_list(liste1, liste2);
        liste_credits->addItem(nb_credits);
    }
}

void Administration::remove_categorie(QListWidget *liste1,  QListWidget *liste2, QListWidget  *liste_credits){
    if (liste1->currentItem() != NULL) {
        liste_credits->takeItem((int) liste1->row(liste1->currentItem()));
        add_to_list(liste1, liste2);
    }
}


Administration::~Administration()
{
    delete ui;
}

void Administration::maj_admin() {
    switch (ui->onglets_admin->currentIndex()) {
        case 0 : {
            this->maj_uv();
            break;
        }
        case 1 : {
            this->maj_filiere();
            break;
        }
        case 2 : {
            this->maj_filiere();
            break;
        }
        case 3 : {
            this->maj_branche();
            break;
        }
        case 4 : {
           this->maj_cursus();
           break;
        }
         case 5 : {
            this->maj_etudiant();
            break;
        }
        case 6 : {
            this->maj_role();
        break;
        }
    }
}

/* Gestion des utilisateurs */
void Administration::maj_role() {
    ui->liste_utilisateurs->addItems(db->getColonne("SELECT login FROM Etudiant WHERE admin = 'false'"));
    ui->liste_modif_credits_uv->addItems(db->getColonne("SELECT login FROM Etudiant WHERE admin = 'true'"));
}


void Administration::ajout_administrateur() { add_to_list(ui->liste_utilisateurs, ui->liste_administrateurs); }
void Administration::retire_administrateur() { add_to_list(ui->liste_administrateurs, ui->liste_utilisateurs); }

void Administration::sauvegarder_role() {
    try {
        db->execute("BEGIN;");
        for (int i = 0 ; i < ui->liste_administrateurs->count() ; i++){
            db->execute("UPDATE Etudiant SET admin = 'true' WHERE login = '" + ui->liste_administrateurs->item(i)->text() + "';");
        }

        db->execute("COMMIT;");

    }
    catch (UTProfilerException u) {
        db->execute("ROLLBACK;");
        ui->message_role->setText(u.getInfo());
    }
}

/* Gestion des UV */

void Administration::modif_ajout_dispo_uv() { add_to_list(ui->liste_modif_dispo_dispo_uv, ui->liste_modif_dispo_choisie_uv); }
void Administration::modif_retire_dispo_uv() { add_to_list(ui->liste_modif_dispo_choisie_uv, ui->liste_modif_dispo_dispo_uv); }
void Administration::modif_ajout_branche_uv() { add_categorie(ui->liste_modif_branche_dispo_uv, ui->liste_modif_branche_choisie_uv, ui->liste_modif_obligation_uv, ui->modif_obligation_uv->text()); }
void Administration::modif_retire_branche_uv() { remove_categorie(ui->liste_modif_branche_choisie_uv, ui->liste_modif_branche_dispo_uv, ui->liste_modif_obligation_uv); }
void Administration::modif_ajout_filiere_uv() { add_to_list(ui->liste_modif_filiere_dispo_uv, ui->liste_modif_filiere_choisie_uv); }
void Administration::modif_retire_filiere_uv() { add_to_list(ui->liste_modif_filiere_choisie_uv, ui->liste_modif_filiere_dispo_uv); }
void Administration::modif_ajout_categorie_uv() { add_categorie(ui->liste_modif_categorie_dispo_uv, ui->liste_modif_categorie_choisie_uv, ui->liste_modif_credits_uv, ui->modif_credit_uv->text()); }
void Administration::modif_retire_categorie_uv() { remove_categorie(ui->liste_modif_categorie_choisie_uv, ui->liste_modif_categorie_dispo_uv, ui->liste_modif_credits_uv); }


void Administration::sauvegarde_ajout_uv() {
    QString code_uv = ui->ajout_code_uv->text();
    bool error = true;

    ui->message_ajout_uv->setText("");

    try {
        formulaire<QString>::verif_text(code_uv, "Code");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_ajout_uv->setText(e.getinfo());
    }
    if (!error) {
        try {
            db->execute("BEGIN;");

            db->execute("INSERT INTO UV VALUES ('" + code_uv + "','" + ui->ajout_description_uv->toPlainText() + "');");

            for (int i = 0 ; i < ui->liste_ajout_dispo_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_disponibilite_uv (code_uv, nom_disponibilite) VALUES ('" + code_uv + "','" + ui->liste_ajout_dispo_choisie_uv->item(i)->text() + "');");
            }

            for (int i = 0 ; i < ui->liste_ajout_branche_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_branche_uv (code_uv, nom_branche, obligation) VALUES ('" + code_uv + "','" + ui->liste_ajout_branche_choisie_uv->item(i)->text() + "','" + ui->liste_ajout_obligation_uv->item(i)->text() + "');");
            }

            for (int i = 0 ; i < ui->liste_ajout_categorie_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_categorie_uv (nom_categorie, code_uv, nbcredits) VALUES ('" + ui->liste_ajout_categorie_choisie_uv->item(i)->text() + "','" + code_uv  + "','" + ui->liste_ajout_credits_uv->item(i)->text() + "');");
            }

            for (int i = 0 ; i < ui->liste_ajout_filiere_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_filiere_uv (code_uv, nom_filiere) VALUES ('" + code_uv + "','" + ui->liste_ajout_filiere_choisie_uv->item(i)->text() + "');");
            }

            uvs.push_back(code_uv);
            db->execute("COMMIT;");
            ui->message_ajout_uv->setText("L'UV a correctement été ajoutée");
            ui->ajout_code_uv->clear();
            ui->ajout_description_uv->clear();
            this->maj_uv();
            }
        catch (UTProfilerException u) {
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
     }
}


void Administration::sauvegarde_modif_uv() {
   QString nouv_code_uv = ui->modif_code_uv->text();
   QString ancien_code_uv = ui->liste_modif_uv->currentItem()->text();

   bool error = true;

    ui->message_modif_uv->setText("");

    try {
        formulaire<QString>::verif_text(nouv_code_uv, "Code");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_modif_uv->setText(e.getinfo());
    }

    if (!error) {
        db->execute("BEGIN;");

        try {
            db->execute("DELETE FROM UV WHERE code = '" + ancien_code_uv + "';");

            db->execute("INSERT INTO UV VALUES ('" + nouv_code_uv + "','" + ui->modif_description_uv->toPlainText() + "');");

            db->execute("DELETE FROM assoc_branche_uv WHERE code_uv = '" + ancien_code_uv + "';");
            for (int i = 0 ; i < ui->liste_modif_branche_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_branche_uv (code_uv, nom_branche, obligation) VALUES ('" + nouv_code_uv + "','" + ui->liste_modif_branche_choisie_uv->item(i)->text() + "', '" + ui->liste_modif_obligation_uv->item(i)->text() +"');");
            }

            db->execute("DELETE FROM assoc_disponibilite_uv WHERE code_uv = '" + ancien_code_uv + "';");
            for (int i = 0 ; i < ui->liste_modif_dispo_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_disponibilite_uv (code_uv, nom_disponibilite) VALUES ('" + nouv_code_uv + "','" + ui->liste_modif_dispo_choisie_uv->item(i)->text() + "');");
            }

            db->execute("DELETE FROM assoc_categorie_uv WHERE code_uv = '" + ancien_code_uv + "';");
            for (int i = 0 ; i < ui->liste_modif_categorie_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_categorie_uv (nom_categorie, code_uv, nbcredits) VALUES ('" + ui->liste_modif_categorie_choisie_uv->item(i)->text() + "','" + nouv_code_uv  + "','" + ui->liste_modif_credits_uv->item(i)->text() + "');");
            }

            db->execute("DELETE FROM assoc_filiere_uv WHERE code_uv = '" + ancien_code_uv+ "';");
            for (int i = 0 ; i < ui->liste_modif_filiere_choisie_uv->count() ; i++){
                db->execute("INSERT INTO assoc_filiere_uv (code_uv, nom_filiere) VALUES ('" + nouv_code_uv + "','" + ui->liste_modif_filiere_choisie_uv->item(i)->text() + "');");
            }
            db->execute("COMMIT;");
            ui->message_modif_uv->setText("L'UV a correctement été modifiée");
            uvs.removeAt(ui->liste_modif_uv->row(ui->liste_modif_uv->currentItem()));
            uvs.push_back(nouv_code_uv);
            ui->modif_code_uv->clear();
            ui->modif_description_uv->clear();
            ui->liste_modif_credits_uv->clear();
            this->maj_uv();
        }
        catch (UTProfilerException u){
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
     }
}

void Administration::modifier_uv() {
    if (ui->liste_modif_uv->currentItem() != NULL) {
        QString nom_uv = ui->liste_modif_uv->currentItem()->text();
        ui->group_modif_uv->setEnabled(true);
        ui->liste_modif_branche_dispo_uv->addItems(db->getColonne("SELECT nom FROM branche WHERE nom NOT IN (SELECT nom_branche FROM assoc_branche_uv WHERE code_uv = '" + nom_uv + "');"));
        ui->liste_modif_branche_choisie_uv->addItems(db->getColonne("SELECT nom_branche FROM assoc_branche_uv WHERE code_uv = '" + nom_uv + "';"));

        ui->liste_modif_dispo_dispo_uv->addItems(db->getColonne("SELECT nom FROM disponibilite_uv WHERE nom NOT IN (SELECT nom_disponibilite FROM assoc_disponibilite_uv WHERE code_uv = '" + nom_uv + "');"));
        ui->liste_modif_dispo_choisie_uv->addItems(db->getColonne("SELECT nom_disponibilite FROM assoc_disponibilite_uv WHERE code_uv = '" + nom_uv + "';"));

        ui->liste_modif_filiere_dispo_uv->addItems(db->getColonne("SELECT nom FROM filiere WHERE nom NOT IN (SELECT nom_filiere FROM assoc_filiere_uv WHERE code_uv = '" + nom_uv + "');"));
        ui->liste_modif_filiere_choisie_uv->addItems(db->getColonne("SELECT nom_filiere FROM assoc_filiere_uv WHERE code_uv = '" + nom_uv + "';"));

        ui->liste_modif_categorie_dispo_uv->addItems(db->getColonne("SELECT nom FROM categorie WHERE nom NOT IN (SELECT nom_categorie FROM assoc_categorie_uv WHERE code_uv = '" + nom_uv + "');"));
        ui->liste_modif_categorie_choisie_uv->addItems(db->getColonne("SELECT nom_categorie FROM assoc_categorie_uv WHERE code_uv = '" + nom_uv + "' ORDER BY nbcredits DESC;"));
        ui->liste_modif_credits_uv->addItems(db->getColonne("SELECT nbcredits FROM assoc_categorie_uv WHERE code_uv = '" + nom_uv + "' ORDER BY nbcredits DESC;"));
        ui->modif_code_uv->setText(nom_uv);
        ui->modif_description_uv->setText(nom_uv);
    }

}

void Administration::supprimer_uv() {
    QString code_uv = ui->liste_suppr_uv->currentItem()->text();

    try {
        db->execute("BEGIN;");

        db->execute("DELETE FROM UV WHERE code = '" + code_uv + "';");

        db->execute("DELETE FROM assoc_branche_uv WHERE code_uv = '" + code_uv + "';");

        db->execute("DELETE FROM assoc_disponibilite_uv WHERE code_uv = '" + code_uv + "';");

        db->execute("DELETE FROM assoc_categorie_uv WHERE code_uv = '" + code_uv + "';");

        db->execute("DELETE FROM assoc_filiere_uv WHERE code_uv = '" + code_uv + "';");

        db->execute("COMMIT;");
        ui->message_suppr_uv->setText("L'UV a correctement été supprimée");
        uvs.removeAt(ui->liste_suppr_uv->row(ui->liste_suppr_uv->currentItem()));
        this->maj_uv();
    }
    catch (UTProfilerException u){
        db->execute("ROLLBACK;");
        msgBox.setText(u.getInfo());
        msgBox.exec();
    }
}
void Administration::ajout_dispo_uv() { add_to_list(ui->liste_ajout_dispo_dispo_uv, ui->liste_ajout_dispo_choisie_uv); }
void Administration::retire_dispo_uv() { add_to_list(ui->liste_ajout_dispo_choisie_uv, ui->liste_ajout_dispo_dispo_uv); }
void Administration::ajout_branche_uv() { add_categorie(ui->liste_ajout_branche_dispo_uv, ui->liste_ajout_branche_choisie_uv, ui->liste_ajout_obligation_uv, ui->ajout_obligation_uv->text()); }
void Administration::retire_branche_uv() { remove_categorie(ui->liste_ajout_branche_choisie_uv, ui->liste_ajout_branche_dispo_uv, ui->liste_ajout_obligation_uv); }
void Administration::ajout_filiere_uv() { add_to_list(ui->liste_ajout_filiere_dispo_uv, ui->liste_ajout_filiere_choisie_uv); }
void Administration::retire_filiere_uv() { add_to_list(ui->liste_ajout_filiere_choisie_uv, ui->liste_ajout_filiere_dispo_uv); }
void Administration::ajout_categorie_uv() { add_categorie(ui->liste_ajout_categorie_dispo_uv, ui->liste_ajout_categorie_choisie_uv, ui->liste_ajout_credits_uv, ui->ajout_credit_uv->text()); }
void Administration::retire_categorie_uv() { remove_categorie(ui->liste_ajout_categorie_choisie_uv, ui->liste_ajout_categorie_dispo_uv, ui->liste_ajout_credits_uv); }

void Administration::maj_uv() {
    switch (ui->toolBox_uv->currentIndex()) {
        case 0 : {
            ui->liste_ajout_branche_choisie_uv->clear();
            ui->liste_ajout_branche_dispo_uv->clear();
            ui->liste_ajout_branche_dispo_uv->addItems(branches->getListe_branches());
            ui->liste_ajout_categorie_choisie_uv->clear();
            ui->liste_ajout_credits_uv->clear();
            ui->liste_ajout_categorie_dispo_uv->clear();
            ui->liste_ajout_categorie_dispo_uv->addItems(categories->getListe_categories());
            ui->liste_ajout_dispo_dispo_uv->clear();
            ui->liste_ajout_dispo_choisie_uv->clear();
            ui->liste_ajout_dispo_dispo_uv->addItems(dispo->getListe_dispos());
            ui->liste_ajout_filiere_choisie_uv->clear();
            ui->liste_ajout_filiere_dispo_uv->clear();
            ui->liste_ajout_filiere_dispo_uv->addItems(filieres->getListe_filieres());
            break;
        }
        case 1 : {
            ui->liste_modif_uv->clear();
            ui->liste_modif_uv->addItems(uvs);
            ui->liste_modif_branche_choisie_uv->clear();
            ui->liste_modif_branche_dispo_uv->clear();
            ui->liste_modif_categorie_choisie_uv->clear();
            ui->liste_modif_categorie_dispo_uv->clear();
            ui->liste_modif_filiere_choisie_uv->clear();
            ui->liste_modif_filiere_dispo_uv->clear();
            ui->group_modif_uv->setEnabled(false);
            ui->modif_code_uv->clear();
            ui->modif_description_uv->clear();
            ui->liste_modif_dispo_dispo_uv->clear();
            ui->liste_modif_dispo_choisie_uv->clear();
            ui->liste_modif_credits_uv->clear();
            break;
        }
        case 2 : {
            ui->liste_suppr_uv->clear();
            ui->liste_suppr_uv->addItems(uvs);
            break;
        }

    }

}

/* Gestion des disponibilites des UV */
void Administration::sauvegarde_ajout_dispo() {
    QSqlQuery query;
    bool error = true;

    try {
        formulaire<QString>::verif_text(ui->ajout_nom_dispo->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_ajout_dispo->setText(e.getinfo());
    }
    if (!error) {
        query = db->execute("INSERT INTO disponibilite_uv VALUES ('" + ui->ajout_nom_dispo->text() + "');");

        if (query.lastError().number() == -1) {
            dispo->getListe_dispos().push_back(ui->ajout_nom_dispo->text());
            ui->ajout_nom_dispo->setText("");
            ui->message_ajout_dispo->setText("La disponibilité a correctement été ajoutée");
        }
        else {
            ui->message_ajout_dispo->setText(query.lastError().text());
        }
    }
}

void Administration::sauvegarde_modif_dispo() {
    QSqlQuery query;
    bool error = true;
    ui->message_modif_dispo->setText("");
    try {
        formulaire<QString>::verif_text(ui->modif_nom_dispo->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_modif_dispo->setText(e.getinfo());
    }
    if (!error) {
        query = db->execute("UPDATE disponibilite_uv SET nom = '" + ui->modif_nom_dispo->text() + "' WHERE nom='" + ui->liste_modif_dispo->currentItem()->text() + "';");

        if (query.lastError().number() == -1) {
            dispo->getListe_dispos().push_back(ui->modif_nom_dispo->text());
            ui->modif_nom_dispo->setText("");
            dispo->getListe_dispos().removeAt(ui->liste_modif_dispo->row(ui->liste_modif_dispo->currentItem()));
            ui->message_modif_dispo->setText("La disponibilité a correctement été modifiée");
            this->maj_dispo();
        }
        else {
            ui->message_modif_dispo->setText(query.lastError().text());
        }
    }
}

void Administration::modifier_dispo() {
    if (ui->liste_modif_dispo->currentItem() != NULL) {
        QSqlQuery query;
        ui->group_modifier_dispo->setEnabled(true);

        query = db->execute("SELECT * FROM disponibilite_uv WHERE nom ='" + ui->liste_modif_dispo->currentItem()->text() + "';");

        if (query.next()) {
            ui->modif_nom_dispo->setText(query.value(0).toString());
        }
        else {
            ui->message_modif_dispo->setText(query.lastError().text());
        }
    }
}

void Administration::supprimer_dispo() {

     if (ui->liste_suppr_dispo->currentItem() != NULL) {
        try {
            db->execute("DELETE FROM disponibilite_uv WHERE nom = '" + ui->liste_suppr_dispo->currentItem()->text() + "';");
            dispo->getListe_dispos().removeAt(ui->liste_suppr_dispo->row(ui->liste_suppr_dispo->currentItem()));
            delete ui->liste_suppr_dispo->currentItem();
            ui->message_suppr_dispo->setText("La disponibilité a correctement été supprimée");

        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }

     }
}

void Administration::maj_dispo() {
    switch (ui->toolBox_dispo->currentIndex()) {
        case 1 : {
            ui->liste_modif_dispo->clear();
            ui->liste_modif_dispo->addItems(dispo->getListe_dispos());
            ui->group_modifier_dispo->setEnabled(false);
            break;
        }
        case 2 : {
            ui->liste_suppr_dispo->clear();
            ui->liste_suppr_dispo->addItems(dispo->getListe_dispos());
            break;
        }

    }
}


/* Gestion des filieres */
void Administration::sauvegarde_ajout_filiere() {
    bool error = true;

    try {
        formulaire<QString>::verif_text(ui->ajout_nom_filiere->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_ajout_filiere->setText(e.getinfo());
    }
    if (!error) {
        try {
            db->execute("BEGIN;");
            db->execute("INSERT INTO FILIERE VALUES ('" + ui->ajout_nom_filiere->text() + "','" + ui->ajout_description_filiere->toPlainText() + "');");


            for (int i = 0 ; i < ui->liste_ajout_branche_choisie->count() ; i++) {
                db->execute("INSERT INTO assoc_branche_filiere (nom_filiere, nom_branche) VALUES ('" + ui->ajout_nom_filiere->text() + "','" + ui->liste_ajout_branche_choisie->item(i)->text() + "');");
            }

            db->execute("COMMIT;");
            filieres->getListe_filieres().push_back(ui->ajout_nom_filiere->text());
            ui->ajout_nom_filiere->setText("");
            ui->ajout_description_filiere->setText("");
            ui->message_ajout_filiere->setText("La filière a correctement été ajoutée");
            this->maj_filiere();
        }
        catch (UTProfilerException u) {
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::ajout_branche_filiere() { add_to_list(ui->liste_ajout_branche_dispo, ui->liste_ajout_branche_choisie); }
void Administration::retire_branche_filiere() { add_to_list(ui->liste_ajout_branche_choisie, ui->liste_ajout_branche_dispo); }
void Administration::modif_ajout_branche_filiere() { add_to_list(ui->liste_modif_branche_dispo, ui->liste_modif_branche_choisie); }
void Administration::modif_retire_branche_filiere() { add_to_list(ui->liste_modif_branche_choisie, ui->liste_modif_branche_dispo); }


void Administration::sauvegarde_modif_filiere() {
    bool error = true;

    ui->message_modif_filiere->setText("");
    try {
        formulaire<QString>::verif_text(ui->modif_nom_filiere->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_modif_filiere->setText(e.getinfo());
    }
    if (!error) {
        try {
        db->execute("BEGIN;");

        db->execute("DELETE FROM filiere WHERE nom ='" + ui->liste_modif_filiere->currentItem()->text() +"';");

        db->execute("INSERT INTO filiere (nom, description) VALUES ('" + ui->modif_nom_filiere->text() +"','" + ui->modif_description_filiere->toPlainText() + "');");

        db->execute("DELETE FROM assoc_branche_filiere WHERE nom_filiere ='" + ui->liste_modif_filiere->currentItem()->text() +"';");

        for (int i = 0 ; i < ui->liste_modif_branche_choisie->count() ; i++) {
            db->execute("INSERT INTO assoc_branche_filiere (nom_filiere, nom_branche) VALUES ('" + ui->modif_nom_filiere->text() + "','" + ui->liste_modif_branche_choisie->item(i)->text() + "');");
        }

        db->execute("COMMIT;");
        filieres->getListe_filieres().push_back(ui->modif_nom_filiere->text());
        ui->modif_nom_filiere->setText("");
        ui->modif_description_filiere->setText("");
        filieres->getListe_filieres().removeAt(ui->liste_modif_filiere->row(ui->liste_modif_filiere->currentItem()));
        ui->message_modif_filiere->setText("La filière a correctement été modifiée");
        this->maj_filiere();
        }
        catch (UTProfilerException u) {
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::modifier_filiere() {
    if (ui->liste_modif_filiere->currentItem() != NULL) {
        QSqlQuery query;
        ui->group_modif_filiere->setEnabled(true);
        query = db->execute("SELECT * FROM Filiere WHERE nom ='" + ui->liste_modif_filiere->currentItem()->text() + "';");

        if (query.next()) {
            ui->liste_modif_branche_choisie->clear();
            ui->liste_modif_branche_choisie->addItems(db->getColonne("SELECT nom_branche FROM assoc_branche_filiere WHERE nom_filiere = '" + ui->liste_modif_filiere->currentItem()->text() + "';"));
            ui->liste_modif_branche_dispo->clear();
            ui->liste_modif_branche_dispo->addItems(db->getColonne("SELECT nom FROM branche WHERE nom NOT IN (SELECT nom_branche FROM assoc_branche_filiere WHERE nom_filiere = '" + ui->liste_modif_filiere->currentItem()->text() + "');"));
            ui->modif_nom_filiere->setText(query.value(0).toString());
            ui->modif_description_filiere->setText(query.value(1).toString());
        }
        else {
            ui->message_modif_filiere->setText(query.lastError().text());
        }


    }
}

void Administration::supprimer_filiere() {
     if (ui->liste_suppr_filiere->currentItem() != NULL) {
         try {
            db->execute("BEGIN;");

            db->execute("DELETE FROM filiere WHERE nom ='" + ui->liste_suppr_filiere->currentItem()->text() +"';");

            db->execute("DELETE FROM assoc_branche_filiere WHERE nom_filiere ='" + ui->liste_suppr_filiere->currentItem()->text() +"';");

            db->execute("COMMIT;");
            ui->message_suppr_filiere->setText("La filière a correctement été supprimée");
            filieres->getListe_filieres().removeAt(ui->liste_suppr_filiere->row(ui->liste_suppr_filiere->currentItem()));
            delete ui->liste_suppr_filiere->currentItem();
         }
         catch(UTProfilerException u) {
             db->execute("ROLLBACK;");
             msgBox.setText(u.getInfo());
             msgBox.exec();
            }

     }
}

void Administration::maj_filiere() {
    switch (ui->toolBox_filiere->currentIndex()) {
        case 0 : {
            ui->liste_ajout_branche_dispo->clear();
            ui->liste_ajout_branche_dispo->addItems(branches->getListe_branches());
            ui->liste_ajout_branche_choisie->clear();
            break;
        }
        case 1 : {
            ui->liste_modif_branche_dispo->clear();
            ui->liste_modif_branche_choisie->clear();
            ui->modif_nom_filiere->clear();
            ui->modif_description_filiere->clear();
            ui->group_modif_filiere->setEnabled(false);
            ui->liste_modif_filiere->clear();
            ui->liste_modif_filiere->addItems(filieres->getListe_filieres());
            break;
        }
        case 2 : {
            ui->liste_suppr_filiere->clear();
            ui->liste_suppr_filiere->addItems(filieres->getListe_filieres());
            break;
        }

    }

}



/* Gestion des branches */
void Administration::sauvegarde_ajout_branche() {
    bool error = true;

    try {
        formulaire<QString>::verif_text(ui->ajout_nom_branche->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_ajout_branche->setText(e.getinfo());
    }
    if (!error) {
        try {
            db->execute("INSERT INTO branche VALUES ('" + ui->ajout_nom_branche->text() + "','" + ui->ajout_description_branche->toPlainText() + "','" + ui->ajout_cursus_branche->currentText() + "');");
            branches->getListe_branches().push_back(ui->ajout_nom_branche->text());
            ui->ajout_nom_branche->setText("");
            ui->ajout_description_branche->setText("");
            ui->message_ajout_branche->setText("La branche a correctement été ajoutée");

        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::sauvegarde_modif_branche() {
    bool error = true;
    ui->message_modif_branche->setText("");
    try {
        formulaire<QString>::verif_text(ui->modif_nom_branche->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_modif_branche->setText(e.getinfo());
    }
        try {
            db->execute("UPDATE Branche SET nom = '" + ui->modif_nom_branche->text() + "', description = '" + ui->modif_description_branche->toPlainText() + "', nom_cursus = '" + ui->modif_cursus_branche->currentText() + "' WHERE nom='" + ui->liste_modif_branche->currentItem()->text() + "';");

            branches->getListe_branches().push_back(ui->modif_nom_branche->text());
            ui->modif_nom_branche->setText("");
            ui->modif_description_branche->setText("");
            branches->getListe_branches().removeAt(ui->liste_modif_branche->row(ui->liste_modif_branche->currentItem()));
            ui->message_modif_branche->setText("La branche a correctement été modifiée");
            this->maj_branche();
        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
}

void Administration::modifier_branche() {
    if (ui->liste_modif_branche->currentItem() != NULL) {
        QSqlQuery query;
        ui->group_modifier_branche->setEnabled(true);

        query = db->execute("SELECT * FROM branche WHERE nom ='" + ui->liste_modif_branche->currentItem()->text() + "';");

        if (query.next()) {
            ui->modif_nom_branche->setText(query.value(0).toString());
            ui->modif_description_branche->setText(query.value(1).toString());
        }
        else {
            ui->message_modif_branche->setText(query.lastError().text());
        }
    }
}

void Administration::supprimer_branche() {

     if (ui->liste_suppr_branche->currentItem() != NULL) {

        try {
            db->execute("DELETE FROM Branche WHERE nom = '" + ui->liste_suppr_branche->currentItem()->text() + "';");

            branches->getListe_branches().removeAt(ui->liste_suppr_branche->row(ui->liste_suppr_branche->currentItem()));
            delete ui->liste_suppr_branche->currentItem();
            ui->message_suppr_branche->setText("La branche a correctement été supprimée");
        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
     }
}

void Administration::maj_branche() {
    switch (ui->toolBox_branche->currentIndex()) {
        case 0 : {
            ui->ajout_cursus_branche->clear();
            ui->ajout_cursus_branche->addItems(cursus->getListe_cursus());
            break;
        }
        case 1 : {
            ui->liste_modif_branche->clear();
            ui->liste_modif_branche->addItems(branches->getListe_branches());
            ui->modif_cursus_branche->clear();
            ui->modif_cursus_branche->addItems(cursus->getListe_cursus());
            ui->group_modifier_branche->setEnabled(false);
            break;
        }
        case 2 : {
            ui->liste_suppr_branche->clear();
            ui->liste_suppr_branche->addItems(branches->getListe_branches());
            break;
        }

    }

}


/* Gestion des cursus */
void Administration::sauvegarde_ajout_cursus() {
    bool error = true;

    try {
        formulaire<QString>::verif_text(ui->ajout_nom_cursus->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_ajout_cursus->setText(e.getinfo());
    }
    if (!error) {
        try {
            db->execute("INSERT INTO cursus VALUES ('" + ui->ajout_nom_cursus->text() + "','" + ui->ajout_description_cursus->toPlainText() + "');");

            cursus->push_back(ui->ajout_nom_cursus->text());
            ui->ajout_nom_cursus->setText("");
            ui->ajout_description_cursus->setText("");
            ui->message_ajout_cursus->setText("Le cursus a correctement été ajoutée");
        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::sauvegarde_modif_cursus() {
    bool error = true;
    ui->message_modif_cursus->setText("");

    try {
        formulaire<QString>::verif_text(ui->modif_nom_cursus->text(), "Nom");
        error = false;
    }

    catch (FormulaireException e) {
        ui->message_modif_cursus->setText(e.getinfo());
    }
    if (!error) {
        try {
            db->execute("UPDATE cursus SET nom = '" + ui->modif_nom_cursus->text() + "', description = '" + ui->modif_description_cursus->toPlainText() + "' WHERE nom='" + ui->liste_modif_cursus->currentItem()->text() + "';");
            cursus->push_back(ui->modif_nom_cursus->text());
            ui->modif_nom_cursus->setText("");
            ui->modif_description_cursus->setText("");
            cursus->removeAt(ui->liste_modif_cursus->row(ui->liste_modif_cursus->currentItem()));
            ui->message_modif_cursus->setText("Le cursus a correctement été modifiée");
            this->maj_cursus();
        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::modifier_cursus() {
    if (ui->liste_modif_cursus->currentItem() != NULL) {
        QSqlQuery query;
        ui->group_modif_cursus->setEnabled(true);
        query = db->execute("SELECT * FROM cursus WHERE nom ='" + ui->liste_modif_cursus->currentItem()->text() + "';");

        if (query.next()) {
            ui->modif_nom_cursus->setText(query.value(0).toString());
            ui->modif_description_cursus->setText(query.value(1).toString());
        }
        else {
            ui->message_modif_cursus->setText(query.lastError().text());
        }


    }
}

void Administration::supprimer_cursus() {
    QSqlQuery query;
     if (ui->liste_suppr_cursus->currentItem() != NULL) {

        try {
            db->execute("DELETE FROM cursus WHERE nom = '" + ui->liste_suppr_cursus->currentItem()->text() + "';");

            cursus->removeAt(ui->liste_suppr_cursus->row(ui->liste_suppr_cursus->currentItem()));
            delete ui->liste_suppr_cursus->currentItem();
            ui->message_suppr_cursus->setText("Le cursus a correctement été supprimé");
        }
        catch(UTProfilerException u) {
             msgBox.setText(u.getInfo());
             msgBox.exec();
        }

     }
}

void Administration::maj_cursus() {
    switch (ui->toolBox_cursus->currentIndex()) {
        case 1 : {
            ui->liste_modif_cursus->clear();
            ui->liste_modif_cursus->addItems(cursus->getListe_cursus());
            ui->group_modif_cursus->setEnabled(false);
            break;
        }
        case 2 : {
            ui->liste_suppr_cursus->clear();
            ui->liste_suppr_cursus->addItems(cursus->getListe_cursus());
            break;
        }

    }
}

/* Gestion des Etudiants */
void Administration::supprimer_etudiant() {

     if (ui->liste_suppr_etudiant->currentItem() != NULL) {
        try {
            db->execute("DELETE FROM etudiant WHERE nom = '" + ui->liste_suppr_etudiant->currentItem()->text() + "';");
            etudiants->getListe_etudiants().removeAt(ui->liste_suppr_etudiant->row(ui->liste_suppr_etudiant->currentItem()));
            delete ui->liste_suppr_etudiant->currentItem();
        }
        catch (UTProfilerException u) {
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
     }
}


void Administration::sauvegarder_ajout_etudiant(){
        bool error = true;
        try {
            formulaire<QString>::verif_text(ui->ajout_login_etudiant->text(), "login");
            formulaire<QString>::verif_text(ui->ajout_nom_etudiant->text(), "nom");
            formulaire<QString>::verif_text(ui->ajout_prenom_etudiant->text(), "prenom");
            formulaire<QString>::verif_pass(ui->ajout_mdp_etudiant->text(), ui->ajout_mdp2_etudiant->text());
            formulaire<QString>::verif_text(ui->ajout_email_etudiant->text(), "email");
            error = false;
        }
        catch (FormulaireException e) {
            ui->message_ajout_etudiant->setText(e.getinfo());
        }

        if (!error){
            try {
                db->execute("BEGIN;");

                db->execute("INSERT INTO Etudiant (login, passwd, nom, prenom, sexe, date_naissance, email) VALUES ('" + ui->ajout_login_etudiant->text() + "','" + ui->ajout_mdp_etudiant->text() + "','" + ui->ajout_nom_etudiant->text() + "','" + ui->ajout_prenom_etudiant->text() + "','" + ui->ajout_sexe_etudiant->currentText() + "','" + ui->ajout_datenaiss_etudiant->text() + "','" + ui->ajout_email_etudiant->text() + "');");

                db->execute("COMMIT;");
                ui->message_ajout_etudiant->setText("L'étudiant a correctement été ajouté");
                etudiants->getListe_etudiants().push_back(ui->ajout_login_etudiant->text());
                ui->ajout_login_etudiant->clear();
                ui->ajout_nom_etudiant->clear();
                ui->ajout_prenom_etudiant->clear();
                ui->ajout_datenaiss_etudiant->clear();
                ui->ajout_mdp_etudiant->clear();
                ui->ajout_mdp2_etudiant->clear();
                ui->ajout_email_etudiant->clear();
            }
            catch (UTProfilerException u) {
                db->execute("ROLLBACK;");
                msgBox.setText(u.getInfo());
                msgBox.exec();
            }
        }
    }

void Administration::sauvegarder_modif_etudiant() {
    bool error = true;
    try {
        formulaire<QString>::verif_text(ui->modif_login_etudiant->text(), "login");
        formulaire<QString>::verif_text(ui->modif_nom_etudiant->text(), "nom");
        formulaire<QString>::verif_text(ui->modif_prenom_etudiant->text(), "prenom");
        formulaire<QString>::verif_pass(ui->modif_mdp_etudiant->text(), ui->modif_mdp2_etudiant->text());
        formulaire<QString>::verif_text(ui->modif_email_etudiant->text(), "email");
        error = false;
    }
    catch (FormulaireException e) {
        ui->message_modif_etudiant->setText(e.getinfo());
    }

    if (!error){
        try {
            db->execute("BEGIN;");

            db->execute("DELETE FROM Etudiant WHERE login = '" + ui->liste_modif_etudiant->currentItem()->text() + "';");


            db->execute("INSERT INTO Etudiant (login, passwd, nom, prenom, sexe, date_naissance, email) VALUES ('" + ui->modif_login_etudiant->text() + "','" + ui->modif_mdp_etudiant->text() + "','" + ui->modif_nom_etudiant->text() + "','" + ui->modif_prenom_etudiant->text() + "','" + ui->modif_sexe_etudiant->currentText() + "','" + ui->modif_datenaiss_etudiant->text() + "','" + ui->modif_email_etudiant->text() + "');");


            db->execute("COMMIT;");
            ui->message_modif_etudiant->setText("L'étudiant a correctement été modifié");
            etudiants->getListe_etudiants().removeAt(ui->liste_modif_etudiant->row(ui->liste_modif_etudiant->currentItem()));
            etudiants->getListe_etudiants().push_back(ui->modif_login_etudiant->text());
            ui->modif_login_etudiant->clear();
            ui->modif_nom_etudiant->clear();
            ui->modif_prenom_etudiant->clear();
            ui->modif_datenaiss_etudiant->clear();
            ui->modif_mdp_etudiant->clear();
            ui->modif_mdp2_etudiant->clear();
            ui->modif_email_etudiant->clear();
            ui->group_modif_etudiant->setEnabled(false);
        }
        catch (UTProfilerException u) {
            db->execute("ROLLBACK;");
            msgBox.setText(u.getInfo());
            msgBox.exec();
        }
    }
}

void Administration::modifier_etudiant() {
    QSqlQuery query;
       if (ui->liste_modif_etudiant->currentItem() != NULL) {
            ui->group_modif_etudiant->setEnabled(true);
            query = db->execute("SELECT * FROM Etudiant WHERE login = '" + ui->liste_modif_etudiant->currentItem()->text() + "';");

            if (query.next()) {
                ui->modif_login_etudiant->setText(query.value(0).toString());
                ui->modif_mdp_etudiant->setText(query.value(1).toString());
                ui->modif_mdp2_etudiant->setText(query.value(1).toString());
                ui->modif_nom_etudiant->setText(query.value(2).toString());
                ui->modif_prenom_etudiant->setText(query.value(3).toString());
                ui->modif_datenaiss_etudiant->setText(query.value(5).toString());
                ui->modif_email_etudiant->setText(query.value(6).toString());
            }
            else {
                ui->message_modif_etudiant->setText(query.lastError().text());
            }
       }
}

void Administration::maj_etudiant() {
    switch (ui->toolBox_etudiant->currentIndex()) {
        case 1 : {
            ui->liste_modif_etudiant->clear();
            ui->liste_modif_etudiant->addItems(etudiants->getListe_etudiants());
            ui->group_modif_etudiant->setEnabled(false);
            break;
        }
        case 2 : {
            ui->liste_suppr_etudiant->clear();
            ui->liste_suppr_etudiant->addItems(etudiants->getListe_etudiants());
            break;
        }

    }
}
