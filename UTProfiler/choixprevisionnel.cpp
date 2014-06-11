#include "choixprevisionnel.h"
#include "ui_choixprevisionnel.h"

choixprevisionnel::choixprevisionnel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::choixprevisionnel)
{
    ui->setupUi(this);
}

choixprevisionnel::~choixprevisionnel()
{
    delete ui;
}
