#include "DirModel.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	DirModel wind;

	wind.show();

	app.exec();
	return 1;
}
