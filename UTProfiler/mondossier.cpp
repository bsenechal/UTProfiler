#include "mondossier.h"
#include "ui_mondossier.h"


mondossier::mondossier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mondossier)
{
    ui->setupUi(this);
    cursus = Cursus::getInstance();
    filieres = Filieres::getInstance();
    branches = Branches::getInstance();
    db = dbmanager::getInstance();
    semestres = Semestre::getInstance();
    QSqlQuery query;
    c = Connexion::getInstance();
    uvmnger = uvmnger::getInstance();


    ui->sauvegarder_modif->hide();
    ui->modif_semestre->hide();
    ui->modif_date_naiss->hide();
    ui->modif_email->hide();
    ui->modif_login->hide();
    ui->modif_cursus->hide();
    ui->modif_branche->hide();
    ui->modif_filiere->hide();
    ui->modif_nom->hide();
    ui->modif_prenom->hide();


/*/////////////////////////////////Remplacer par c->getLogin()    <<< ne marche pas !!*/
    query = db->execute("SELECT id_dossier FROM Dossier WHERE login_etudiant='damartin';");
     while(query.next()) {
         this->numerodossier=query.value(0).toString();
     }


    //Fenetre des choix
    query = db->execute("SELECT Code FROM UV;");
    while(query.next()) {
        ui->liste_selection_UV->addItem(query.value(0).toString());
        ui->liste_choix_uv->addItem(query.value(0).toString());
    }

    query = db->execute("SELECT UV, choix FROM choixUv;");
    while(query.next()) {
        if (query.value(1).toString()=="exigence"){
            ui->liste_exigences->addItem(query.value(0).toString());
        }
        else if (query.value(1).toString()=="preference"){
            ui->liste_preferences->addItem(query.value(0).toString());
        }
        else if (query.value(1).toString()=="rejet"){
            ui->liste_rejets->addItem(query.value(0).toString());
        }

        for (int i = 0; i < ui->liste_choix_uv->count(); i++) {
            if(ui->liste_choix_uv->item(i)->text()==query.value(0).toString()) {
                qDebug()<<ui->liste_choix_uv->item(i);
                delete ui->liste_choix_uv->item(i);
            };
        }
    }

    //Fin fenetre des choix


    ui->comboBox_cursus->addItem("");
    ui->comboBox_cursus->addItems(cursus->getListe_cursus());
    ui->comboBox_note->addItems(db->getColonne("SELECT Note FROM Note;"));
    ui->comboBox_semestre->addItems(semestres->getListe_semestres());
    QObject::connect(ui->ajout_uv, SIGNAL(clicked()), this, SLOT(ajoutUV()));
    QObject::connect(ui->add_exigence, SIGNAL(clicked()), this, SLOT(ajoutExigence()));
    QObject::connect(ui->add_rejet, SIGNAL(clicked()), this, SLOT(ajoutRejet()));
    QObject::connect(ui->add_preference, SIGNAL(clicked()), this, SLOT(ajoutPreference()));
    QObject::connect(ui->suppr_exigence, SIGNAL(clicked()), this, SLOT(supprExigence()));
    QObject::connect(ui->suppr_preference, SIGNAL(clicked()), this, SLOT(supprPreference()));
    QObject::connect(ui->suppr_rejet, SIGNAL(clicked()), this, SLOT(supprRejet()));
    QObject::connect(ui->sauvegarder_choix, SIGNAL(clicked()), this, SLOT(sauvegarder_choix()));
    QObject::connect(ui->modif_info, SIGNAL(clicked()), this, SLOT(modifier_infos()));
    QObject::connect(ui->modif_cursus, SIGNAL(currentIndexChanged(int)), this, SLOT(enable_branche()));
    QObject::connect(ui->sauvegarder_modif, SIGNAL(clicked()), this, SLOT(sauvegarder_modif()));
    QObject::connect(ui->sauvegarder_dossier, SIGNAL(clicked()), this, SLOT(sauvegarder_dossier()));
    QObject::connect(ui->onglets_dossier, SIGNAL(currentChanged(int)), this, SLOT(maj_dossier()));
    QObject::connect(ui->comboBox_cursus, SIGNAL(currentIndexChanged(int)), this, SLOT(enable_branche()));
    QObject::connect(ui->liste_selection_UV, SIGNAL(currentRowChanged(int)), this, SLOT(enable_credits()));
    //QObject::connect(ui->comboBox_branche, SIGNAL(clicked()), this, SLOT(enable_filiere()));
    QTimer::singleShot(0, this, SLOT(maj_dossier()));
    this->maj_dossier();
}

/* A modifier */

void mondossier::enable_credits() {
    QStringList combinaisons;
    QString curUv = ui->liste_selection_UV->currentItem()->text();
    qDebug()<< curUv;

    ui->comboBox_credits->clear();
    ui->comboBox_credits->addItem("");

    map_pos_uv = uvmnger->getPossibiliteFromUv(ui->liste_selection_UV->currentItem()->text());
    map<QString,QString>::iterator p;
    for(p = map_pos_uv.begin(); p != map_pos_uv.end(); p++)
    {
        combinaisons<<p->first;
    }

    ui->comboBox_credits->addItems(combinaisons);
    ui->comboBox_credits->setEnabled(true);
}


void mondossier::enable_filiere() {
    ui->comboBox_filiere->clear();
    ui->comboBox_filiere->addItem("");
    ui->comboBox_filiere->addItems(filieres->getFilieresFromBranche(ui->comboBox_branche->currentText()));
    ui->comboBox_filiere->setEnabled(true);
}

void mondossier::enable_branche() {
    ui->comboBox_branche->clear();
    ui->comboBox_branche->addItem("");
    ui->comboBox_branche->addItems(branches->getBranchesFromCursus(ui->comboBox_cursus->currentText()));
    ui->comboBox_branche->setEnabled(true);

    //On pourra surcharger ça
    ui->modif_branche->clear();
    ui->modif_branche->addItem("");
    ui->modif_branche->addItems(branches->getBranchesFromCursus(ui->modif_cursus->currentText()));
    ui->modif_branche->setEnabled(true);
}

void mondossier::ajoutUV() {

    if (ui->liste_selection_UV->currentItem() != NULL) {
        ui->liste_uv_suivies->addItem(ui->liste_selection_UV->currentItem()->text());
        ui->liste_notes->addItem(ui->comboBox_note->currentText());
        ui->liste_semestres->addItem(ui->comboBox_semestre->currentText());
        ui->liste_credits->addItem(ui->comboBox_credits->currentText());
        ui->liste_possibilite_uv->addItem(map_pos_uv[ui->comboBox_credits->currentText()]);
    }
}

void mondossier::maj_dossier() {


    QSqlQuery query;

    ui->login->clear();
    ui->nom->clear();
    ui->prenom->clear();
    ui->date_naiss->clear();
    ui->email->clear();
    ui->titre_mesinfos->clear();

    ui->titre_mesinfos->setText("Bienvenue " + c->getPrenom() + " " + c->getNom());
    query = db->execute("SELECT * FROM Etudiant, Dossier WHERE Etudiant.login = '" + c->getLogin() + "' AND Dossier.login_etudiant='" + c->getLogin() + "';");


    while(query.next()) {
        ui->num_dossier->setText(query.value(8).toString());
        ui->login->setText(query.value(0).toString());
        ui->nom->setText(query.value(2).toString());
        ui->prenom->setText(query.value(3).toString());
        ui->date_naiss->setText(query.value(5).toString());
        ui->email->setText(query.value(6).toString());
        ui->filiere->setText(query.value(10).toString());
        ui->cursus->setText(query.value(11).toString());
        ui->branche->setText(query.value(12).toString());
        ui->semestre->setText(query.value(13).toString());
    }
}

void mondossier::sauvegarder_modif(){
    QString cursus=  ui->modif_cursus->currentText();
    QString filiere=  ui->modif_filiere->currentText();
    QString branche=  ui->modif_branche->currentText();
    QString semestre=  ui->modif_semestre->currentText();
    qDebug()<<semestre;

    db->execute("UPDATE Dossier SET nom_filiere='"+ filiere +"', nom_cursus='"+cursus+"', nom_branche='"+branche+"', num_semestre_actuel="+semestre+"  WHERE login_etudiant='"+c->getLogin()+"';");
    db->execute("UPDATE Etudiant SET nom='"+ui->modif_nom->text()+"', prenom='"+ui->modif_prenom->text()+"', date_naissance='"+ui->modif_date_naiss->text()+"', email='"+ui->modif_email->text()+"'  WHERE login='"+c->getLogin()+"';");

    ui->sauvegarder_modif->hide();
    ui->modif_semestre->hide();
    ui->modif_date_naiss->hide();
    ui->modif_email->hide();
    ui->modif_login->hide();
    ui->modif_cursus->hide();
    ui->modif_filiere->hide();
    ui->modif_nom->hide();
    ui->modif_prenom->hide();
    ui->modif_branche->hide();

    ui->modif_info->show();
    this->maj_dossier();
}


void mondossier::modifier_infos() {
    QSqlQuery query;

    ui->modif_filiere->clear();
    ui->modif_filiere->addItems(filieres->getListe_filieres());

    ui->modif_cursus->clear();
    ui->modif_cursus->addItems(cursus->getListe_cursus());

    ui->modif_semestre->clear();

    QStringList stringList;
    stringList.append("1");stringList.append("2"); stringList.append("3");stringList.append("4");stringList.append("5");stringList.append("6");stringList.append("7");stringList.append("8");
    ui->modif_semestre->addItems(stringList);

    query = db->execute("SELECT * FROM Etudiant, Dossier WHERE Etudiant.login = '" + c->getLogin() + "' AND Dossier.login_etudiant='" + c->getLogin() + "';");
    if (query.next()) {
        ui->sauvegarder_modif->show();
        ui->modif_semestre->show();
        ui->modif_date_naiss->show();   ui->modif_date_naiss->setText(query.value(5).toString());
        ui->modif_email->show();        ui->modif_email->setText(query.value(6).toString());
        ui->modif_login->show();        ui->modif_login->setText(query.value(0).toString());
        ui->modif_cursus->show();
        ui->modif_filiere->show();
        ui->modif_nom->show();          ui->modif_nom->setText(query.value(2).toString());
        ui->modif_prenom->show();       ui->modif_prenom->setText(query.value(3).toString());
        ui->modif_branche->show();
    }
    ui->modif_info->hide();
}

void mondossier::sauvegarder_choix(){
    QSqlQuery query;
    //On drop tout les enregistrements pour ce dossier
    db->execute("DELETE FROM choixUv WHERE id_dossier="+this->numerodossier+";");

    for (int i = 0; i < ui->liste_exigences->count(); i++) {
            QString curUv = ui->liste_exigences->item(i)->text();
                db->execute("INSERT INTO choixUv (id_dossier, UV, choix)VALUES ("+this->numerodossier+",'"+curUv+"', 'exigence')");
        }

    for (int i = 0; i < ui->liste_preferences->count(); i++) {
            QString curUv = ui->liste_preferences->item(i)->text();
            db->execute("INSERT INTO choixUv (id_dossier, UV, choix)VALUES ("+this->numerodossier+",'"+curUv+"', 'preference')");
        }

    for (int i = 0; i < ui->liste_rejets->count(); i++) {
            QString curUv = ui->liste_rejets->item(i)->text();
            db->execute("INSERT INTO choixUv (id_dossier, UV, choix)VALUES ("+this->numerodossier+",'"+curUv+"', 'rejet')");
        }
}

void mondossier::sauvegarder_dossier(){

    for (int i = 0; i < ui->liste_uv_suivies->count(); i++) {
            QString curUv = ui->liste_uv_suivies->item(i)->text();
            QString curNote = ui->liste_notes->item(i)->text();
            QString curSem = ui->liste_semestres->item(i)->text();
            QString curposs = ui->liste_possibilite_uv->item(i)->text();
qDebug()<<curUv+curNote+curSem+curposs;
        }
}


void mondossier::ajoutExigence(){
    if (ui->liste_choix_uv->currentItem() != NULL){
        ui->liste_exigences->addItem(ui->liste_choix_uv->currentItem()->text());
        delete ui->liste_choix_uv->currentItem();
    }
}

void mondossier::ajoutPreference(){
    if (ui->liste_choix_uv->currentItem() != NULL){
        ui->liste_preferences->addItem(ui->liste_choix_uv->currentItem()->text());
        delete ui->liste_choix_uv->currentItem();
    }
}

void mondossier::ajoutRejet(){
    if (ui->liste_choix_uv->currentItem() != NULL){
        ui->liste_rejets->addItem(ui->liste_choix_uv->currentItem()->text());
        delete ui->liste_choix_uv->currentItem();
    }
}

void mondossier::supprExigence(){
    if (ui->liste_exigences->currentItem() != NULL){
        ui->liste_choix_uv->addItem(ui->liste_exigences->currentItem()->text());
        delete ui->liste_exigences->currentItem();
    }
}

void mondossier::supprRejet(){
    if (ui->liste_rejets->currentItem() != NULL){
        ui->liste_choix_uv->addItem(ui->liste_rejets->currentItem()->text());
        delete ui->liste_rejets->currentItem();
    }
}

void mondossier::supprPreference(){
    if (ui->liste_preferences->currentItem() != NULL){
        ui->liste_choix_uv->addItem(ui->liste_preferences->currentItem()->text());
        delete ui->liste_preferences->currentItem();
    }
}

mondossier::~mondossier()
{
    delete ui;
}
