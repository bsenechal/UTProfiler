#include "categorie.h"

/**
  * @file categorie.cpp
  */

/**
 * @fn  Categorie::Categorie()
 * @brief Constructeur de la classe Categorie. Il stock dans liste_categories chaque nom de categorie
 */
Categorie::Categorie()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_categories = db->getColonne("SELECT nom FROM categorie;");
}
