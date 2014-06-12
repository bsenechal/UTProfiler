#include "etudiants.h"

/**
  * @file etudiants.cpp
  */

/**
 * @fn  Etudiants::Etudiants()
 * @brief Constructeur de la classe Etudiants. Il stock le nom de tous les étudiants dans "liste_etudiants"
 */
Etudiants::Etudiants()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_etudiants = db->getColonne("SELECT login FROM Etudiant;");
}
