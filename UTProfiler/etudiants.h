#ifndef ETUDIANTS_H
#define ETUDIANTS_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Etudiants : public Singleton<Etudiants>
{
    friend class Singleton<Etudiants>;
    QStringList liste_etudiants;
    Etudiants();
public:
    QStringList& getListe_etudiants() { return this->liste_etudiants; }
    void push_back(QString item) { this->liste_etudiants.push_back(item); }
    void removeAt(int row) { this->liste_etudiants.removeAt(row); }
    void setListe_etudiants(QStringList& l) { this->liste_etudiants = l; }
};

#endif // ETUDIANTS_H
