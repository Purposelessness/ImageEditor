#include "editorwindowview.h"

#include <QStandardPaths>
#include <QDir>

EditorWindowView::EditorWindowView(QWidget *parent) : QMainWindow(parent), imageViewer(new ImageViewer()),
                                                      toolBar(new ToolBar()), toolDock(new ToolDock()) {
    resize(1200, 720);
    createActions();
    setCentralWidget(imageViewer->getView());
    addToolBar(Qt::TopToolBarArea, toolBar);
    addDockWidget(Qt::RightDockWidgetArea, toolDock);
}

void EditorWindowView::createActions() {
    auto fileMenu = menuBar()->addMenu(tr("&File"));

    useLibAct = new QAction(tr("Use lib"));
    useLibAct->setCheckable(true);
    fileMenu->addAction(useLibAct);
    auto open = fileMenu->addAction(tr("&Open"), this, SLOT(onOpenActionTriggered()));
    open->setShortcut(Qt::CTRL | Qt::Key_O);
    auto save = fileMenu->addAction(tr("Save As"), this, SLOT(onSaveActionTriggered()));
    save->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);

    menuBar()->addAction(tr("&ToolDock"), this, SLOT(onShowDockActionTriggered()));
}

void EditorWindowView::onOpenActionTriggered() {
    emit openActionTriggered();
}

void EditorWindowView::onSaveActionTriggered() {
    emit saveActionTriggered();
}

void EditorWindowView::onShowDockActionTriggered() {
    emit showDockActionTriggered();
}
