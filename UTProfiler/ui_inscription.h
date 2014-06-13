/********************************************************************************
** Form generated from reading UI file 'inscription.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INSCRIPTION_H
#define UI_INSCRIPTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Inscription
{
public:
    QLabel *label_login;
    QLabel *label_nom;
    QLabel *label_prenom;
    QLabel *label_mdp1;
    QLabel *label_mdp2;
    QLabel *label_sexe;
    QLineEdit *input_login;
    QLineEdit *input_nom;
    QLineEdit *input_prenom;
    QLineEdit *input_mdp;
    QLineEdit *input_mdp2;
    QLabel *label_titre;
    QComboBox *comboBox;
    QPushButton *valider;
    QLabel *label_email;
    QLineEdit *input_email;
    QLabel *label_datenaiss;
    QLineEdit *input_date_naiss;
    QComboBox *comboBox_cursus;
    QLabel *label_cursus;
    QComboBox *comboBox_branche;
    QLabel *label_branche;
    QComboBox *comboBox_filiere;
    QLabel *label_filiere;
    QComboBox *comboBox_semestre;
    QLabel *label_semestre;
    QLabel *label;

    void setupUi(QDialog *Inscription)
    {
        if (Inscription->objectName().isEmpty())
            Inscription->setObjectName(QStringLiteral("Inscription"));
        Inscription->resize(400, 500);
        Inscription->setAutoFillBackground(false);
        label_login = new QLabel(Inscription);
        label_login->setObjectName(QStringLiteral("label_login"));
        label_login->setGeometry(QRect(90, 70, 90, 20));
        label_login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_nom = new QLabel(Inscription);
        label_nom->setObjectName(QStringLiteral("label_nom"));
        label_nom->setGeometry(QRect(90, 100, 90, 20));
        label_nom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_prenom = new QLabel(Inscription);
        label_prenom->setObjectName(QStringLiteral("label_prenom"));
        label_prenom->setGeometry(QRect(90, 130, 90, 20));
        label_prenom->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mdp1 = new QLabel(Inscription);
        label_mdp1->setObjectName(QStringLiteral("label_mdp1"));
        label_mdp1->setGeometry(QRect(90, 220, 90, 20));
        label_mdp1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_mdp2 = new QLabel(Inscription);
        label_mdp2->setObjectName(QStringLiteral("label_mdp2"));
        label_mdp2->setGeometry(QRect(90, 250, 90, 20));
        label_mdp2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_sexe = new QLabel(Inscription);
        label_sexe->setObjectName(QStringLiteral("label_sexe"));
        label_sexe->setGeometry(QRect(90, 160, 90, 20));
        label_sexe->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input_login = new QLineEdit(Inscription);
        input_login->setObjectName(QStringLiteral("input_login"));
        input_login->setGeometry(QRect(190, 70, 113, 20));
        input_nom = new QLineEdit(Inscription);
        input_nom->setObjectName(QStringLiteral("input_nom"));
        input_nom->setGeometry(QRect(190, 100, 113, 20));
        input_prenom = new QLineEdit(Inscription);
        input_prenom->setObjectName(QStringLiteral("input_prenom"));
        input_prenom->setGeometry(QRect(190, 130, 113, 20));
        input_mdp = new QLineEdit(Inscription);
        input_mdp->setObjectName(QStringLiteral("input_mdp"));
        input_mdp->setGeometry(QRect(190, 220, 113, 20));
        input_mdp->setEchoMode(QLineEdit::Password);
        input_mdp2 = new QLineEdit(Inscription);
        input_mdp2->setObjectName(QStringLiteral("input_mdp2"));
        input_mdp2->setGeometry(QRect(190, 250, 113, 20));
        input_mdp2->setEchoMode(QLineEdit::Password);
        label_titre = new QLabel(Inscription);
        label_titre->setObjectName(QStringLiteral("label_titre"));
        label_titre->setGeometry(QRect(150, 20, 131, 31));
        QFont font;
        font.setPointSize(18);
        label_titre->setFont(font);
        comboBox = new QComboBox(Inscription);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(190, 160, 111, 22));
        valider = new QPushButton(Inscription);
        valider->setObjectName(QStringLiteral("valider"));
        valider->setGeometry(QRect(170, 440, 91, 31));
        label_email = new QLabel(Inscription);
        label_email->setObjectName(QStringLiteral("label_email"));
        label_email->setGeometry(QRect(90, 280, 90, 20));
        label_email->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input_email = new QLineEdit(Inscription);
        input_email->setObjectName(QStringLiteral("input_email"));
        input_email->setGeometry(QRect(190, 280, 113, 20));
        input_email->setEchoMode(QLineEdit::Normal);
        label_datenaiss = new QLabel(Inscription);
        label_datenaiss->setObjectName(QStringLiteral("label_datenaiss"));
        label_datenaiss->setGeometry(QRect(59, 190, 121, 20));
        label_datenaiss->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        input_date_naiss = new QLineEdit(Inscription);
        input_date_naiss->setObjectName(QStringLiteral("input_date_naiss"));
        input_date_naiss->setGeometry(QRect(190, 190, 113, 20));
        comboBox_cursus = new QComboBox(Inscription);
        comboBox_cursus->setObjectName(QStringLiteral("comboBox_cursus"));
        comboBox_cursus->setGeometry(QRect(190, 310, 111, 22));
        label_cursus = new QLabel(Inscription);
        label_cursus->setObjectName(QStringLiteral("label_cursus"));
        label_cursus->setGeometry(QRect(90, 310, 90, 20));
        label_cursus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_branche = new QComboBox(Inscription);
        comboBox_branche->setObjectName(QStringLiteral("comboBox_branche"));
        comboBox_branche->setGeometry(QRect(190, 340, 111, 22));
        label_branche = new QLabel(Inscription);
        label_branche->setObjectName(QStringLiteral("label_branche"));
        label_branche->setGeometry(QRect(90, 340, 90, 20));
        label_branche->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_filiere = new QComboBox(Inscription);
        comboBox_filiere->setObjectName(QStringLiteral("comboBox_filiere"));
        comboBox_filiere->setGeometry(QRect(190, 370, 111, 22));
        label_filiere = new QLabel(Inscription);
        label_filiere->setObjectName(QStringLiteral("label_filiere"));
        label_filiere->setGeometry(QRect(90, 370, 90, 20));
        label_filiere->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        comboBox_semestre = new QComboBox(Inscription);
        comboBox_semestre->setObjectName(QStringLiteral("comboBox_semestre"));
        comboBox_semestre->setGeometry(QRect(190, 400, 111, 22));
        label_semestre = new QLabel(Inscription);
        label_semestre->setObjectName(QStringLiteral("label_semestre"));
        label_semestre->setGeometry(QRect(79, 400, 101, 20));
        label_semestre->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label = new QLabel(Inscription);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(0, 0, 401, 501));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/fond_inscription.png")));
        label->raise();
        label_login->raise();
        label_nom->raise();
        label_prenom->raise();
        label_mdp1->raise();
        label_mdp2->raise();
        label_sexe->raise();
        input_login->raise();
        input_nom->raise();
        input_prenom->raise();
        input_mdp->raise();
        input_mdp2->raise();
        label_titre->raise();
        comboBox->raise();
        valider->raise();
        label_email->raise();
        input_email->raise();
        label_datenaiss->raise();
        input_date_naiss->raise();
        comboBox_cursus->raise();
        label_cursus->raise();
        comboBox_branche->raise();
        label_branche->raise();
        comboBox_filiere->raise();
        label_filiere->raise();
        comboBox_semestre->raise();
        label_semestre->raise();

        retranslateUi(Inscription);

        QMetaObject::connectSlotsByName(Inscription);
    } // setupUi

    void retranslateUi(QDialog *Inscription)
    {
        Inscription->setWindowTitle(QApplication::translate("Inscription", "Dialog", 0));
        label_login->setText(QApplication::translate("Inscription", "Login", 0));
        label_nom->setText(QApplication::translate("Inscription", "Nom", 0));
        label_prenom->setText(QApplication::translate("Inscription", "Pr\303\251nom", 0));
        label_mdp1->setText(QApplication::translate("Inscription", "Mot de passe", 0));
        label_mdp2->setText(QApplication::translate("Inscription", "Confirmation", 0));
        label_sexe->setText(QApplication::translate("Inscription", "Sexe", 0));
        label_titre->setText(QApplication::translate("Inscription", "Inscription", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("Inscription", "Homme", 0)
         << QApplication::translate("Inscription", "Femme", 0)
        );
        valider->setText(QApplication::translate("Inscription", "Valider", 0));
        label_email->setText(QApplication::translate("Inscription", "Email", 0));
        label_datenaiss->setText(QApplication::translate("Inscription", "Date de naissance", 0));
        label_cursus->setText(QApplication::translate("Inscription", "Cursus", 0));
        label_branche->setText(QApplication::translate("Inscription", "Branche", 0));
        label_filiere->setText(QApplication::translate("Inscription", "Filiere", 0));
        comboBox_semestre->clear();
        comboBox_semestre->insertItems(0, QStringList()
         << QApplication::translate("Inscription", "1", 0)
         << QApplication::translate("Inscription", "2", 0)
         << QApplication::translate("Inscription", "3", 0)
         << QApplication::translate("Inscription", "4", 0)
         << QApplication::translate("Inscription", "5", 0)
         << QApplication::translate("Inscription", "6", 0)
         << QApplication::translate("Inscription", "7", 0)
         << QApplication::translate("Inscription", "8", 0)
        );
        label_semestre->setText(QApplication::translate("Inscription", "Semestre Actuel", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Inscription: public Ui_Inscription {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INSCRIPTION_H
