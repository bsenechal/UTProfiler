#include "categorie.h"

Categorie::Categorie()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_categories = db->getColonne("SELECT nom FROM categorie;");
}
