#include <iostream>
#include "dbmanager.h"
#include "utprofilerexception.h"


void dbmanager::dbinitialise(QString dbtype, QString dbhost, QString dbuser, QString dbpasswd, QString dbname) {
   db = QSqlDatabase::addDatabase(dbtype);
   /////////Completer
}


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

QStringList dbmanager::getColonne(QString requete)
{
    QStringList liste;

    QSqlQuery query = this->execute(requete);

    while (query.next()) {
           liste << query.value(0).toString();
     }

    return liste;
}
