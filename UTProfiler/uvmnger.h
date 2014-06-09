#ifndef UVMNGER_H
#define UVMNGER_H


#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class uvmnger : public Singleton<uvmnger>
{
    friend class Singleton<uvmnger>;
    QStringList liste_uv;
    dbmanager *db;
    uvmnger();

public:
    QStringList getPossibiliteFromUv(const QString& Uv);
};


#endif // UVMNGER_H
