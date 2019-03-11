#include "uiTest.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uiTest w;
	w.show();
	return a.exec();
}
