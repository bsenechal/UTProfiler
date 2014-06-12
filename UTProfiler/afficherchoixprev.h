#ifndef AFFICHERCHOIXPREV_H
#define AFFICHERCHOIXPREV_H

#include <QWidget>
#include <QDialog>
#include <QDebug>

namespace Ui {
class afficherchoixprev;
}

class afficherchoixprev : public QDialog
{
    Q_OBJECT



private:
    Ui::afficherchoixprev *ui;
    typedef std::map<int, std::map<QString, QString> > Mapsugg_UV;
    typedef std::map<int, std::map<QString, std::pair<int, int> > > Mapsugg_nbtype2;
    Mapsugg_nbtype2 map_suggestion_nb;

public:
    explicit afficherchoixprev(QDialog *parent = 0);
    void ajoutprev(Mapsugg_UV mapsuggestion, Mapsugg_nbtype2 map_suggestion_nb);
    ~afficherchoixprev();
};

#endif // AFFICHERCHOIXPREV_H
