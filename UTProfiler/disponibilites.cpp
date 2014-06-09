#include "disponibilites.h"

Disponibilites::Disponibilites()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_dispos = db->getColonne("SELECT nom FROM disponibilite_uv;");
}
