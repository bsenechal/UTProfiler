/**
  * @file afficherchoixprev.h
  */

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

public:
    explicit afficherchoixprev(QDialog *parent = 0);
    void ajoutprev(Mapsugg_UV mapsuggestion);
    ~afficherchoixprev();
};

#endif // AFFICHERCHOIXPREV_H
