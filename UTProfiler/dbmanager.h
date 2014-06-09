#ifndef DBMANAGER_H
#define DBMANAGER_H

#include <QCoreApplication>
#include <QtSql>
#include <iostream>
#include <QStringList>
#define q2c(string) string.toStdString()

#include "singleton.h"

using namespace std;


class dbmanager : public Singleton<dbmanager>
{
  friend class Singleton<dbmanager>;

private:
  dbmanager () {}
  ~dbmanager (){db.close();}

public:
  void dbinitialise(QString dbtype, QString dbhost, QString dbuser, QString dbpasswd, QString dbname);   //MySQL
  void dbinitialise(QString dbtype, QString dbname);  //SqLite
  void dbclose(){   db.close();}

  QSqlDatabase getValue () { return db; }
  QSqlQuery execute(QString marequete);
  QStringList getColonne(QString requete);

private:
  QSqlDatabase db;
  QSqlQuery query;
};

#endif // DBMANAGER_H
