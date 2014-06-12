#include <iostream>
#include "dbmanager.h"

/**
  * @file connexion.cpp
  */

/*void dbmanager::dbinitialise(QString dbtype, QString dbhost, QString dbuser, QString dbpasswd, QString dbname) {
   db = QSqlDatabase::addDatabase(dbtype);
   /////////Completer
}
*/

/**
 * @fn  void dbmanager::dbinitialise(QString dbtype, QString dbname)
 * @return void
 * @param QString dbtype
 * @param QString dbname
 * @brief Initialise la base de données
 */
void dbmanager::dbinitialise(QString dbtype, QString dbname) {
   db = QSqlDatabase::addDatabase(dbtype);
   db.setDatabaseName(dbname);
   cout<<"Db manager SQLite\n";

   if(db.open())
   {
       std::cout << "Vous êtes maintenant connecté à " << q2c(db.databaseName()) << std::endl;
   }
   else
   {

       std::cout << "La connexion a échouée, désolé " << q2c(db.databaseName()) << std::endl;
   }
}

/**
 * @fn  QSqlQuery dbmanager::execute(QString marequete)
 * @return QSqlQuery
 * @param QString marequete
 * @brief Execute la requête passée en paramètre
 */
QSqlQuery dbmanager::execute(QString marequete) {
   QSqlQuery query(db);
   if(query.exec(marequete))
   {
       std::cout << "La requete a fonctionnee ! :)" << std::endl;
       return query;
   }
   else
       {
       throw UTProfilerException("Une erreur s'est produite. " + query.lastError().text());
       std::cout << "Une erreur s'est produite. " << std::endl << q2c(query.lastError().text()) << std::endl;
   }
}

/**
 * @fn  QStringList dbmanager::getColonne(QString requete)
 * @return QStringList
 * @param QString requete
 * @brief Renvoi une colonne d'une table de la BDD en fonction de la requête passée en paramètre
 */
QStringList dbmanager::getColonne(QString requete)
{
    QStringList liste;

    QSqlQuery query = this->execute(requete);

    while (query.next()) {
           liste << query.value(0).toString();
     }

    return liste;
}
