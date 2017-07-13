#include "dataprocess.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DataProcess w;
	w.show();
	return a.exec();
}
