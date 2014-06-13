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
        Accueil->resize(865, 519);
        centralwidget = new QWidget(Accueil);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 861, 500));
        Connexion = new QWidget();
        Connexion->setObjectName(QStringLiteral("Connexion"));
        inscription = new QPushButton(Connexion);
        inscription->setObjectName(QStringLiteral("inscription"));
        inscription->setGeometry(QRect(710, 230, 101, 41));
        input_mdp = new QLineEdit(Connexion);
        input_mdp->setObjectName(QStringLiteral("input_mdp"));
        input_mdp->setGeometry(QRect(650, 190, 125, 22));
        input_mdp->setEchoMode(QLineEdit::Password);
        input_login = new QLineEdit(Connexion);
        input_login->setObjectName(QStringLiteral("input_login"));
        input_login->setGeometry(QRect(650, 150, 125, 22));
        label_mdp = new QLabel(Connexion);
        label_mdp->setObjectName(QStringLiteral("label_mdp"));
        label_mdp->setGeometry(QRect(480, 190, 150, 25));
        QFont font;
        font.setPointSize(10);
        label_mdp->setFont(font);
        label_mdp->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_login = new QLabel(Connexion);
        label_login->setObjectName(QStringLiteral("label_login"));
        label_login->setGeometry(QRect(480, 150, 150, 25));
        label_login->setFont(font);
        label_login->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        connexion = new QPushButton(Connexion);
        connexion->setObjectName(QStringLiteral("connexion"));
        connexion->setGeometry(QRect(590, 230, 101, 41));
        label_erreur = new QLabel(Connexion);
        label_erreur->setObjectName(QStringLiteral("label_erreur"));
        label_erreur->setGeometry(QRect(540, 270, 281, 81));
        QFont font1;
        font1.setPointSize(10);
        font1.setBold(false);
        font1.setWeight(50);
        label_erreur->setFont(font1);
        label = new QLabel(Connexion);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(1, -15, 881, 471));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/fond_accueil.jpg")));
        tabWidget->addTab(Connexion, QString());
        label->raise();
        inscription->raise();
        input_mdp->raise();
        input_login->raise();
        label_mdp->raise();
        connexion->raise();
        label_erreur->raise();
        label_login->raise();
        Accueil->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Accueil);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 865, 22));
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
        inscription->setText(QApplication::translate("Accueil", "Inscription", 0));
        label_mdp->setText(QApplication::translate("Accueil", "Mot de passe", 0));
        label_login->setText(QApplication::translate("Accueil", "Login", 0));
        connexion->setText(QApplication::translate("Accueil", "Connexion", 0));
        label_erreur->setText(QString());
        label->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(Connexion), QApplication::translate("Accueil", "Connexion", 0));
    } // retranslateUi

};

namespace Ui {
    class Accueil: public Ui_Accueil {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACCUEIL_H
