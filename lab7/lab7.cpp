#include "lab7.h"
#include "ui_lab7.h"

Lab7::Lab7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Lab7)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    RectPainter *item = new RectPainter();
    item->setPos(20, 20);
    scene->addItem(item);
}

Lab7::~Lab7()
{
    delete ui;
}

void Lab7::on_pushButton_clicked()
{
    this->close();
}

