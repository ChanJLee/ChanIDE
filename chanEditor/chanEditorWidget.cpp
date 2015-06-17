#include "chanEditorWidget.h"
#include <qfiledialog.h>
#include <qfile.h>
#include <qdatastream.h>
#include <qmessagebox.h>
#include <Qsci\qscilexercpp.h>
#include <qevent.h>
#include <qfileinfo.h>
#include <qiodevice.h>

chanEditorWidget::chanEditorWidget(QWidget* parent)
	:QsciScintilla(parent),
	m_isUntitled(true),
	m_action(NULL){
	init();
}

void chanEditorWidget::init(){
	m_action = new QAction(this);

	m_action->setCheckable(true);

	connect(m_action, SIGNAL(triggered()), this, SLOT(show()));
	connect(m_action, SIGNAL(triggered()), this, SLOT(setFocus()));

	connect(this, SIGNAL(textChanged()), this, SLOT(documentWasModified()));


	QsciLexerCPP* lexer = new QsciLexerCPP(this);

	setLexer(lexer);

	//设置边框行号
	setMarginLineNumbers(1, true);

	//精确的括号匹配
	setBraceMatching(QsciScintilla::BraceMatch::StrictBraceMatch);

	//设置折叠
	setFolding(QsciScintilla::FoldStyle::CircledTreeFoldStyle);

	//设置自动填充有效
	setAutoCompletionFillupsEnabled(true);

	//所有可能的来源
	setAutoCompletionSource(QsciScintilla::AcsAll);

	//补字符号
	setCaretLineVisible(true);

	setAutoIndent(true);

	setUtf8(true);

	setWhitespaceVisibility(QsciScintilla::WsVisible);

	setAttribute(Qt::WA_DeleteOnClose);
}

void chanEditorWidget::documentWasModified(){

	setWindowModified(true);

	emit undoAvailable(isUndoAvailable());
	emit redoAvailable(isRedoAvailable());

	setTitle();
}

void chanEditorWidget::setTitle(){

	if (isWindowModified()){
		setWindowTitle(tr("%1 %2").arg(strippedName(m_curFileName)).arg("*"));
	}
	else{
		setWindowTitle(strippedName(m_curFileName));
	}
}

void chanEditorWidget::newFile(const QString& fileName){

	if (!fileName.isEmpty()){
		saveFile(fileName);
		return;
	}

	static unsigned short docNum = 0x0001u;

	m_curFileName = tr("untitled%1").arg(docNum);
	setTitle();

	setActionText(m_curFileName);

	++docNum;
}

chanEditorWidget* chanEditorWidget::open(QWidget* parent){

	QString fileName = QFileDialog::getOpenFileName(parent, tr("open"), ".", tr(
		"c/c++ header file(*.h)\n"
		"c/c++ header file(*.hpp)\n"
		"c source file(*.c)\n"
		"c++ source file(*.cpp)"));

	if (fileName.isEmpty()) return NULL;

	return openFile(fileName, parent);
}

chanEditorWidget* chanEditorWidget::openFile(const QString& fileName, QWidget* parent){

	chanEditorWidget* widget = new chanEditorWidget(parent);

	if (widget->openFile(fileName)){

		widget->setCurrentFile(fileName);
		widget->setActionText(fileName);
		widget->setTitle();
		return widget;
	}

	delete widget;
	return NULL;
}


bool chanEditorWidget::save(){

	if (m_isUntitled)
		return saveAs();

	return saveFile(m_curFileName);
}

bool chanEditorWidget::saveAs(){

	QString fileName = QFileDialog::getSaveFileName(this, tr("save as"), ".",
		tr("c/c++ header file(*.h)\n"
		"c/c++ header file(*.hpp)\n"
		"c source file(*.c)\n"
		"c++ source file(*.cpp)"
		));

	if (fileName.isEmpty()) return false;

	return saveFile(fileName);
}

bool chanEditorWidget::saveFile(const QString& fileName){
	QFile file(fileName);

	if (!file.open(QIODevice::WriteOnly)){
		QMessageBox::warning(this, "chan editer",
			tr("failed to save the file %1").arg(m_curFileName));
		return false;
	}

	if (write(&file)){

		file.close();

		m_isUntitled = false;

		setWindowModified(false);

		setCurrentFile(fileName);
		setActionText(fileName);

		setTitle();

		return true;
	}

	return false;
}

bool chanEditorWidget::openFile(const QString& fileName){

	QFile file(fileName);

	if (!file.open(QIODevice::ReadOnly)){
		QMessageBox::warning(this, "chan editer",
			tr("failed to open the file %1").arg(m_curFileName));

		return false;
	}

	if (read(&file)){

		file.close();

		m_isUntitled = false;
		setWindowModified(false);
		setCurrentFile(fileName);

		setActionText(fileName);
		setTitle();
		return true;
	}

	return false;
}


void chanEditorWidget::closeEvent(QCloseEvent* event){
	if (okToContinue()){
		event->accept();
	}

	else event->ignore();
}

bool chanEditorWidget::okToContinue(){

	if (isWindowModified()){
		int result = QMessageBox::warning(this, tr("chan Editer"),
			tr("the document has been modified.\n"
			"Do you want to save your changes?"),
			QMessageBox::Yes | QMessageBox::No |
			QMessageBox::Cancel);

		if (result == QMessageBox::Yes)
			return save();

		else if (result == QMessageBox::Cancel)
			return false;
	}

	return true;
}

QString chanEditorWidget::strippedName(const QString& fileName){
	return QFileInfo(fileName).fileName();
}

void chanEditorWidget::setFileName(const QString& fileName){
	
	setCurrentFile(fileName);
	setTitle();
}