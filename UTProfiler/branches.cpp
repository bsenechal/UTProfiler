#include "branches.h"
/**
  *@file branches.cpp
  */

/**
 * @fn Branches::Branches()
 * @brief Constructeur de la classe Branches. Il récupère les noms de toutes les branches et les stocks dans "liste_branches"
 * @return void
 */
Branches::Branches()
{
    db = dbmanager::getInstance();
    this->liste_branches = db->getColonne("SELECT nom FROM branche;");
}

/**
 * @fn QStringList Branches::getBranchesFromCursus(const QString& cursus)
 * @param const QString& cursus
 * @brief Renvoi toutes les branches qui correspondent au cursus passé en paramètre
 * @return const QString& cursus
 */
QStringList Branches::getBranchesFromCursus(const QString& cursus) {
    return db->getColonne("SELECT nom FROM branche WHERE nom_cursus = '" + cursus + "';");
}
