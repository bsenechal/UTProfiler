#include "connexion.h"
#include "dbmanager.h"
#include "formulaire.h"

/**
  * @file connexion.cpp
  */

/**
 * @fn  QString Connexion::connexion(QString login, QString mdp)
 * @return QString
 * @param QString login
 * @param QString mdp
 * @brief Permet la connexion d'un utilisateur. Renvoi "ok" si la connection est effectuée et un message d'erreur sinon.
 */
QString Connexion::connexion(QString login, QString mdp) {
    dbmanager *db = dbmanager::getInstance();
    QString res = "ok";
    QSqlQuery query;
    bool error = true;

    try {
        formulaire<QString>::verif_text(login, "Login");
        formulaire<QString>::verif_text(mdp, "Mot de passe");
        error = false;
    }

    catch (FormulaireException e) {
        res = e.getinfo();
    }
    if (!error) {
        query = db->execute("SELECT * FROM Etudiant WHERE login='" + login + "' AND passwd='" + mdp + "';");

        if(query.next()){
               this->setLogin(query.value(0).toString());
               this->setPasswd(query.value(1).toString());
               this->setNom(query.value(2).toString());
               this->setPrenom(query.value(3).toString());
               this->setSexe(query.value(4).toString());
               this->setDate_naissance(query.value(5).toString());
               this->setEmail(query.value(6).toString());
               this->setCommentaires(query.value(7).toString());
            }
        else {
            QMessageBox msgBox;
            msgBox.setText("Mauvais identifiant où mot de passe !");
            msgBox.exec();
        }
        }

    return res;
}
