#include "emd2dtester.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    emd2DTester w;
    w.show();
    return a.exec();
}
