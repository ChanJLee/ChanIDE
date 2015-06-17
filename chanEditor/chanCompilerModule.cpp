#include "chanCompilerModule.h"
#include <qstringlist.h>
#include <qmessagebox.h>

void chanCompilerModule::build(const QStringList& fileNames, const QString& dec){

	//默认 gcc 
	QStringList arg;

	std::for_each(fileNames.cbegin(), fileNames.cend(), [&](const QString& fileName){
		arg << fileName;
	});

	arg << "-o" << dec;

	m_successCount = fileNames.size();
	m_errorCount = 0;

	m_process.start("g++",arg);
}

void chanCompilerModule::finish(){

	m_process.close();

	emit result(tr("========== realeased:  successed %1 , failed %2 , updated 0 , skipped 0 ==========").
		arg(QString::number(m_successCount)).
		arg(QString::number(m_errorCount)));

	emit finished(true);
}

void chanCompilerModule::getResults(){
	
	++m_errorCount;
	m_successCount = 0;

	emit result(QString::fromLocal8Bit(m_process.readAllStandardError()));
}