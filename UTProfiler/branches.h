/**
  * @file branches.h
  */

#ifndef BRANCHES_H
#define BRANCHES_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Branches : public Singleton<Branches>
{
    friend class Singleton<Branches>;
    QStringList liste_branches;
    dbmanager *db;
    Branches();

public:
    QStringList& getListe_branches() { return this->liste_branches; }
    QStringList getBranchesFromCursus(const QString& cursus);
    void push_back(QString item) { this->liste_branches.push_back(item); }
    void removeAt(int row) { this->liste_branches.removeAt(row); }
    void setListe_branches(QStringList& l) { this->liste_branches = l; }
};

#endif // BRANCHES_H
