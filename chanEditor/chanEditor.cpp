#include "chanEditor.h"
#include <qmdiarea.h>
#include <qicon.h>
#include <qtimer.h>
#include <qmenu.h>
#include <algorithm>
#include "chanEditorWidget.h"
#include <qmdisubwindow.h>
#include <qmessagebox.h>
#include <qevent.h>
#include "chanFileSystemDockWidget.h"
#include <qfiledialog.h>
#include "chanRuntimeEnvironment.h"
#include "chanCompilerModule.h"

chanEditor::chanEditor(QWidget *parent)
	: QMainWindow(parent),
	m_fileSystemDockWidget(NULL),
	m_compilerModule(&chanCompilerModule::getCompilerModule()),
	m_runtimeEnvironment(&chanRuntimeEnvironment::getRuntimeEnvironment()){
	ui.setupUi(this);

	//做一些初始化工作
	init();
}

template <typename ParentPtr, typename ShortCutType>
void chanEditor::releaseAction(QAction*& pAction, ParentPtr pParent,
	const char* const pTitle, const char* const pIconFileName,
	ShortCutType shortCut, const char* const pStatusTip){

	//产生QAction
	pAction = new QAction(tr(pTitle), pParent);

	//如果有图标 则加图标
	if (pIconFileName != NULL)
		pAction->setIcon(QIcon(pIconFileName));

	//设置快捷键
	pAction->setShortcut(shortCut);

	//设置状态提示
	pAction->setStatusTip(tr(pStatusTip));
}


void chanEditor::init(){

	//分配多用户界面
	m_mdiArea = new QMdiArea(this);

	//设置中央组件
	setCentralWidget(m_mdiArea);

	//如果窗口发生变化，那么就要更新action 比如 重做按钮，此时可能设置为无效
	connect(m_mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)),
		this, SLOT(updateActions()));

	//创建所需要的所有组件
	createWidgets();

	//创建菜单栏
	createMenuBar();

	//创建工具栏
	createToolBar();

	//设置输出信息栏
	setOutputDockWidget();

	//设置窗口的图标
	setWindowIcon(QIcon(resourceFileName::pWindow));

	//设置窗口的标题
	setWindowTitle(tr("Chan Editor - %1").arg(CE_VER));
}

void chanEditor::createWidgets(){

	createActionGroups();

	//生成一系列的actions
	createFileActions();
	createEditActions();
	createWindowActions();
	createProjectActions();
	createOptionActions();
	createHelpActions();
}

void chanEditor::createFileActions(){

	releaseAction(m_newProjectAction, this, "&New Project", resourceFileName::pNew, QKeySequence::New,
		"create a new project");
	connect(m_newProjectAction, SIGNAL(triggered()), this, SLOT(createFileSystemDockWidget()));

	releaseAction(m_saveAction, this, "&Save", resourceFileName::pSave, QKeySequence::Save,
		"save the file");
	connect(m_saveAction, SIGNAL(triggered()), this, SLOT(save()));

	releaseAction(m_saveAsAction, this, "Save &As", resourceFileName::pSaveAs, QKeySequence::SaveAs,
		"save as");
	connect(m_saveAsAction, SIGNAL(triggered()), this, SLOT(saveAs()));

	releaseAction(m_exitAction, this, "&Exit", resourceFileName::pExit, QKeySequence::Close,
		"close chan editer");
	connect(m_exitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void chanEditor::createEditActions(){
	releaseAction(m_undoAction, this, "&Undo", resourceFileName::pUndo, QKeySequence::Undo,
		"undo");
	connect(m_undoAction, SIGNAL(triggered()), this, SLOT(undo()));

	releaseAction(m_redoAction, this, "&Redo", resourceFileName::pRedo, QKeySequence::Redo,
		"redo");
	connect(m_redoAction, SIGNAL(triggered()), this, SLOT(redo()));

	releaseAction(m_cutAction, this, "&Cut", resourceFileName::pCut, QKeySequence::Cut,
		"cut");
	connect(m_cutAction, SIGNAL(triggered()), this, SLOT(cut()));

	releaseAction(m_copyAction, this, "C&opy", resourceFileName::pCopy, QKeySequence::Copy,
		"copy");
	connect(m_copyAction, SIGNAL(triggered()), this, SLOT(copy()));

	releaseAction(m_pasteAction, this, "&Paste", resourceFileName::pPaste, QKeySequence::Paste,
		"paste");
	connect(m_pasteAction, SIGNAL(triggered()), this, SLOT(paste()));
}

void chanEditor::createWindowActions(){
	releaseAction(m_closeAction, this, "&Close", resourceFileName::pClose, tr(""),
		"close current window");
	connect(m_closeAction, SIGNAL(triggered()), m_mdiArea, SLOT(closeActiveSubWindow()));

	releaseAction(m_closeAllAction, this, "Close &All", resourceFileName::pCloseAll, tr(""),
		"close all the windows");
	connect(m_closeAllAction, SIGNAL(triggered()), m_mdiArea, SLOT(closeAllSubWindows()));

	releaseAction(m_tileAction, this, "&Tile", NULL, tr(""),
		"tile sub windows");
	connect(m_tileAction, SIGNAL(triggered()), m_mdiArea, SLOT(tileSubWindows()));

	releaseAction(m_cascadeAction, this, "Ca&scade", NULL, tr(""),
		"cascade sub windows");
	connect(m_cascadeAction, SIGNAL(triggered()), m_mdiArea, SLOT(cascadeSubWindows()));

	releaseAction(m_nextAction, this, "&Next", resourceFileName::pNext, tr(""),
		"activate next sub window");
	connect(m_nextAction, SIGNAL(triggered()), m_mdiArea, SLOT(activateNextSubWindow()));

	releaseAction(m_prevAction, this, "&Previous", resourceFileName::pPrev, tr(""),
		"ctivate previous sub window");
	connect(m_prevAction, SIGNAL(triggered()), m_mdiArea, SLOT(activatePreviousSubWindow()));
}

//最后修改时间  2015/2/25 14：18
void chanEditor::createProjectActions(){
	
	releaseAction(m_buildAction, this, "&Build", resourceFileName::pBuild, tr("F7"), 
		"build");
	connect(m_buildAction, SIGNAL(triggered()), this, SLOT(build()));
	connect(m_compilerModule, SIGNAL(finished(bool)), m_buildAction, SLOT(setEnabled(bool)));

	releaseAction(m_runAction, this, "&Run", resourceFileName::pRun, tr("F5"), 
		"run");
	connect(m_runAction, SIGNAL(triggered()), this, SLOT(run()));
	connect(m_runtimeEnvironment, SIGNAL(finished(bool)), m_runAction, SLOT(setEnabled(bool)));

	releaseAction(m_shutDownAction, this, "&Shut Down", resourceFileName::pShutDown, tr("F4"),
		"shut down");
	connect(m_shutDownAction, SIGNAL(triggered()), this, SLOT(shutDown()));
	m_shutDownAction->setEnabled(false);
}

void chanEditor::createOptionActions(){
	releaseAction(m_wsvAction, this, "&Whitespace Visibility", NULL, tr(""),
		"set whitespace visibility");
	m_wsvAction->setCheckable(true);
	m_wsvAction->setChecked(true);
	connect(m_wsvAction, SIGNAL(toggled(bool)), this, SLOT(setWhitespaceVisibility(bool)));
}

void chanEditor::createHelpActions(){
	releaseAction(m_aboutMeAction, this, "About &Me", resourceFileName::pAboutMe, tr(""),
		"about chan editer");
	connect(m_aboutMeAction, SIGNAL(triggered()), this, SLOT(aboutMe()));

	releaseAction(m_aboutQtAction, this, "About &Qt", resourceFileName::pAboutQt, tr(""),
		"about qt");
	connect(m_aboutQtAction, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void chanEditor::createActionGroups(){
	//生成action groups
	m_actionGroup = new QActionGroup(this);
}

void chanEditor::createMenuBar(){

	createFileMenu();
	createEditMenu();
	createWindowMenu();
	createProjectMenu();
	createOptionMenu();
	createHelpMenu();
}

void chanEditor::createFileMenu(){

	QMenu* menu = menuBar()->addMenu(tr("&File"));

	menu->addAction(m_newProjectAction);
	menu->addAction(m_saveAction);
	menu->addAction(m_saveAsAction);
	menu->addAction(m_exitAction);
}

void chanEditor::createEditMenu(){

	QMenu* menu = menuBar()->addMenu(tr("&Edit"));

	menu->addAction(m_undoAction);
	menu->addAction(m_redoAction);
	menu->addAction(m_cutAction);
	menu->addAction(m_copyAction);
	menu->addAction(m_pasteAction);
}

void chanEditor::createWindowMenu(){

	m_windowMenu = menuBar()->addMenu(tr("&Window"));

	m_windowMenu->addAction(m_closeAction);
	m_windowMenu->addAction(m_closeAllAction);

	//添加分隔
	m_windowMenu->addSeparator();

	m_windowMenu->addAction(m_tileAction);
	m_windowMenu->addAction(m_cascadeAction);

	//添加分隔
	m_windowMenu->addSeparator();

	m_windowMenu->addAction(m_nextAction);
	m_windowMenu->addAction(m_prevAction);

	//添加分隔符
	m_windowMenu->addSeparator();
}

void chanEditor::createProjectMenu(){

	QMenu* menu = menuBar()->addMenu(tr("&Project"));

	menu->addAction(m_buildAction);
	menu->addAction(m_runAction);
	menu->addAction(m_shutDownAction);
}

void chanEditor::createOptionMenu(){
	QMenu* menu = menuBar()->addMenu(tr("&Option"));

	menu->addAction(m_wsvAction);
}

void chanEditor::createHelpMenu(){

	QMenu* menu = menuBar()->addMenu(tr("&Help"));

	menu->addAction(m_aboutMeAction);
	menu->addAction(m_aboutQtAction);
}

void chanEditor::createToolBar(){

	createFileToolBar();
	createEditToolBar();
	createProjectToolBar();
}

void chanEditor::createFileToolBar(){

	QToolBar* toolBar = addToolBar(tr("&File"));

	toolBar->addAction(m_saveAction);
	toolBar->addAction(m_saveAsAction);
}

void chanEditor::createEditToolBar(){

	QToolBar* toolBar = addToolBar(tr("&Edit"));

	toolBar->addAction(m_undoAction);
	toolBar->addAction(m_redoAction);
}

void chanEditor::createProjectToolBar(){

	QToolBar* toolBar = addToolBar(tr("&Project"));

	toolBar->addAction(m_buildAction);
	toolBar->addAction(m_runAction);
	toolBar->addAction(m_shutDownAction);
}

void chanEditor::openFile(const QString& fileName){

	chanEditorWidget* widget = chanEditorWidget::openFile(fileName, this);

	if (widget != NULL){
		addChanEditerWidget(widget);
	}
}

void chanEditor::newFile(){

	chanEditorWidget* widget = new chanEditorWidget(this);

	widget->newFile();

	addChanEditerWidget(widget);
}

void chanEditor::open(){

	chanEditorWidget* widget = chanEditorWidget::open(this);

	if (widget != NULL)
		addChanEditerWidget(widget);
}

chanEditorWidget* chanEditor::activeChanEditerWidget(){

	QMdiSubWindow* win = m_mdiArea->activeSubWindow();

	return (win != NULL) ?
		qobject_cast<chanEditorWidget*>(win->widget()) : NULL;
}

void chanEditor::save(){

	//获得当前活跃的窗口
	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->save();
}

void chanEditor::saveAs(){

	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->saveAs();
}

void chanEditor::undo(){

	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->undo();
}

void chanEditor::redo(){

	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->redo();
}

void chanEditor::cut(){
	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->cut();
}

void chanEditor::copy(){

	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->copy();
}

void chanEditor::paste(){
	chanEditorWidget* widget = activeChanEditerWidget();

	if (widget != NULL)
		widget->paste();

}

void chanEditor::aboutMe(){

	QMessageBox::about(this, tr("about chan Editor"),
		tr("<h2> Chan Editer %1 </h2>"
		"<p> Copyright copy 2008 Software Inc."
		"<p>Chan Editer is a small application that\n"
		"demostrates QAction, QMenuBar, QScintilla and many other Qt class."
		"<p>For the exchange of learning,"
		"for commercial purposes is strictly prohibited.").arg(CE_VER));
}

void chanEditor::addChanEditerWidget(chanEditorWidget* widget){

	connect(widget, SIGNAL(undoAvailable(bool)),
		m_undoAction, SLOT(setEnabled(bool)));
	connect(widget, SIGNAL(redoAvailable(bool)),
		m_redoAction, SLOT(setEnabled(bool)));
	connect(widget, SIGNAL(copyAvailable(bool)),
		m_copyAction, SLOT(setEnabled(bool)));
	connect(widget, SIGNAL(copyAvailable(bool)),
		m_cutAction, SLOT(setEnabled(bool)));

	QMdiSubWindow* win = m_mdiArea->addSubWindow(widget);

	m_windowMenu->addAction(widget->windowMenuAction());

	m_actionGroup->addAction(widget->windowMenuAction());

	if (!m_wsvAction->isChecked())
		widget->setWhitespaceVisibility(
		QsciScintilla::WhitespaceVisibility::WsInvisible);

	win->show();
}

void chanEditor::closeEvent(QCloseEvent* event){

	m_mdiArea->closeAllSubWindows();

	if (!m_mdiArea->subWindowList().isEmpty())
		event->ignore();
	else event->accept();
}

void chanEditor::updateActions(){

	chanEditorWidget* widget = activeChanEditerWidget();

	bool hasEditer = (widget != NULL);

	bool hasSelection = (widget != NULL &&
		widget->hasSelectedText());

	m_saveAction->setEnabled(hasEditer);
	m_saveAsAction->setEnabled(hasEditer);

	m_redoAction->setEnabled((hasEditer && widget->isRedoAvailable()));
	m_undoAction->setEnabled((hasEditer && widget->isUndoAvailable()));

	m_cutAction->setEnabled(hasSelection);
	m_copyAction->setEnabled(hasSelection);
	m_pasteAction->setEnabled(hasEditer);

	m_closeAction->setEnabled(hasEditer);
	m_closeAllAction->setEnabled(hasEditer);
	m_tileAction->setEnabled(hasEditer);
	m_cascadeAction->setEnabled(hasEditer);
	m_nextAction->setEnabled(hasEditer);
	m_prevAction->setEnabled(hasEditer);

	if (widget != NULL)
		widget->windowMenuAction()->setChecked(true);
}

void chanEditor::setWhitespaceVisibility(bool isVisibility){

	//设置空白格可见
	QList<QMdiSubWindow*> wins = m_mdiArea->subWindowList();

	if (isVisibility){
		std::for_each(wins.begin(), wins.end(), [](QMdiSubWindow* win){
			qobject_cast<chanEditorWidget*>(win->widget())
				->setWhitespaceVisibility(QsciScintilla::WsVisible);
		});
	}
	else{
		std::for_each(wins.begin(), wins.end(), [](QMdiSubWindow* win){
			qobject_cast<chanEditorWidget*>(win->widget())
				->setWhitespaceVisibility(QsciScintilla::WsInvisible);
		});
	}
}


//最后修改时间  2015/2/22 9:45
void chanEditor::build(){

	m_buildAction->setEnabled(false);
	m_compilerModule->build(cppOrCFileNames(), binaryFileName());
}

void chanEditor::run(){

	m_runAction->setEnabled(false);
	m_shutDownAction->setEnabled(true);
	m_runtimeEnvironment->run(binaryFileName());
}

void chanEditor::shutDown(){

	m_runtimeEnvironment->kill();
}

void chanEditor::setOutputDockWidget(){

	connect(m_compilerModule, SIGNAL(result(const QString&)),
		this, SLOT(addToOutputDockWidget(const QString&)));
	connect(m_runtimeEnvironment, SIGNAL(outputString(const QString&)),
		this, SLOT(addToOutputDockWidget(const QString&)));
	connect(m_runtimeEnvironment, SIGNAL(errorString(const QString&)),
		this, SLOT(addToOutputDockWidget(const QString&)));
	connect(m_runtimeEnvironment, SIGNAL(outputString(const QString&)),
		ui.m_outputTextEdit, SLOT(storeCurrentCursor()));
	connect(m_runtimeEnvironment, SIGNAL(errorString(const QString&)),
		ui.m_outputTextEdit, SLOT(storeCurrentCursor()));
	connect(ui.m_outputTextEdit, SIGNAL(inputedString(const QString&)),
		m_runtimeEnvironment, SLOT(setInputString(const QString&)));
}

void chanEditor::addToOutputDockWidget(const QString& text){

	ui.m_outputTextEdit->append(text);
}

const QStringList chanEditor::cppOrCFileNames(){
	
	QList<QMdiSubWindow*> list = m_mdiArea->subWindowList();
	QStringList result;

	std::for_each(list.begin(), list.end(), [&](QMdiSubWindow* item){

		chanEditorWidget* win = qobject_cast<chanEditorWidget*>(item->widget());
		QFileInfo fileInfo(win->fileName());
		if (fileInfo.completeSuffix() == "cpp" ||
			fileInfo.completeSuffix() == "c")
			result << win->fileName();
	});

	return result;
}

const QString chanEditor::binaryFileName(){

	return (m_cd + "/" + QDir(m_cd).dirName());
}

void chanEditor::createFileSystemDockWidget(){
	
	if (!m_cd.isEmpty()) return;

	m_cd = QFileDialog::getExistingDirectory(this, tr("create project"),
		".",
		QFileDialog::ShowDirsOnly
		| QFileDialog::DontResolveSymlinks);

	if (m_cd.isEmpty())
		return;

	m_fileSystemDockWidget = new chanFileSystemDockWidget(m_cd, this);

	connect(m_fileSystemDockWidget, SIGNAL(removedFile(const QString&)),
		this, SLOT(closeFile(const QString&)));
	connect(m_fileSystemDockWidget, SIGNAL(importedFile(const QString&)),
		this, SLOT(openFile(const QString&)));
	connect(m_fileSystemDockWidget, SIGNAL(renamedFile(const QString&, const QString&)),
		this, SLOT(renameFile(const QString&, const QString&)));
	connect(m_fileSystemDockWidget, SIGNAL(selectedFile(const QString&)),
		this, SLOT(selectFile(const QString&)));
	connect(m_fileSystemDockWidget, SIGNAL(createdFile(const QString&)),
		this, SLOT(openFile(const QString&)));

	m_fileSystemDockWidget->setWindowTitle(tr("Solution Explorer"));
	addDockWidget(Qt::LeftDockWidgetArea, m_fileSystemDockWidget);
	m_fileSystemDockWidget->show();
}


void chanEditor::closeFile(const QString& fileName){

	selectFile(fileName);
	m_mdiArea->closeActiveSubWindow();
}

QMdiSubWindow* chanEditor::findSubWindowByFileName(const QString& fileName){

	QList<QMdiSubWindow*> list = m_mdiArea->subWindowList();

	auto it = std::find_if(list.begin(), list.end(), [&](QMdiSubWindow* item){

		//必须调用widget
		chanEditorWidget* win = qobject_cast<chanEditorWidget*>(item->widget());
		return win->fileName() == fileName;
	});

	return *it;
}

void chanEditor::renameFile(const QString& oFileName, const QString& nFileName){

	chanEditorWidget* win = qobject_cast<chanEditorWidget*>(findSubWindowByFileName(oFileName)->widget());
	win->setFileName(nFileName);
}

void chanEditor::selectFile(const QString& fileName){
	m_mdiArea->setActiveSubWindow(findSubWindowByFileName(fileName));
}
