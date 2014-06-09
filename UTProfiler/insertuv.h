#ifndef INSERTUV_H
#define INSERTUV_H

#include <QWidget>

namespace Ui {
class InsertUv;
}

class InsertUv : public QWidget
{
    Q_OBJECT

public:
    explicit InsertUv(QWidget *parent = 0);
    ~InsertUv();

private:
    Ui::InsertUv *ui;
};

#endif // INSERTUV_H
