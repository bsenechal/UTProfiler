/********************************************************************************
** Form generated from reading UI file 'mondossier.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONDOSSIER_H
#define UI_MONDOSSIER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mondossier
{
public:
    QTabWidget *onglets_dossier;
    QWidget *mes_infos;
    QLabel *label_Login;
    QLabel *label_nom;
    QLabel *label_prenom;
    QLabel *label_date_naiss;
    QLabel *label_filiere;
    QLabel *label_cursus;
    QLabel *label_branche;
    QLabel *label_sem_actu;
    QLabel *login;
    QLabel *nom;
    QLabel *prenom;
    QLabel *date_naiss;
    QLabel *filiere;
    QLabel *cursus;
    QLabel *branche;
    QLabel *semestre;
    QLabel *label_num_dossier;
    QLabel *num_dossier;
    QLabel *email;
    QLabel *label_email;
    QLabel *titre_mesinfos;
    QLabel *fond;
    QPushButton *sauvegarder_modif;
    QLineEdit *modif_login;
    QLineEdit *modif_nom;
    QLineEdit *modif_date_naiss;
    QLineEdit *modif_prenom;
    QLineEdit *modif_email;
    QPushButton *modif_info;
    QComboBox *modif_filiere;
    QComboBox *modif_cursus;
    QComboBox *modif_branche;
    QComboBox *modif_semestre;
    QWidget *tab_info_perso;
    QLabel *label_cursus_2;
    QComboBox *comboBox_cursus;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QComboBox *comboBox_note;
    QLabel *label_5;
    QFrame *line;
    QPushButton *ajout_uv;
    QListWidget *liste_selection_UV;
    QListWidget *liste_uv_suivies;
    QListWidget *liste_notes;
    QComboBox *comboBox_filiere;
    QLabel *label_filiere_2;
    QLabel *label_6;
    QComboBox *comboBox_semestre;
    QListWidget *liste_semestres;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *fond_2;
    QComboBox *comboBox_branche;
    QLabel *label_branche_2;
    QComboBox *comboBox_credits;
    QLabel *label_9;
    QListWidget *liste_credits;
    QLabel *label_18;
    QPushButton *sauvegarder_dossier;
    QListWidget *liste_possibilite_uv;
    QPushButton *suppri_UV_suivies;
    QWidget *choix;
    QPushButton *add_exigence;
    QLabel *label_titre_choix;
    QListWidget *liste_choix_uv;
    QListWidget *liste_exigences;
    QLabel *label_selection_uv;
    QListWidget *liste_preferences;
    QListWidget *liste_rejets;
    QLabel *label_exigences;
    QLabel *label_preferences;
    QLabel *label_rejets;
    QPushButton *sauvegarder_choix;
    QPushButton *add_preference;
    QPushButton *add_rejet;
    QPushButton *suppr_exigence;
    QPushButton *suppr_preference;
    QPushButton *suppr_rejet;
    QLabel *fond_3;
    QPushButton *suggestion_uv;
    QLabel *label;

    void setupUi(QDialog *mondossier)
    {
        if (mondossier->objectName().isEmpty())
            mondossier->setObjectName(QStringLiteral("mondossier"));
        mondossier->resize(893, 547);
        onglets_dossier = new QTabWidget(mondossier);
        onglets_dossier->setObjectName(QStringLiteral("onglets_dossier"));
        onglets_dossier->setGeometry(QRect(0, 40, 901, 511));
        mes_infos = new QWidget();
        mes_infos->setObjectName(QStringLiteral("mes_infos"));
        label_Login = new QLabel(mes_infos);
        label_Login->setObjectName(QStringLiteral("label_Login"));
        label_Login->setGeometry(QRect(60, 150, 150, 25));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_Login->setFont(font);
        label_Login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_nom = new QLabel(mes_infos);
        label_nom->setObjectName(QStringLiteral("label_nom"));
        label_nom->setGeometry(QRect(60, 200, 150, 25));
        label_nom->setFont(font);
        label_nom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_prenom = new QLabel(mes_infos);
        label_prenom->setObjectName(QStringLiteral("label_prenom"));
        label_prenom->setGeometry(QRect(60, 250, 150, 25));
        label_prenom->setFont(font);
        label_prenom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_date_naiss = new QLabel(mes_infos);
        label_date_naiss->setObjectName(QStringLiteral("label_date_naiss"));
        label_date_naiss->setGeometry(QRect(60, 300, 150, 25));
        label_date_naiss->setFont(font);
        label_date_naiss->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_filiere = new QLabel(mes_infos);
        label_filiere->setObjectName(QStringLiteral("label_filiere"));
        label_filiere->setGeometry(QRect(440, 150, 150, 25));
        label_filiere->setFont(font);
        label_filiere->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_cursus = new QLabel(mes_infos);
        label_cursus->setObjectName(QStringLiteral("label_cursus"));
        label_cursus->setGeometry(QRect(440, 200, 150, 25));
        label_cursus->setFont(font);
        label_cursus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_branche = new QLabel(mes_infos);
        label_branche->setObjectName(QStringLiteral("label_branche"));
        label_branche->setGeometry(QRect(440, 250, 150, 25));
        label_branche->setFont(font);
        label_branche->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_sem_actu = new QLabel(mes_infos);
        label_sem_actu->setObjectName(QStringLiteral("label_sem_actu"));
        label_sem_actu->setGeometry(QRect(440, 300, 150, 25));
        label_sem_actu->setFont(font);
        label_sem_actu->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        login = new QLabel(mes_infos);
        login->setObjectName(QStringLiteral("login"));
        login->setGeometry(QRect(240, 150, 200, 25));
        QFont font1;
        font1.setPointSize(10);
        login->setFont(font1);
        nom = new QLabel(mes_infos);
        nom->setObjectName(QStringLiteral("nom"));
        nom->setGeometry(QRect(240, 200, 200, 25));
        nom->setFont(font1);
        prenom = new QLabel(mes_infos);
        prenom->setObjectName(QStringLiteral("prenom"));
        prenom->setGeometry(QRect(240, 250, 200, 25));
        prenom->setFont(font1);
        date_naiss = new QLabel(mes_infos);
        date_naiss->setObjectName(QStringLiteral("date_naiss"));
        date_naiss->setGeometry(QRect(240, 300, 200, 25));
        date_naiss->setFont(font1);
        filiere = new QLabel(mes_infos);
        filiere->setObjectName(QStringLiteral("filiere"));
        filiere->setGeometry(QRect(620, 150, 200, 25));
        filiere->setFont(font1);
        cursus = new QLabel(mes_infos);
        cursus->setObjectName(QStringLiteral("cursus"));
        cursus->setGeometry(QRect(620, 200, 200, 25));
        cursus->setFont(font1);
        branche = new QLabel(mes_infos);
        branche->setObjectName(QStringLiteral("branche"));
        branche->setGeometry(QRect(620, 250, 200, 25));
        branche->setFont(font1);
        semestre = new QLabel(mes_infos);
        semestre->setObjectName(QStringLiteral("semestre"));
        semestre->setGeometry(QRect(620, 300, 200, 25));
        semestre->setFont(font1);
        label_num_dossier = new QLabel(mes_infos);
        label_num_dossier->setObjectName(QStringLiteral("label_num_dossier"));
        label_num_dossier->setGeometry(QRect(60, 100, 150, 25));
        label_num_dossier->setFont(font);
        label_num_dossier->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        num_dossier = new QLabel(mes_infos);
        num_dossier->setObjectName(QStringLiteral("num_dossier"));
        num_dossier->setGeometry(QRect(240, 100, 200, 25));
        num_dossier->setFont(font1);
        email = new QLabel(mes_infos);
        email->setObjectName(QStringLiteral("email"));
        email->setGeometry(QRect(620, 100, 200, 25));
        email->setFont(font1);
        label_email = new QLabel(mes_infos);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setGeometry(QRect(440, 100, 150, 25));
        label_email->setFont(font);
        label_email->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        titre_mesinfos = new QLabel(mes_infos);
        titre_mesinfos->setObjectName(QStringLiteral("titre_mesinfos"));
        titre_mesinfos->setGeometry(QRect(20, 20, 751, 41));
        QFont font2;
        font2.setPointSize(18);
        titre_mesinfos->setFont(font2);
        fond = new QLabel(mes_infos);
        fond->setObjectName(QStringLiteral("fond"));
        fond->setGeometry(QRect(0, 0, 891, 491));
        fond->setPixmap(QPixmap(QString::fromUtf8(":/images/fond_pg.png")));
        sauvegarder_modif = new QPushButton(mes_infos);
        sauvegarder_modif->setObjectName(QStringLiteral("sauvegarder_modif"));
        sauvegarder_modif->setGeometry(QRect(130, 400, 211, 31));
        modif_login = new QLineEdit(mes_infos);
        modif_login->setObjectName(QStringLiteral("modif_login"));
        modif_login->setEnabled(true);
        modif_login->setGeometry(QRect(240, 150, 200, 30));
        modif_nom = new QLineEdit(mes_infos);
        modif_nom->setObjectName(QStringLiteral("modif_nom"));
        modif_nom->setEnabled(true);
        modif_nom->setGeometry(QRect(240, 200, 200, 30));
        modif_date_naiss = new QLineEdit(mes_infos);
        modif_date_naiss->setObjectName(QStringLiteral("modif_date_naiss"));
        modif_date_naiss->setEnabled(true);
        modif_date_naiss->setGeometry(QRect(240, 300, 200, 30));
        modif_prenom = new QLineEdit(mes_infos);
        modif_prenom->setObjectName(QStringLiteral("modif_prenom"));
        modif_prenom->setEnabled(true);
        modif_prenom->setGeometry(QRect(240, 250, 200, 30));
        modif_email = new QLineEdit(mes_infos);
        modif_email->setObjectName(QStringLiteral("modif_email"));
        modif_email->setEnabled(true);
        modif_email->setGeometry(QRect(620, 100, 200, 30));
        modif_info = new QPushButton(mes_infos);
        modif_info->setObjectName(QStringLiteral("modif_info"));
        modif_info->setGeometry(QRect(130, 400, 211, 31));
        modif_filiere = new QComboBox(mes_infos);
        modif_filiere->setObjectName(QStringLiteral("modif_filiere"));
        modif_filiere->setGeometry(QRect(620, 150, 200, 30));
        modif_cursus = new QComboBox(mes_infos);
        modif_cursus->setObjectName(QStringLiteral("modif_cursus"));
        modif_cursus->setGeometry(QRect(620, 200, 200, 30));
        modif_branche = new QComboBox(mes_infos);
        modif_branche->setObjectName(QStringLiteral("modif_branche"));
        modif_branche->setGeometry(QRect(620, 250, 200, 30));
        modif_semestre = new QComboBox(mes_infos);
        modif_semestre->setObjectName(QStringLiteral("modif_semestre"));
        modif_semestre->setGeometry(QRect(620, 300, 200, 30));
        onglets_dossier->addTab(mes_infos, QString());
        fond->raise();
        label_Login->raise();
        label_nom->raise();
        label_prenom->raise();
        label_date_naiss->raise();
        label_filiere->raise();
        label_cursus->raise();
        label_branche->raise();
        label_sem_actu->raise();
        login->raise();
        nom->raise();
        prenom->raise();
        date_naiss->raise();
        filiere->raise();
        cursus->raise();
        branche->raise();
        semestre->raise();
        label_num_dossier->raise();
        num_dossier->raise();
        email->raise();
        label_email->raise();
        titre_mesinfos->raise();
        sauvegarder_modif->raise();
        modif_login->raise();
        modif_nom->raise();
        modif_date_naiss->raise();
        modif_prenom->raise();
        modif_email->raise();
        modif_info->raise();
        modif_filiere->raise();
        modif_cursus->raise();
        modif_branche->raise();
        modif_semestre->raise();
        tab_info_perso = new QWidget();
        tab_info_perso->setObjectName(QStringLiteral("tab_info_perso"));
        label_cursus_2 = new QLabel(tab_info_perso);
        label_cursus_2->setObjectName(QStringLiteral("label_cursus_2"));
        label_cursus_2->setGeometry(QRect(20, 90, 46, 22));
        comboBox_cursus = new QComboBox(tab_info_perso);
        comboBox_cursus->setObjectName(QStringLiteral("comboBox_cursus"));
        comboBox_cursus->setGeometry(QRect(60, 90, 69, 22));
        label_2 = new QLabel(tab_info_perso);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(430, 90, 81, 16));
        label_3 = new QLabel(tab_info_perso);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(540, 90, 51, 16));
        label_4 = new QLabel(tab_info_perso);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(80, 140, 151, 16));
        comboBox_note = new QComboBox(tab_info_perso);
        comboBox_note->setObjectName(QStringLiteral("comboBox_note"));
        comboBox_note->setGeometry(QRect(240, 190, 101, 22));
        label_5 = new QLabel(tab_info_perso);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(270, 170, 46, 13));
        line = new QFrame(tab_info_perso);
        line->setObjectName(QStringLiteral("line"));
        line->setGeometry(QRect(410, 80, 20, 291));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        ajout_uv = new QPushButton(tab_info_perso);
        ajout_uv->setObjectName(QStringLiteral("ajout_uv"));
        ajout_uv->setGeometry(QRect(240, 350, 141, 31));
        liste_selection_UV = new QListWidget(tab_info_perso);
        liste_selection_UV->setObjectName(QStringLiteral("liste_selection_UV"));
        liste_selection_UV->setGeometry(QRect(80, 160, 111, 211));
        liste_uv_suivies = new QListWidget(tab_info_perso);
        liste_uv_suivies->setObjectName(QStringLiteral("liste_uv_suivies"));
        liste_uv_suivies->setGeometry(QRect(430, 120, 91, 201));
        liste_notes = new QListWidget(tab_info_perso);
        liste_notes->setObjectName(QStringLiteral("liste_notes"));
        liste_notes->setGeometry(QRect(530, 120, 91, 201));
        comboBox_filiere = new QComboBox(tab_info_perso);
        comboBox_filiere->setObjectName(QStringLiteral("comboBox_filiere"));
        comboBox_filiere->setEnabled(false);
        comboBox_filiere->setGeometry(QRect(340, 90, 69, 22));
        label_filiere_2 = new QLabel(tab_info_perso);
        label_filiere_2->setObjectName(QStringLiteral("label_filiere_2"));
        label_filiere_2->setGeometry(QRect(300, 90, 46, 22));
        label_6 = new QLabel(tab_info_perso);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(270, 230, 81, 16));
        comboBox_semestre = new QComboBox(tab_info_perso);
        comboBox_semestre->setObjectName(QStringLiteral("comboBox_semestre"));
        comboBox_semestre->setGeometry(QRect(240, 250, 101, 22));
        liste_semestres = new QListWidget(tab_info_perso);
        liste_semestres->setObjectName(QStringLiteral("liste_semestres"));
        liste_semestres->setGeometry(QRect(630, 120, 91, 201));
        label_7 = new QLabel(tab_info_perso);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(640, 90, 71, 16));
        label_8 = new QLabel(tab_info_perso);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 20, 191, 31));
        QFont font3;
        font3.setPointSize(16);
        label_8->setFont(font3);
        fond_2 = new QLabel(tab_info_perso);
        fond_2->setObjectName(QStringLiteral("fond_2"));
        fond_2->setGeometry(QRect(0, 0, 891, 491));
        fond_2->setPixmap(QPixmap(QString::fromUtf8(":/images/fond_pg.png")));
        comboBox_branche = new QComboBox(tab_info_perso);
        comboBox_branche->setObjectName(QStringLiteral("comboBox_branche"));
        comboBox_branche->setEnabled(false);
        comboBox_branche->setGeometry(QRect(210, 90, 69, 22));
        label_branche_2 = new QLabel(tab_info_perso);
        label_branche_2->setObjectName(QStringLiteral("label_branche_2"));
        label_branche_2->setGeometry(QRect(155, 90, 51, 22));
        comboBox_credits = new QComboBox(tab_info_perso);
        comboBox_credits->setObjectName(QStringLiteral("comboBox_credits"));
        comboBox_credits->setGeometry(QRect(240, 310, 131, 22));
        label_9 = new QLabel(tab_info_perso);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(270, 290, 81, 16));
        liste_credits = new QListWidget(tab_info_perso);
        liste_credits->setObjectName(QStringLiteral("liste_credits"));
        liste_credits->setGeometry(QRect(730, 120, 91, 201));
        label_18 = new QLabel(tab_info_perso);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(740, 90, 71, 16));
        sauvegarder_dossier = new QPushButton(tab_info_perso);
        sauvegarder_dossier->setObjectName(QStringLiteral("sauvegarder_dossier"));
        sauvegarder_dossier->setGeometry(QRect(750, 350, 141, 31));
        liste_possibilite_uv = new QListWidget(tab_info_perso);
        liste_possibilite_uv->setObjectName(QStringLiteral("liste_possibilite_uv"));
        liste_possibilite_uv->setGeometry(QRect(790, 10, 91, 71));
        suppri_UV_suivies = new QPushButton(tab_info_perso);
        suppri_UV_suivies->setObjectName(QStringLiteral("suppri_UV_suivies"));
        suppri_UV_suivies->setGeometry(QRect(830, 120, 31, 21));
        onglets_dossier->addTab(tab_info_perso, QString());
        fond_2->raise();
        label_cursus_2->raise();
        comboBox_cursus->raise();
        label_2->raise();
        label_3->raise();
        label_4->raise();
        comboBox_note->raise();
        label_5->raise();
        line->raise();
        ajout_uv->raise();
        liste_selection_UV->raise();
        liste_uv_suivies->raise();
        liste_notes->raise();
        comboBox_filiere->raise();
        label_filiere_2->raise();
        label_6->raise();
        comboBox_semestre->raise();
        liste_semestres->raise();
        label_7->raise();
        label_8->raise();
        comboBox_branche->raise();
        label_branche_2->raise();
        comboBox_credits->raise();
        label_9->raise();
        liste_credits->raise();
        label_18->raise();
        sauvegarder_dossier->raise();
        liste_possibilite_uv->raise();
        suppri_UV_suivies->raise();
        choix = new QWidget();
        choix->setObjectName(QStringLiteral("choix"));
        add_exigence = new QPushButton(choix);
        add_exigence->setObjectName(QStringLiteral("add_exigence"));
        add_exigence->setGeometry(QRect(410, 90, 51, 41));
        label_titre_choix = new QLabel(choix);
        label_titre_choix->setObjectName(QStringLiteral("label_titre_choix"));
        label_titre_choix->setGeometry(QRect(30, 20, 131, 31));
        label_titre_choix->setFont(font3);
        liste_choix_uv = new QListWidget(choix);
        liste_choix_uv->setObjectName(QStringLiteral("liste_choix_uv"));
        liste_choix_uv->setGeometry(QRect(210, 50, 151, 321));
        liste_exigences = new QListWidget(choix);
        liste_exigences->setObjectName(QStringLiteral("liste_exigences"));
        liste_exigences->setGeometry(QRect(500, 70, 151, 81));
        label_selection_uv = new QLabel(choix);
        label_selection_uv->setObjectName(QStringLiteral("label_selection_uv"));
        label_selection_uv->setGeometry(QRect(210, 30, 151, 16));
        liste_preferences = new QListWidget(choix);
        liste_preferences->setObjectName(QStringLiteral("liste_preferences"));
        liste_preferences->setGeometry(QRect(500, 180, 151, 81));
        liste_rejets = new QListWidget(choix);
        liste_rejets->setObjectName(QStringLiteral("liste_rejets"));
        liste_rejets->setGeometry(QRect(500, 290, 151, 81));
        label_exigences = new QLabel(choix);
        label_exigences->setObjectName(QStringLiteral("label_exigences"));
        label_exigences->setGeometry(QRect(500, 50, 151, 16));
        label_preferences = new QLabel(choix);
        label_preferences->setObjectName(QStringLiteral("label_preferences"));
        label_preferences->setGeometry(QRect(500, 160, 151, 16));
        label_rejets = new QLabel(choix);
        label_rejets->setObjectName(QStringLiteral("label_rejets"));
        label_rejets->setGeometry(QRect(500, 270, 151, 16));
        sauvegarder_choix = new QPushButton(choix);
        sauvegarder_choix->setObjectName(QStringLiteral("sauvegarder_choix"));
        sauvegarder_choix->setGeometry(QRect(10, 170, 181, 61));
        add_preference = new QPushButton(choix);
        add_preference->setObjectName(QStringLiteral("add_preference"));
        add_preference->setGeometry(QRect(410, 200, 51, 41));
        add_rejet = new QPushButton(choix);
        add_rejet->setObjectName(QStringLiteral("add_rejet"));
        add_rejet->setGeometry(QRect(410, 310, 51, 41));
        suppr_exigence = new QPushButton(choix);
        suppr_exigence->setObjectName(QStringLiteral("suppr_exigence"));
        suppr_exigence->setGeometry(QRect(650, 70, 31, 21));
        suppr_preference = new QPushButton(choix);
        suppr_preference->setObjectName(QStringLiteral("suppr_preference"));
        suppr_preference->setGeometry(QRect(650, 180, 31, 21));
        suppr_rejet = new QPushButton(choix);
        suppr_rejet->setObjectName(QStringLiteral("suppr_rejet"));
        suppr_rejet->setGeometry(QRect(650, 290, 31, 21));
        fond_3 = new QLabel(choix);
        fond_3->setObjectName(QStringLiteral("fond_3"));
        fond_3->setGeometry(QRect(0, 0, 891, 491));
        fond_3->setPixmap(QPixmap(QString::fromUtf8(":/images/fond_pg.png")));
        suggestion_uv = new QPushButton(choix);
        suggestion_uv->setObjectName(QStringLiteral("suggestion_uv"));
        suggestion_uv->setGeometry(QRect(200, 400, 271, 61));
        onglets_dossier->addTab(choix, QString());
        fond_3->raise();
        add_exigence->raise();
        label_titre_choix->raise();
        liste_choix_uv->raise();
        liste_exigences->raise();
        label_selection_uv->raise();
        liste_preferences->raise();
        liste_rejets->raise();
        label_exigences->raise();
        label_preferences->raise();
        label_rejets->raise();
        sauvegarder_choix->raise();
        add_preference->raise();
        add_rejet->raise();
        suppr_exigence->raise();
        suppr_preference->raise();
        suppr_rejet->raise();
        suggestion_uv->raise();
        label = new QLabel(mondossier);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 911, 61));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/bandeau_utc.jpg")));
        label->raise();
        onglets_dossier->raise();

        retranslateUi(mondossier);

        onglets_dossier->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(mondossier);
    } // setupUi

    void retranslateUi(QDialog *mondossier)
    {
        mondossier->setWindowTitle(QApplication::translate("mondossier", "Dialog", 0));
        label_Login->setText(QApplication::translate("mondossier", "Login", 0));
        label_nom->setText(QApplication::translate("mondossier", "Nom", 0));
        label_prenom->setText(QApplication::translate("mondossier", "Prenom", 0));
        label_date_naiss->setText(QApplication::translate("mondossier", "Date de Naissance", 0));
        label_filiere->setText(QApplication::translate("mondossier", "Filiere", 0));
        label_cursus->setText(QApplication::translate("mondossier", "Cursus", 0));
        label_branche->setText(QApplication::translate("mondossier", "Branche", 0));
        label_sem_actu->setText(QApplication::translate("mondossier", "Semestre", 0));
        login->setText(QString());
        nom->setText(QString());
        prenom->setText(QString());
        date_naiss->setText(QString());
        filiere->setText(QString());
        cursus->setText(QString());
        branche->setText(QString());
        semestre->setText(QString());
        label_num_dossier->setText(QApplication::translate("mondossier", "Num\303\251ro de dossier", 0));
        num_dossier->setText(QString());
        email->setText(QString());
        label_email->setText(QApplication::translate("mondossier", "Email", 0));
        titre_mesinfos->setText(QString());
        fond->setText(QString());
        sauvegarder_modif->setText(QApplication::translate("mondossier", "Sauvegarder les modifications", 0));
        modif_info->setText(QApplication::translate("mondossier", "Modifier mes informations", 0));
        onglets_dossier->setTabText(onglets_dossier->indexOf(mes_infos), QApplication::translate("mondossier", "Mes Informations", 0));
        label_cursus_2->setText(QApplication::translate("mondossier", "Cursus", 0));
        label_2->setText(QApplication::translate("mondossier", "UV Suivies", 0));
        label_3->setText(QApplication::translate("mondossier", "Notes", 0));
        label_4->setText(QApplication::translate("mondossier", "Selectionnez une UV", 0));
        label_5->setText(QApplication::translate("mondossier", "Note", 0));
        ajout_uv->setText(QApplication::translate("mondossier", "Ajouter une UV", 0));
        label_filiere_2->setText(QApplication::translate("mondossier", "Filiere", 0));
        label_6->setText(QApplication::translate("mondossier", "Semestre", 0));
        label_7->setText(QApplication::translate("mondossier", "Semestres", 0));
        label_8->setText(QApplication::translate("mondossier", "Nouveau Dossier", 0));
        fond_2->setText(QString());
        label_branche_2->setText(QApplication::translate("mondossier", "Branche", 0));
        label_9->setText(QApplication::translate("mondossier", "Credits", 0));
        label_18->setText(QApplication::translate("mondossier", "Credits", 0));
        sauvegarder_dossier->setText(QApplication::translate("mondossier", "Sauvegarder", 0));
        suppri_UV_suivies->setText(QApplication::translate("mondossier", "X", 0));
        onglets_dossier->setTabText(onglets_dossier->indexOf(tab_info_perso), QApplication::translate("mondossier", "Saisir Dossier", 0));
        add_exigence->setText(QApplication::translate("mondossier", ">", 0));
        label_titre_choix->setText(QApplication::translate("mondossier", "Mes Choix", 0));
        label_selection_uv->setText(QApplication::translate("mondossier", "Selectionnez une UV", 0));
        label_exigences->setText(QApplication::translate("mondossier", "Mes exigences", 0));
        label_preferences->setText(QApplication::translate("mondossier", "Mes pr\303\251f\303\251rences", 0));
        label_rejets->setText(QApplication::translate("mondossier", "Mes rejets", 0));
        sauvegarder_choix->setText(QApplication::translate("mondossier", "Sauvegarder mes choix", 0));
        add_preference->setText(QApplication::translate("mondossier", ">", 0));
        add_rejet->setText(QApplication::translate("mondossier", ">", 0));
        suppr_exigence->setText(QApplication::translate("mondossier", "X", 0));
        suppr_preference->setText(QApplication::translate("mondossier", "X", 0));
        suppr_rejet->setText(QApplication::translate("mondossier", "X", 0));
        fond_3->setText(QString());
        suggestion_uv->setText(QApplication::translate("mondossier", "G\303\251n\303\251rer une suggestion d'UVs", 0));
        onglets_dossier->setTabText(onglets_dossier->indexOf(choix), QApplication::translate("mondossier", "Mes Choix", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mondossier: public Ui_mondossier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONDOSSIER_H
