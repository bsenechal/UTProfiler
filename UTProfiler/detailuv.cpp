#include "detailuv.h"
#include "ui_detailuv.h"
#include "dbmanager.h"
#include <QString>

detailuv::detailuv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::detailuv)
{
    ui->setupUi(this);

    dbmanager *mabdd = dbmanager::getInstance();
}

detailuv::~detailuv()
{
    delete ui;
}
