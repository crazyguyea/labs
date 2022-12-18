#ifndef LAB7_H
#define LAB7_H

#include "rectpainter.h"

#include <QWidget>
#include <QGraphicsScene>

namespace Ui {
class Lab7;
}

class Lab7 : public QWidget
{
    Q_OBJECT

public:
    explicit Lab7(QWidget *parent = 0);
    ~Lab7();
private slots:
    void on_pushButton_clicked();

private:
    Ui::Lab7 *ui;
    QGraphicsScene *scene;
};

#endif // LAB7_H
