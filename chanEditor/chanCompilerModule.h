#if !defined __CHAN__COMPILER__MODULE__H__
#define __CHAN__COMPILER__MODULE__H__

#if defined _MSC_VER && _MSC_VER > 1000
	#pragma once
#endif

#include <qstring.h>
#include <qprocess.h>
#include <qobject.h>

class QStringList;

class chanCompilerModule:public QObject{
	Q_OBJECT

public:
	static chanCompilerModule& getCompilerModule(){
		static chanCompilerModule module;
		return module;
	}	

public slots:
	void getResults();
	void finish();
	void build(const QStringList&, const QString&);

private:
	chanCompilerModule(){

		connect(&m_process, SIGNAL(readyReadStandardError()), this, SLOT(getResults()));
		connect(&m_process, SIGNAL(finished(int,QProcess::ExitStatus)), this, SLOT(finish()));
	}

	chanCompilerModule(const chanCompilerModule&) = delete;
	chanCompilerModule& operator=(const chanCompilerModule&) = delete;

signals:
	void finished(bool);
	void result(const QString&);

private:
	size_t		 m_errorCount;
	size_t		 m_successCount;
	QProcess m_process;
};

#endif