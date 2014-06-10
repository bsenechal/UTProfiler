/**
 * \file categorie.cpp
 */

#include "categorie.h"

/**
 * \fn Categorie::Categorie()
 * \brief Construit une QStringList à partir des noms de chaque catégorie d'UV
 */
Categorie::Categorie()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_categories = db->getColonne("SELECT nom FROM categorie;");
}
