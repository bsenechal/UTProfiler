/**
  * @file filieres.h
  */

#ifndef FILIERES_H
#define FILIERES_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Filieres : public Singleton<Filieres>
{
    friend class Singleton<Filieres>;
    QStringList liste_filieres;
    dbmanager *db;
    Filieres();

public:
    QStringList& getListe_filieres() { return this->liste_filieres; }
    QStringList getFilieresFromBranche(const QString& branche);
    void push_back(QString item) { this->liste_filieres.push_back(item); }
    void removeAt(int row) { this->liste_filieres.removeAt(row); }
    void setListe_cursus(QStringList& l) { this->liste_filieres = l; }
};


#endif // FILIERES_H
