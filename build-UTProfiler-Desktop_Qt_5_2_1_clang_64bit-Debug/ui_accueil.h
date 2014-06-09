/********************************************************************************
** Form generated from reading UI file 'accueil.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACCUEIL_H
#define UI_ACCUEIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Accueil
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *Connexion;
    QLabel *label_2;
    QPushButton *inscription;
    QLineEdit *input_mdp;
    QLineEdit *input_login;
    QLabel *label_mdp;
    QLabel *label_login;
    QPushButton *connexion;
    QLabel *label_erreur;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Accueil)
    {
        if (Accueil->objectName().isEmpty())
            Accueil->setObjectName(QStringLiteral("Accueil"));
        Accueil->resize(850, 427);
        centralwidget = new QWidget(Accueil);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 861, 431));
        Connexion = new QWidget();
        Connexion->setObjectName(QStringLiteral("Connexion"));
        label_2 = new QLabel(Connexion);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(0, 0, 881, 371));
        label_2->setPixmap(QPixmap(QString::fromUtf8(":/images/utc.jpg")));
        inscription = new QPushButton(Connexion);
        inscription->setObjectName(QStringLiteral("inscription"));
        inscription->setGeometry(QRect(670, 190, 91, 23));
        input_mdp = new QLineEdit(Connexion);
        input_mdp->setObjectName(QStringLiteral("input_mdp"));
        input_mdp->setGeometry(QRect(660, 150, 113, 20));
        input_mdp->setEchoMode(QLineEdit::Password);
        input_login = new QLineEdit(Connexion);
        input_login->setObjectName(QStringLiteral("input_login"));
        input_login->setGeometry(QRect(660, 120, 113, 20));
        label_mdp = new QLabel(Connexion);
        label_mdp->setObjectName(QStringLiteral("label_mdp"));
        label_mdp->setGeometry(QRect(560, 150, 91, 21));
        label_login = new QLabel(Connexion);
        label_login->setObjectName(QStringLiteral("label_login"));
        label_login->setGeometry(QRect(560, 120, 91, 21));
        connexion = new QPushButton(Connexion);
        connexion->setObjectName(QStringLiteral("connexion"));
        connexion->setGeometry(QRect(574, 190, 91, 23));
        label_erreur = new QLabel(Connexion);
        label_erreur->setObjectName(QStringLiteral("label_erreur"));
        label_erreur->setGeometry(QRect(540, 230, 281, 81));
        QFont font;
        font.setPointSize(10);
        font.setBold(false);
        font.setWeight(50);
        label_erreur->setFont(font);
        label = new QLabel(Connexion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(320, 10, 191, 51));
        QFont font1;
        font1.setPointSize(16);
        label->setFont(font1);
        tabWidget->addTab(Connexion, QString());
        label_2->raise();
        inscription->raise();
        input_mdp->raise();
        input_login->raise();
        label_mdp->raise();
        label_login->raise();
        connexion->raise();
        label->raise();
        label_erreur->raise();
        Accueil->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Accueil);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 850, 22));
        Accueil->setMenuBar(menubar);
        statusbar = new QStatusBar(Accueil);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        Accueil->setStatusBar(statusbar);

        retranslateUi(Accueil);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Accueil);
    } // setupUi

    void retranslateUi(QMainWindow *Accueil)
    {
        Accueil->setWindowTitle(QApplication::translate("Accueil", "MainWindow", 0));
        label_2->setText(QString());
        inscription->setText(QApplication::translate("Accueil", "Inscription", 0));
        label_mdp->setText(QApplication::translate("Accueil", "Mot de passe :", 0));
        label_login->setText(QApplication::translate("Accueil", "Login :", 0));
        connexion->setText(QApplication::translate("Accueil", "Connexion", 0));
        label_erreur->setText(QString());
        label->setText(QApplication::translate("Accueil", "<html><head/><body><p><span style=\" font-size:20pt;\">UT Profiler</span></p></body></html>", 0));
        tabWidget->setTabText(tabWidget->indexOf(Connexion), QApplication::translate("Accueil", "Connexion", 0));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
