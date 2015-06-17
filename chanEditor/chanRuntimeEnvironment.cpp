#include "chanRuntimeEnvironment.h"

void chanRuntimeEnvironment::run(const QString& fileName){

	m_process.start(fileName);

	m_process.setInputChannelMode(QProcess::InputChannelMode::ForwardedInputChannel);
}

void chanRuntimeEnvironment::kill(){

	m_process.kill();
}

void chanRuntimeEnvironment::finish(){

	m_process.close();
	
	emit finished(true);
}

void chanRuntimeEnvironment::getOutputString(){

	emit outputString((QString::fromLocal8Bit(m_process.readAllStandardOutput())));
}

void chanRuntimeEnvironment::getErrorString(){

	emit errorString((QString::fromLocal8Bit(m_process.readAllStandardError())));
}

void chanRuntimeEnvironment::setInputString(const QString& text){

	if (m_process.write(text.toLocal8Bit()) == -1){
		emit errorString("error: failed to input string");

		return;
	}

	//提交数据
	m_process.closeWriteChannel();
}