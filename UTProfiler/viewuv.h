#ifndef VIEWUV_H
#define VIEWUV_H

#include <QWidget>
#include <QMainWindow>

namespace Ui {
class ViewUv;
}

class ViewUv : public QWidget
{
    Q_OBJECT

public:
    explicit ViewUv(QWidget *parent = 0);
    ~ViewUv();

private:
    Ui::ViewUv *ui;
};

#endif // VIEWUV_H
