#include "afficherchoixprev.h"
#include "ui_afficherchoixprev.h"

afficherchoixprev::afficherchoixprev(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::afficherchoixprev)
{
    ui->setupUi(this);
}

afficherchoixprev::~afficherchoixprev()
{
    delete ui;
}
