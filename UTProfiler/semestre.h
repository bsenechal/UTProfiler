#ifndef SEMESTRE_H
#define SEMESTRE_H

#include <QStringList>
#include "singleton.h"
#include "dbmanager.h"

class Semestre : public Singleton<Semestre>
{
    friend class Singleton<Semestre>;
    QStringList liste_semestres;
public:
    Semestre();
    QStringList& getListe_semestres() { return this->liste_semestres; }
    void push_back(QString item) { this->liste_semestres.push_back(item); }
    void removeAt(int row) { this->liste_semestres.removeAt(row); }
    void setListe_semestres(QStringList& l) { this->liste_semestres = l; }
};


#endif // SEMESTRE_H
