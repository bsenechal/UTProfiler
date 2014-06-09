#include "fenetreplus.h"
#include "ui_fenetreplus.h"

fenetreplus::fenetreplus(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fenetreplus)
{
    ui->setupUi(this);
    visible=true;
    position=true;
}

fenetreplus::~fenetreplus()
{
    delete ui;
}

void fenetreplus::rendreVisible()
{
    if (this->visible==true) {
        hide();
        visible=false;
    }
    else {
        show();
        visible=true;
    }
}



void fenetreplus::changerPosition()
{
    int x= this->pos().x();
    int y= this->pos().y();

    if (this->position==true) {
        move(x,y-170);
        position=false;
    }
    else {
        move(x,y+170);
        position=true;
    }
}
