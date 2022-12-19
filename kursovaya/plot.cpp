#include "plot.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

Plot::Plot(QString inputStr)
{
    /*std::ifstream myfile;
    std::string tmp;
    double d = 0;

    myfile.open(inputStr.toStdString());

    if (myfile.is_open()) {
        while (myfile) {
            std::getline(myfile, tmp);
            if (!tmp.empty()) {
                try {
                    yComponent.push_back(std::stod(tmp));
                    xComponent.push_back(d++);
                } catch (...) {
                    continue;
                }
            }
        }
    }*/

    std::string tmp;
    std::istringstream strStream(inputStr.toStdString());
    double d = 0;
    while (std::getline(strStream, tmp, ';')) {
        if (!tmp.empty()) {
            try {
                yComponent.push_back(std::stod(tmp));
                xComponent.push_back(d++);
            } catch (...) {
                continue;
            }
        }
    }
}

QVector<double> Plot::getY()
{
    return yComponent;
}

QVector<double> Plot::getX()
{
    return xComponent;
}

QVector<double> Plot::getXInflected()
{
    return xInflected;
}

QVector<double> Plot::getYInflected()
{
    return yInflected;
}

void Plot::drawInflected(QCustomPlot *plot)
{
    solveInflection();
    // draw each point
    QCPItemTracer *groupTracer = new QCPItemTracer(plot);
    groupTracer->setGraph(plot->graph());
    groupTracer->setGraphKey(3);
    //groupTracer->setInterpolating(true);
    groupTracer->setStyle(QCPItemTracer::tsCircle);
    groupTracer->setPen(QPen(Qt::red));
    groupTracer->setBrush(Qt::red);
    groupTracer->setSize(7);
}

void Plot::solveInflection()
{
    /*double prev = 0;
    for (int i = 0; i < yComponent.count() - 1; i++) {
        double z = yComponent[i] * yComponent[i + 1] + i * i + 1;
        if (z)
    }*/
}
