#ifndef __CHAN__EDITOR__WIDGET__H__
#define __CHAN__EDITOR__WIDGET__H__

#if defined _MSC_VER && _MSC_VER > 1000
#pragma once
#endif

#include <Qsci\qsciscintilla.h>
#include <qaction.h>

class chanEditorWidget :public QsciScintilla{
	Q_OBJECT

public:
	chanEditorWidget(QWidget* = NULL);

public:
	static chanEditorWidget* open(QWidget*);
	static chanEditorWidget* openFile(const QString&, QWidget*);
	static QString strippedName(const QString&);

	void newFile(const QString& fileName = "");
	bool save();
	bool saveAs();
	QAction* windowMenuAction() { return  m_action; }

	void setFileName(const QString&);
	const QString fileName()const { return m_curFileName; }
protected:
	void closeEvent(QCloseEvent*);

signals:
	void redoAvailable(bool);
	void undoAvailable(bool);

	private slots:
	void documentWasModified();

private:
	void init();

	bool okToContinue();
	bool saveFile(const QString&);
	void setCurrentFile(const QString& fileName){
		m_curFileName = fileName;
	}
	void setActionText(const QString& txt){
		m_action->setText(txt);
	}

	bool openFile(const QString&);

	void setTitle();
private:
	QAction* m_action;
	QString  m_curFileName;
	bool	 m_isUntitled;
};


#endif