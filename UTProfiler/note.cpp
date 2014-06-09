#include "note.h"
#include "dbmanager.h"

Note::Note()
{
    QSqlQuery query;
    query.prepare("SELECT Note FROM Note;");
    if (!query.exec())
            qDebug() << "Erreur de la BDD : "<< query.lastError();
    else {
        while (query.next()) {
            Notes << query.value(0).toString();
        }
    }
}

