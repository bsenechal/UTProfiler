#ifndef AFFICHERCHOIXPREV_H
#define AFFICHERCHOIXPREV_H

#include <QWidget>

namespace Ui {
class afficherchoixprev;
}

class afficherchoixprev : public QWidget
{
    Q_OBJECT

public:
    explicit afficherchoixprev(QWidget *parent = 0);
    ~afficherchoixprev();

private:
    Ui::afficherchoixprev *ui;
};

#endif // AFFICHERCHOIXPREV_H
