#ifndef CHOIXPREVISIONNEL_H
#define CHOIXPREVISIONNEL_H

#include <QDialog>

namespace Ui {
class choixprevisionnel;
}

class choixprevisionnel : public QDialog
{
    Q_OBJECT

public:
    explicit choixprevisionnel(QWidget *parent = 0);
    ~choixprevisionnel();

private:
    Ui::choixprevisionnel *ui;
};

#endif // CHOIXPREVISIONNEL_H
