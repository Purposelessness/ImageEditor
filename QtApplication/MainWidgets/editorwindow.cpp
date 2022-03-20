#include "editorwindow.h"

#include <QGuiApplication>
#include <QPalette>

EditorWindow::EditorWindow(QWidget *parent) : QMainWindow(parent), imageViewer(new ImageViewer(this)),
                                              toolBar(new ToolBar(this)), toolDock(new ToolDock(this)) {
    resize(1200, 720);
    setCentralWidget(imageViewer);
    addToolBar(Qt::TopToolBarArea, toolBar);
    addDockWidget(Qt::RightDockWidgetArea, toolDock);
    createActions();
}

void EditorWindow::createActions() {
    auto fileMenu = new QMenu(tr("&File"));
    menuBar()->addMenu(fileMenu);
    auto open = new QAction(tr("&Open"));
    fileMenu->addAction(open);
    auto save = new QAction(tr("Save As"));
    save->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    fileMenu->addAction(save);
    auto showDock = new QAction(tr("&ToolDock"));
    connect(showDock, SIGNAL(triggered(bool)), toolDock, SLOT(show()));
    menuBar()->addAction(showDock);
}