#include "clockdown.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ClockDown w;
    w.show();
    return a.exec();
}
