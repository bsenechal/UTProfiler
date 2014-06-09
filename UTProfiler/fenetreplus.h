#ifndef FENETREPLUS_H
#define FENETREPLUS_H

#include <QWidget>

namespace Ui {
class fenetreplus;
}

class fenetreplus : public QWidget
{
    Q_OBJECT

public:
    explicit fenetreplus(QWidget *parent = 0);
    ~fenetreplus();

public slots:
void rendreVisible();
void changerPosition();

private:
    Ui::fenetreplus *ui;
    bool visible;
    bool position;  //true=haute ou false=basse ? pour masquer
};

#endif // FENETREPLUS_H
