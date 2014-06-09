#ifndef DISPONIBILITES_H
#define DISPONIBILITES_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Disponibilites : public Singleton<Disponibilites>
{
    friend class Singleton<Disponibilites>;
    QStringList liste_dispos;
    Disponibilites();
public:

    QStringList& getListe_dispos() { return this->liste_dispos; }
    void push_back(QString item) { this->liste_dispos.push_back(item); }
    void removeAt(int row) { this->liste_dispos.removeAt(row); }
    void setListe_dispos(QStringList& l) { this->liste_dispos = l; }
};

#endif // DISPONIBILITES_H
