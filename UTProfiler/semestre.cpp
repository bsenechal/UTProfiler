#include "semestre.h"

Semestre::Semestre()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_semestres = db->getColonne("SELECT nom FROM semestre ORDER BY annee DESC;");
}
