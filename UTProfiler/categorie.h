#ifndef CATEGORIE_H
#define CATEGORIE_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Categorie : public Singleton<Categorie>
{
    friend class Singleton<Categorie>;
    QStringList liste_categories;
    Categorie();
public:
    QStringList& getListe_categories() { return this->liste_categories; }
    void push_back(QString item) { this->liste_categories.push_back(item); }
    void removeAt(int row) { this->liste_categories.removeAt(row); }
    void setListe_categories(QStringList& l) { this->liste_categories = l; }
};



#endif // CATEGORIE_H
