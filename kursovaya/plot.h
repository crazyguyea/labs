#ifndef PLOT_H
#define PLOT_H

#include <QVector>
#include "mainwindow.h"
#include "ui_mainwindow.h"

class Plot
{
public:
    Plot(QString inputStr);
    QVector<double> getY();
    QVector<double> getX();
    QVector<double> getXInflected();
    QVector<double> getYInflected();
    void            drawInflected(QCustomPlot *plot);

private:
    void solveInflection();

private:
    //main plot
    QVector<double>     yComponent;
    QVector<double>     xComponent;

    //inflected points
    QVector<double>     xInflected;
    QVector<double>     yInflected;
};

#endif // PLOT_H
