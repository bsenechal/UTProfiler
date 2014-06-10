/********************************************************************************
** Form generated from reading UI file 'fenetreplus.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FENETREPLUS_H
#define UI_FENETREPLUS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fenetreplus
{
public:
    QCommandLinkButton *commandLinkButton;

    void setupUi(QWidget *fenetreplus)
    {
        if (fenetreplus->objectName().isEmpty())
            fenetreplus->setObjectName(QStringLiteral("fenetreplus"));
        fenetreplus->resize(420, 131);
        commandLinkButton = new QCommandLinkButton(fenetreplus);
        commandLinkButton->setObjectName(QStringLiteral("commandLinkButton"));
        commandLinkButton->setGeometry(QRect(10, 0, 199, 41));

        retranslateUi(fenetreplus);

        QMetaObject::connectSlotsByName(fenetreplus);
    } // setupUi

    void retranslateUi(QWidget *fenetreplus)
    {
        fenetreplus->setWindowTitle(QApplication::translate("fenetreplus", "Form", 0));
        commandLinkButton->setText(QApplication::translate("fenetreplus", "CommandLinkButton", 0));
    } // retranslateUi

};

namespace Ui {
    class fenetreplus: public Ui_fenetreplus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FENETREPLUS_H
