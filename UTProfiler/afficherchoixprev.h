#ifndef AFFICHERCHOIXPREV_H
#define AFFICHERCHOIXPREV_H

#include <QWidget>
#include <QDialog>
#include <QDebug>
#include <QListWidget>
#include <QPushButton>
#include "dbmanager.h"

namespace Ui {
class afficherchoixprev;
}

class afficherchoixprev : public QDialog
{
    Q_OBJECT



private:
    Ui::afficherchoixprev *ui;
    dbmanager *db;

    typedef std::map<int, std::map<QString, QString> > Mapsugg_UV;
    typedef std::map<int, std::map<QString, std::pair<int, int> > > Mapsugg_nbtype2;
    Mapsugg_nbtype2 map_suggestion_nb;

    typedef std::map<int, std::map<QString, std::pair<QString, int> > > Mapsugg_UV2;
    //[S1]["LO21"].first=categ [S1]["LO21"].second=nbcredit
    Mapsugg_UV2 map_suggestion_uv2;

    typedef struct   {
         QListWidget *uv;
         QListWidget *categorie;
         QListWidget *credits;
         QString credits_cs;
         QString credits_tm;
         QString credits_tsh;
         QString credits_total;
        }liste_semestre;
    typedef std::map<QString, liste_semestre > Map_of_liste;
    Map_of_liste map_liste;
    QPushButton *btn_sauvegarder;
public:
    explicit afficherchoixprev(QDialog *parent = 0);
    void ajoutprev(Mapsugg_UV2 mapsuggestion);
    ~afficherchoixprev();
private slots:
    void sauvegarde_solutions();
};

#endif // AFFICHERCHOIXPREV_H
