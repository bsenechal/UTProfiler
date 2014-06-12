/**
  * @file cursus.h
  */

#ifndef CURSUS_H
#define CURSUS_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Cursus : public Singleton<Cursus> /* Pour être sûr qu'on travail toujours sur une liste à jour des Cursus */
{
    friend class Singleton<Cursus>;
    QStringList liste_cursus;
    Cursus();

public:
    QStringList& getListe_cursus() { return this->liste_cursus; }
    void push_back(QString item) { this->liste_cursus.push_back(item); }
    void removeAt(int row) { this->liste_cursus.removeAt(row); }
    void setListe_cursus(QStringList& l) { this->liste_cursus = l; }
};

#endif // CURSUS_H
