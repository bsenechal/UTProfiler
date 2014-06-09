/********************************************************************************
** Form generated from reading UI file 'detailuv.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DETAILUV_H
#define UI_DETAILUV_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_detailuv
{
public:
    QLabel *titre;
    QLabel *codetitre;
    QLabel *label;
    QTextBrowser *textBrowser;
    QLabel *label_dispo;
    QListView *list_dispo;

    void setupUi(QWidget *detailuv)
    {
        if (detailuv->objectName().isEmpty())
            detailuv->setObjectName(QStringLiteral("detailuv"));
        detailuv->resize(581, 464);
        titre = new QLabel(detailuv);
        titre->setObjectName(QStringLiteral("titre"));
        titre->setGeometry(QRect(170, 10, 101, 41));
        QFont font;
        font.setPointSize(15);
        titre->setFont(font);
        codetitre = new QLabel(detailuv);
        codetitre->setObjectName(QStringLiteral("codetitre"));
        codetitre->setGeometry(QRect(280, 10, 51, 41));
        codetitre->setFont(font);
        label = new QLabel(detailuv);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 80, 91, 16));
        textBrowser = new QTextBrowser(detailuv);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(20, 110, 531, 111));
        label_dispo = new QLabel(detailuv);
        label_dispo->setObjectName(QStringLiteral("label_dispo"));
        label_dispo->setGeometry(QRect(40, 240, 231, 16));
        list_dispo = new QListView(detailuv);
        list_dispo->setObjectName(QStringLiteral("list_dispo"));
        list_dispo->setGeometry(QRect(20, 260, 531, 192));

        retranslateUi(detailuv);

        QMetaObject::connectSlotsByName(detailuv);
    } // setupUi

    void retranslateUi(QWidget *detailuv)
    {
        detailuv->setWindowTitle(QApplication::translate("detailuv", "Form", 0));
        titre->setText(QApplication::translate("detailuv", "Detail de l'UV", 0));
        codetitre->setText(QApplication::translate("detailuv", "CODE", 0));
        label->setText(QApplication::translate("detailuv", "Description :", 0));
        label_dispo->setText(QApplication::translate("detailuv", "Disponible en tant que :", 0));
    } // retranslateUi

};

namespace Ui {
    class detailuv: public Ui_detailuv {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DETAILUV_H
