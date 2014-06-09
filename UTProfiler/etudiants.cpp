#include "etudiants.h"

Etudiants::Etudiants()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_etudiants = db->getColonne("SELECT login FROM Etudiant;");
}
