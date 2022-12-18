#include <QApplication>
#include "lab7.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Lab7 b;
    b.show();
    return a.exec();
}
