#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "plot.h"
#include <algorithm>

static int ind;
static const int h = 2;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//clear
void MainWindow::on_pushButton_clicked()
{
    int g = ui->widget->graphCount();
    for (int i = 0; i < g; i++)
        ui->widget->graph(i)->data()->clear();
    ui->widget->replot();
    ind = 0;
}

//draw
void MainWindow::on_pushButton_2_clicked()
{
    //getting from a line editor
    QString inputStr = ui->lineEdit->text();
    if (!inputStr.isEmpty()) {
        //clear the plot
        on_pushButton_clicked();

        //constructing the plot
        Plot plot(inputStr);

        //setting ranges for plot
        ui->widget->xAxis->setRange(0, plot.getX().back() + 1);
        ui->widget->yAxis->setRange(*std::min_element(plot.getY().constBegin(), plot.getY().constEnd()) - h,
                                    *std::max_element(plot.getY().constBegin(), plot.getY().constEnd()) + h);

        //drawing plot
        ui->widget->addGraph();
        ui->widget->graph(ind)->addData(plot.getX(), plot.getY());
        //ui->widget->graph(ind++)->setPen(QPen(Qt::blue));


        //drawting Inflection points
        //ui->widget->graph(ind)->selectionDecorator()->setPen(QPen(Qt::green));
        //ui->widget->graph(ind++)->addData(plot.getX(), plot.getY());
        ui->widget->replot();
    }
}

