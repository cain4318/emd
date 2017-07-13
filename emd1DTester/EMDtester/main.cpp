#include "emdtester.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    EMDtester w;
    w.show();
    return a.exec();
}
