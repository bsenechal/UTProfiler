#include "disponibilites.h"
/**
  * @file disponibilites.cpp
  */

/**
 * @fn  Disponibilites::Disponibilites()
 * @brief Constructeur de la classe Disponibilites. Il stock le nom de toutes les disponibilités d'UV dans "liste_dispos"
 */
Disponibilites::Disponibilites()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_dispos = db->getColonne("SELECT nom FROM disponibilite_uv;");
}
