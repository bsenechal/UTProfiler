#include "uvmnger.h"
#include <map>
#include <iterator>


Uvmnger::Uvmnger()
{
    db = dbmanager::getInstance();
    this->liste_uv = db->getColonne("SELECT code FROM UV;");
}


map<QString,QString> Uvmnger::getPossibiliteFromUv(const QString& Uv){
    std::map<QString,QString> map_pos_uv;


    QSqlQuery query;
    query = db->execute("SELECT id_acatu, nom_categorie, nbcredits FROM assoc_categorie_UV WHERE code_uv = '" + Uv + "' ORDER BY id_acatu;");

    QString idsvg;
    QString maligne="";

    while (query.next()) {
        if ((query.value(0).toString())==idsvg) {
            maligne=maligne+" & "+query.value(1).toString()+" : "+query.value(2).toString();
        }
        else {
            if(maligne!=""){map_pos_uv[maligne]=idsvg;}
            maligne=""+query.value(1).toString()+" : "+query.value(2).toString();
        }
           idsvg=query.value(0).toString();
     }
    map_pos_uv[maligne]=idsvg;

    return map_pos_uv;
}

/*
map<QString,QString>::iterator p;
for(p = map_pos_uv.begin(); p != map_pos_uv.end(); p++)
{
  qDebug() <<"first : "<< p->first ;
  qDebug()  <<"second : "<<p->second;
}
*/

/*
QStringList uvmnger::getPossibiliteFromUv(const QString& Uv){
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
}*/
