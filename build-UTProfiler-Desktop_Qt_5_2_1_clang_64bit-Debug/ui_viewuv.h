/********************************************************************************
** Form generated from reading UI file 'viewuv.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWUV_H
#define UI_VIEWUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewUv
{
public:
    QTabWidget *tabWidget;
    QWidget *Tout;
    QListWidget *allUv;

    void setupUi(QWidget *ViewUv)
    {
        if (ViewUv->objectName().isEmpty())
            ViewUv->setObjectName(QStringLiteral("ViewUv"));
        ViewUv->setEnabled(true);
        ViewUv->resize(860, 430);
        tabWidget = new QTabWidget(ViewUv);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 861, 431));
        Tout = new QWidget();
        Tout->setObjectName(QStringLiteral("Tout"));
        allUv = new QListWidget(Tout);
        allUv->setObjectName(QStringLiteral("allUv"));
        allUv->setGeometry(QRect(20, 40, 811, 341));
        tabWidget->addTab(Tout, QString());

        retranslateUi(ViewUv);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ViewUv);
    } // setupUi

    void retranslateUi(QWidget *ViewUv)
    {
        ViewUv->setWindowTitle(QApplication::translate("ViewUv", "Form", 0));
        tabWidget->setTabText(tabWidget->indexOf(Tout), QApplication::translate("ViewUv", "Tout", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewUv: public Ui_ViewUv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWUV_H
