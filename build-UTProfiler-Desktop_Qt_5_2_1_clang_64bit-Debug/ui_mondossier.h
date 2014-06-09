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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_mondossier
{
public:
    QTabWidget *tabwidget;
    QWidget *mes_infos;
    QWidget *tab_info_perso;
    QLabel *label;

    void setupUi(QDialog *mondossier)
    {
        if (mondossier->objectName().isEmpty())
            mondossier->setObjectName(QStringLiteral("mondossier"));
        mondossier->resize(831, 467);
        tabwidget = new QTabWidget(mondossier);
        tabwidget->setObjectName(QStringLiteral("tabwidget"));
        tabwidget->setGeometry(QRect(0, 30, 841, 441));
        mes_infos = new QWidget();
        mes_infos->setObjectName(QStringLiteral("mes_infos"));
        tabwidget->addTab(mes_infos, QString());
        tab_info_perso = new QWidget();
        tab_info_perso->setObjectName(QStringLiteral("tab_info_perso"));
        tabwidget->addTab(tab_info_perso, QString());
        label = new QLabel(mondossier);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(-60, 0, 911, 61));
        label->setPixmap(QPixmap(QString::fromUtf8(":/images/bandeau_utc.jpg")));
        label->raise();
        tabwidget->raise();

        retranslateUi(mondossier);

        tabwidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(mondossier);
    } // setupUi

    void retranslateUi(QDialog *mondossier)
    {
        mondossier->setWindowTitle(QApplication::translate("mondossier", "Dialog", 0));
        tabwidget->setTabText(tabwidget->indexOf(mes_infos), QApplication::translate("mondossier", "Mes Informations", 0));
        tabwidget->setTabText(tabwidget->indexOf(tab_info_perso), QApplication::translate("mondossier", "Tab 2", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class mondossier: public Ui_mondossier {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONDOSSIER_H
