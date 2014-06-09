#include "branches.h"

Branches::Branches()
{
    db = dbmanager::getInstance();
    this->liste_branches = db->getColonne("SELECT nom FROM branche;");
}

QStringList Branches::getBranchesFromCursus(const QString& cursus) {
    return db->getColonne("SELECT nom FROM branche WHERE nom_cursus = '" + cursus + "';");
}
