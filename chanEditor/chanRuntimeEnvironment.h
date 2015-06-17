#if !defined __CHAN__RUNTIME__ENVIRONMENT__H__	
#define __CHAN__RUNTIME__ENVIRONMENT__H__

#if defined _MSC_VER && _MSC_VER > 1000
	#pragma once
#endif

#include <qobject.h>
#include <qprocess.h>
#include <qtextcodec.h>

class chanRuntimeEnvironment:public QObject{
	Q_OBJECT

public:
	static chanRuntimeEnvironment& getRuntimeEnvironment(){
		static chanRuntimeEnvironment object;
		return object;
	}

signals:
	void outputString(const QString&);
	void errorString(const QString&);
	void finished(bool);

public slots:
	void run(const QString&);
	void kill();

private:
	chanRuntimeEnvironment():m_textCodec(QTextCodec::codecForLocale()){
		connect(&m_process, SIGNAL(finished(int, QProcess::ExitStatus)), this, SLOT(finish()));
		connect(&m_process, SIGNAL(readyReadStandardError()), this, SLOT(getErrorString()));
		connect(&m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(getOutputString()));

	}

	chanRuntimeEnvironment(const chanRuntimeEnvironment&) = delete;
	chanRuntimeEnvironment& operator =(const chanRuntimeEnvironment&) = delete;

private slots:
	void getOutputString();
	void getErrorString();
	void setInputString(const QString&);
	void finish();
	
private:
	QProcess m_process;
	QTextCodec* m_textCodec;
};


#endif