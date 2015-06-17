#if !defined __CHAN__FILE__SYSTEM__DOCK__WIDGET__H__
#define __CHAN__FILE__SYSTEM__DOCK__WIDGET__H__

#if defined _MSC_VER && _MSC_VER > 1000
	#pragma once
#endif

#include <qdockwidget.h>

class QTreeWidget;
class QTreeWidgetItem;

class chanFileSystemDockWidget :public QDockWidget{
	Q_OBJECT

private:
	const static ushort actionArraySize = 0x0007u;

	//源程序严重依赖这里的顺序 所以不要修改
	enum { RemoveFile, RenameFile, CreateFile, ImportFile, 
		CreateFolder, RemoveFolder, RenameFolder };

	enum itemType { File, Folder };

#	if !defined CHANFILESYSTEMDOCKWIDGET_MOC
#		define CHANFILESYSTEMDOCKWIDGET_MOC
#		define _ITEM_TYPE_KEY		(Qt::UserRole)
#		define ITEM_TYPE_KEY		_ITEM_TYPE_KEY
#		define _FILE_NAME_KEY		(ITEM_TYPE_KEY + 1)
#		define FILE_NAME_KEY		_FILE_NAME_KEY
#		define FOLDER_NAME_KEY		FILE_NAME_KEY
#	endif

public:
	chanFileSystemDockWidget(const QString&,QWidget* = NULL);

private:
	void init();

	void createWidgets();
	void createFileSystemTree();
	void createContextMenu();
	void createTreeWidgetItem(const QString&,QTreeWidgetItem* = NULL);
	void createRoot();

private slots:
	void createFile();
	void removeFile();
	void importFile();
	void renameFile();
	void createFolder();
	void removeFolder();
	void updateActions(QTreeWidgetItem*);
	void renameFolder();

signals:
	void createdFile(const QString&);
	void removedFile(const QString&);
	void importedFile(const QString&);
	void renamedFile(const QString&, const QString&);
	void selectedFile(const QString&);

private:
	QAction*	 m_actionArray[actionArraySize];
	QTreeWidget* m_fileSystemTree;
	QString		 m_home;
};


#endif