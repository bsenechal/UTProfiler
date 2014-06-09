#include "filieres.h"

Filieres::Filieres()
{
    db = dbmanager::getInstance();
    this->liste_filieres = db->getColonne("SELECT DISTINCT nom FROM Filiere;");
}

QStringList Filieres::getFilieresFromBranche(const QString& branche) {
    return db->getColonne("SELECT nom_filiere FROM assoc_branche_filiere WHERE nom_branche = '" + branche + "';");
}
