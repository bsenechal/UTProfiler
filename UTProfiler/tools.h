/**
  * @file tools.h
  */

#ifndef TOOLS_H
#define TOOLS_H

#include <qlistwidget.h>
#include <qcombobox.h>
#include "dbmanager.h"

class Tools
{
public:
    Tools();
    static void switch_current_item(QListWidget *liste1,  QListWidget *liste2);
    static void enable_combobox(QComboBox* cbox, const QStringList& liste);
    static void maj_liste(QListWidget *liste, QSqlQuery query);
    static void maj_liste(QListWidget *liste1, QListWidget *liste2, const QSqlQuery query);
 };



#endif // TOOLS_H
