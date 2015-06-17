#include "chanFileSystemDockWidget.h"
#include <algorithm>
#include <qaction.h>
#include <qtreewidget.h>
#include <qtreewidget.h>
#include <qfiledialog.h>
#include "resourceFileName.h"
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qfile.h>
#include <qtextstream.h>

chanFileSystemDockWidget::chanFileSystemDockWidget(const QString& home,QWidget* parent)
:QDockWidget(parent),
m_home(home){
	init();
}


void chanFileSystemDockWidget::init(){

	createWidgets();
	createContextMenu();
	createFileSystemTree();
	createRoot();
}

void chanFileSystemDockWidget::createRoot(){

	QTreeWidgetItem* item = new QTreeWidgetItem(m_fileSystemTree);

	item->setData(0, ITEM_TYPE_KEY, Folder);
	item->setData(0, FOLDER_NAME_KEY, m_home);

	//只是显示当前的文件名
	item->setText(0, QDir(m_home).dirName());

	item->setIcon(0, QIcon(resourceFileName::pFolder));
}

void chanFileSystemDockWidget::createWidgets(){

	std::for_each(m_actionArray, m_actionArray + actionArraySize, [this](QAction*& item){
		item = new QAction(this);
		item->setVisible(false);
	});

	m_fileSystemTree = new QTreeWidget(this);
}

void chanFileSystemDockWidget::createContextMenu(){

	m_actionArray[CreateFile]->setText("new file");
	connect(m_actionArray[CreateFile], SIGNAL(triggered()),
		this, SLOT(createFile()));

	m_actionArray[CreateFolder]->setText("new folder");
	connect(m_actionArray[CreateFolder], SIGNAL(triggered()),
		this, SLOT(createFolder()));

	m_actionArray[ImportFile]->setText("import file");
	connect(m_actionArray[ImportFile], SIGNAL(triggered()),
		this, SLOT(importFile()));

	m_actionArray[RemoveFile]->setText("remove file");
	connect(m_actionArray[RemoveFile], SIGNAL(triggered()),
		this, SLOT(removeFile()));

	m_actionArray[RemoveFolder]->setText("remove folder");
	connect(m_actionArray[RemoveFolder], SIGNAL(triggered()),
		this, SLOT(removeFolder()));

	m_actionArray[RenameFile]->setText("rename file");
	connect(m_actionArray[RenameFile], SIGNAL(triggered()),
		this, SLOT(renameFile()));

	m_actionArray[RenameFolder]->setText("rename folder");
	connect(m_actionArray[RenameFolder], SIGNAL(triggered()),
		this, SLOT(renameFolder()));

	std::for_each(m_actionArray, m_actionArray + actionArraySize, [this](QAction* item){
		this->addAction(item);
	});

	setContextMenuPolicy(Qt::ContextMenuPolicy::ActionsContextMenu);
}

void chanFileSystemDockWidget::createFileSystemTree(){

	m_fileSystemTree->setColumnCount(1);
	m_fileSystemTree->setHeaderLabel(tr("project"));

	setWidget(m_fileSystemTree);

	connect(m_fileSystemTree, SIGNAL(itemPressed(QTreeWidgetItem*, int)),
		this, SLOT(updateActions(QTreeWidgetItem*)));
}

void chanFileSystemDockWidget::createFile(){
	
	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	if (items.isEmpty()) return;

	QTreeWidgetItem* parent = items.front();

	QString fileName = QFileDialog::getSaveFileName(this, tr("edit name"), ".",
		tr("c/c++ header file(*.h)\n"
		"c/c++ header file(*.hpp)\n"
		"c source file(*.c)\n"
		"c++ source file(*.cpp)"
		));

	if (!QFile(fileName).open(QIODevice::WriteOnly)){
		QMessageBox::warning(this, "error", 
			tr("create the file %1 failed").arg(fileName));

		return;
	}

	createTreeWidgetItem(fileName, parent);

	emit createdFile(fileName);
}

void chanFileSystemDockWidget::createTreeWidgetItem(const QString& fileName, QTreeWidgetItem* parent){

	QTreeWidgetItem* child = NULL;
	
	child = parent == NULL ?
		new QTreeWidgetItem(m_fileSystemTree) :
		new QTreeWidgetItem(parent);

	QFileInfo info(fileName);
	child->setData(0, ITEM_TYPE_KEY,File);
	child->setData(0, FILE_NAME_KEY, fileName);
	child->setText(0, info.completeBaseName());

	QString suffix = info.completeSuffix();
	if (suffix == "c")
		child->setIcon(0, QIcon(resourceFileName::pC));

	else if (suffix == "cpp")
		child->setIcon(0, QIcon(resourceFileName::pCpp));

	else if (suffix == "h" || suffix == "hpp")
		child->setIcon(0, QIcon(resourceFileName::pH));
}

void chanFileSystemDockWidget::createFolder(){

	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	QString folderName;
	QString path;
	QDir dir;

	folderName = QInputDialog::getText(this, "set folder's name", "enter name:");
	path = m_home + QDir::separator() + folderName;

	//修改硬盘中的数据
	if (!dir.mkdir(path)){
		QMessageBox::warning(this, tr("error"),
			tr("make directory %1 failed").arg(folderName));
		return;
	}
	
	QTreeWidgetItem* item = items.empty() ?
		new QTreeWidgetItem(m_fileSystemTree) :
		new QTreeWidgetItem(items.front());

	item->setData(0, ITEM_TYPE_KEY, Folder);
	item->setData(0, FOLDER_NAME_KEY,path);
	item->setText(0, folderName);

	item->setIcon(0, QIcon(resourceFileName::pFolder));
}


void chanFileSystemDockWidget::importFile(){

	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	if (items.empty() || (items.front()->data(0, ITEM_TYPE_KEY).toInt() == File))
		return;

	QString fileName = QFileDialog::getOpenFileName(this, tr("open"), ".", tr(
		"c/c++ header file(*.h)\n"
		"c/c++ header file(*.hpp)\n"
		"c source file(*.c)\n"
		"c++ source file(*.cpp)"));

	if (fileName.isEmpty()) return;

	createTreeWidgetItem(fileName, items.front());

	emit importedFile(fileName);
}

void chanFileSystemDockWidget::removeFile(){

	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	std::for_each(items.begin(), items.end(), [this](QTreeWidgetItem* item){

		emit removedFile(item->text(0));

		//修改硬盘中的数据
		QFile().remove(item->data(0, FILE_NAME_KEY).toString());
		delete item;
	});
}

void chanFileSystemDockWidget::removeFolder(){

	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	//跟节点不可以被删除
	if (!items.isEmpty() && (m_fileSystemTree->itemAbove(items.front()) == NULL)){
		return;
	}

	std::for_each(items.begin(), items.end(), [this](QTreeWidgetItem* item){
		
		QList<QTreeWidgetItem*> list = item->takeChildren();

		std::for_each(list.begin(), list.end(), [this](QTreeWidgetItem* item){
			
			emit removedFile(item->text(0));
			delete item; 
		});

		//删除硬盘中的目录 及其子项
		QDir(item->data(0, FOLDER_NAME_KEY).toString()).removeRecursively();
		delete item;
	});
}

void chanFileSystemDockWidget::renameFile(){

	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();

	if (items.isEmpty()) return;

	QTreeWidgetItem* parent = items.front();

	QString fileName = QFileDialog::getSaveFileName(this, tr("edit name"), ".",
		tr("c/c++ header file(*.h)\n"
		"c/c++ header file(*.hpp)\n"
		"c source file(*.c)\n"
		"c++ source file(*.cpp)"
		));

	if (fileName.isEmpty()) return;

	QTreeWidgetItem* item = items.front();

	//修改了硬盘中的数据
	if (!QFile::rename(item->data(0, FILE_NAME_KEY).toString(), fileName)){
		QMessageBox::warning(this, "error", "failed to rename the file");
		return;
	}

	if (QFile().exists(fileName)){
		QMessageBox::warning(this, tr("error"), tr("failed to rename the file"));
		return;
	}

	//发射修改了的信号
	emit renamedFile(item->data(0, FILE_NAME_KEY).toString(), fileName);

	QFileInfo info(fileName);

	item->setData(0, FILE_NAME_KEY, fileName);
	item->setText(0, info.completeBaseName());

	QString suffix = info.completeSuffix();
	if (suffix == "c")
		item->setIcon(0, QIcon(resourceFileName::pC));
	else if (suffix == "cpp")
		item->setIcon(0, QIcon(resourceFileName::pCpp));
	else if (suffix == "h" || suffix == "hpp")
		item->setIcon(0, QIcon(resourceFileName::pH));
}

void chanFileSystemDockWidget::renameFolder(){

	//之前这里一直获得的都是size == 0 原因在于context menu设置不正确
	//那个错误的设置是remove folder 但是却导致了这里始终接受的items.size() == 0
	QList<QTreeWidgetItem*> items = m_fileSystemTree->selectedItems();
	QTreeWidgetItem* item = items.front();

	//根节点不可修改名字
	if (m_fileSystemTree->itemAbove(item) == NULL){
		return;
	}

	QString folderName;
	QString path;
	QDir dir;

	folderName = QInputDialog::getText(this, "set folder's name", "enter name:");
	path = m_home + QDir::separator() + folderName;

	if (!QDir().rename(item->data(0, FOLDER_NAME_KEY).toString(), (path))){
		QMessageBox::warning(this, tr("error"),
			tr("failed to rename the folder!"));
		return;	
	}

	item->setData(0, FOLDER_NAME_KEY, path);
	item->setText(0, folderName);
}

//最后修改时间 2015/2/22 21:50
void chanFileSystemDockWidget::updateActions(QTreeWidgetItem* item){

	//默认选中的是文件夹
	bool isFilesActionsVisible	= false;
	bool isFoldersActionsVisible = true;

	//如果选择的是文件 
	if ((item->data(0, ITEM_TYPE_KEY).toInt() == File)){
		isFilesActionsVisible	= true;
		isFoldersActionsVisible  = false;

		emit selectedFile((item->data(0, FILE_NAME_KEY).toString()));
	}

	std::for_each(m_actionArray, m_actionArray + CreateFile, [&](QAction* item){
		item->setVisible(isFilesActionsVisible);
	});

	std::for_each(m_actionArray + CreateFile, m_actionArray + actionArraySize, [&](QAction* item){
		item->setVisible(isFoldersActionsVisible);
	});
}