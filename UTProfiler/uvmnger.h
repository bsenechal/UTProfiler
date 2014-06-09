#ifndef UVMNGER_H
#define UVMNGER_H


#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Uvmnger : public Singleton<Uvmnger>
{
    friend class Singleton<Uvmnger>;
    QStringList liste_uv;
    dbmanager *db;
    Uvmnger();

public:
    QStringList getPossibiliteFromUv(const QString& Uv);
};


#endif // UVMNGER_H
