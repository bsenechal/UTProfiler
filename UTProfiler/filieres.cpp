#include "filieres.h"
/**
  * @file filieres.cpp
  */

/**
 * @fn  Filieres::Filieres()
 * @brief Constructeur de la classe Filieres. Il stock le nom de toutes les filieres dans "liste_filieress"
 */
Filieres::Filieres()
{
    db = dbmanager::getInstance();
    this->liste_filieres = db->getColonne("SELECT DISTINCT nom FROM Filiere;");
}


/**
 * @fn  Filieres::Filieres()
 * @param const QString& branche
 * @return QStringList
 * @brief Renvoi sous forme la liste de toutes les filieres correspondantes à la branche passée en paramètre
 */
QStringList Filieres::getFilieresFromBranche(const QString& branche) {
    return db->getColonne("SELECT nom_filiere FROM assoc_branche_filiere WHERE nom_branche = '" + branche + "';");
}
