/********************************************************************************
** Form generated from reading UI file 'chanEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANEDITOR_H
#define UI_CHANEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "../../chanOutputTextEdit.h"

QT_BEGIN_NAMESPACE

class Ui_chanEditorClass
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *m_outputDockWidget;
    QWidget *dockWidgetContents_5;
    QHBoxLayout *horizontalLayout;
    chanOutputTextEdit *m_outputTextEdit;

    void setupUi(QMainWindow *chanEditorClass)
    {
        if (chanEditorClass->objectName().isEmpty())
            chanEditorClass->setObjectName(QStringLiteral("chanEditorClass"));
        chanEditorClass->resize(1113, 688);
        chanEditorClass->setMinimumSize(QSize(1113, 688));
        centralWidget = new QWidget(chanEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        chanEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(chanEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1113, 23));
        chanEditorClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(chanEditorClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        chanEditorClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(chanEditorClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        chanEditorClass->setStatusBar(statusBar);
        m_outputDockWidget = new QDockWidget(chanEditorClass);
        m_outputDockWidget->setObjectName(QStringLiteral("m_outputDockWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_outputDockWidget->sizePolicy().hasHeightForWidth());
        m_outputDockWidget->setSizePolicy(sizePolicy);
        m_outputDockWidget->setMinimumSize(QSize(1113, 159));
        dockWidgetContents_5 = new QWidget();
        dockWidgetContents_5->setObjectName(QStringLiteral("dockWidgetContents_5"));
        horizontalLayout = new QHBoxLayout(dockWidgetContents_5);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_outputTextEdit = new chanOutputTextEdit(dockWidgetContents_5);
        m_outputTextEdit->setObjectName(QStringLiteral("m_outputTextEdit"));

        horizontalLayout->addWidget(m_outputTextEdit);

        m_outputDockWidget->setWidget(dockWidgetContents_5);
        chanEditorClass->addDockWidget(static_cast<Qt::DockWidgetArea>(8), m_outputDockWidget);

        retranslateUi(chanEditorClass);

        QMetaObject::connectSlotsByName(chanEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *chanEditorClass)
    {
        chanEditorClass->setWindowTitle(QApplication::translate("chanEditorClass", "chanEditor", 0));
        m_outputDockWidget->setWindowTitle(QApplication::translate("chanEditorClass", "output", 0));
    } // retranslateUi

};

namespace Ui {
    class chanEditorClass: public Ui_chanEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANEDITOR_H
