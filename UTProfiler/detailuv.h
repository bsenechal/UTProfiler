#ifndef DETAILUV_H
#define DETAILUV_H

#include <QWidget>

namespace Ui {
class detailuv;
}

class detailuv : public QWidget
{
    Q_OBJECT

public:
    explicit detailuv(QWidget *parent = 0);
    ~detailuv();

private:
    Ui::detailuv *ui;
};

#endif // DETAILUV_H
