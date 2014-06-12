#include "semestre.h"

/**
 * @file semestre.cpp
 */

/**
 * @fn Semestre::Semestre()
 * @brief Constructeur de la classe semestre. Il stock dans "liste_semestres" le nom de tous les semestres
 */
Semestre::Semestre()
{
    dbmanager *db = dbmanager::getInstance();
    this->liste_semestres = db->getColonne("SELECT nom FROM semestre ORDER BY annee DESC;");
}
