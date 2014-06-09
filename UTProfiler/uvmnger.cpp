#include "uvmnger.h"

Uvmnger::Uvmnger()
{
    db = dbmanager::getInstance();
    this->liste_uv = db->getColonne("SELECT code FROM UV;");
}


QStringList Uvmnger::getPossibiliteFromUv(const QString& Uv){
    QSqlQuery query;
    query = db->execute("SELECT id_acatu, nom_categorie, nbcredits FROM assoc_categorie_UV WHERE code_uv = '" + Uv + "' ORDER BY id_acatu;");

    QStringList liste;

    QString idsvg;
    QString maligne="";

    while (query.next()) {
        if ((query.value(0).toString())==idsvg) {
            maligne=maligne+" & "+query.value(1).toString()+" : "+query.value(2).toString();
        }
        else {
            if(maligne!=""){liste<<maligne;}
            maligne=""+query.value(1).toString()+" : "+query.value(2).toString();
        }
           idsvg=query.value(0).toString();
     }
    liste<<maligne;

qDebug()<<liste;
    return liste;
}
