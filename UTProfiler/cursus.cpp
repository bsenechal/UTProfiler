#include "cursus.h"

/**
  * @file cursus.cpp
  */

/**
 * @fn  Cursus::Cursus()
 * @brief Constructeur de la classe Cursus. Il stock le nom de chaque cursus dans "liste_cursus"
 */
Cursus::Cursus()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_cursus = db->getColonne("SELECT nom FROM cursus;");
}
