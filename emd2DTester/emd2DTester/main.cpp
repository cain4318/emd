#include "emd2dtester.h"
#include "compareDialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
	compareDialog d;
	d.show();

    emd2DTester w;
    w.show();
    return a.exec();
}
