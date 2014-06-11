#include "choixprevisionnel.h"
#include "ui_choixprevisionnel.h"

choixprevisionnel::choixprevisionnel(QWidget *parent) :
    QFrame(parent),
    ui(new Ui::choixprevisionnel)
{
    ui->setupUi(this);
}

choixprevisionnel::~choixprevisionnel()
{
    delete ui;
}
