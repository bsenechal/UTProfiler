#include "insertuv.h"
#include "ui_insertuv.h"

InsertUv::InsertUv(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InsertUv)
{
    ui->setupUi(this);
}

InsertUv::~InsertUv()
{
    delete ui;
}
