#include "chanEditor.h"
#include <QtWidgets/QApplication>
#include <qtextcodec.h>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("GBK"));

	chanEditor w;
	w.show();
	return a.exec();
}
