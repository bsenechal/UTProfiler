#include "cursus.h"

Cursus::Cursus()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_cursus = db->getColonne("SELECT nom FROM cursus;");
}
