#if !defined __CHAN__OUTPUT__TEXT__EDIT__H__
#define __CHAN__OUTPUT__TEXT__EDIT__H__

#if defined _MSC_VER && _MSC_VER > 1000
	#pragma once
#endif

#include <qtextedit.h>


/**
*	��ʵ��QTextEdit ʹ֮�ܹ���ȡ�ض������ڵ��ı�	
*/
class chanOutputTextEdit :public QTextEdit{

	Q_OBJECT

public:
	chanOutputTextEdit(QWidget* = NULL);

protected:
	void keyPressEvent(QKeyEvent*);

public slots:
	void storeCurrentCursor(){
		m_prevCursor = textCursor();
	}

signals:
	void inputedString(const QString&);

private:
	QTextCursor m_prevCursor;
};


#endif