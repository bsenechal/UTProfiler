#ifndef CHOIXPREVISIONNEL_H
#define CHOIXPREVISIONNEL_H

#include <QFrame>

namespace Ui {
class choixprevisionnel;
}

class choixprevisionnel : public QFrame
{
    Q_OBJECT

public:
    explicit choixprevisionnel(QWidget *parent = 0);

    ~choixprevisionnel();

private:
    Ui::choixprevisionnel *ui;
};

#endif // CHOIXPREVISIONNEL_H
