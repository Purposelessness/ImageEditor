#include "editorwindowview.h"

#include <QStandardPaths>
#include <QDir>
#include <QFileDialog>

EditorWindowView::EditorWindowView(QWidget *parent) : QMainWindow(parent) {
    resize(1200, 720);
    createActions();
    show();
}

void EditorWindowView::createActions() {
    auto fileMenu = new QMenu(tr("&File"));
    menuBar()->addMenu(fileMenu);

    auto open = new QAction(tr("&Open"));
    connect(open, SIGNAL(triggered(bool)), this, SLOT(onOpenActionTriggered()));
    fileMenu->addAction(open);
    auto save = new QAction(tr("Save As"));
    connect(save, SIGNAL(triggered(bool)), this, SLOT(onSaveActionTriggered()));
    save->setShortcut(Qt::CTRL | Qt::SHIFT | Qt::Key_S);
    fileMenu->addAction(save);
    auto showDock = new QAction(tr("&ToolDock"));
    connect(showDock, SIGNAL(triggered(bool)), this, SLOT(onShowDockActionTriggered()));
    menuBar()->addAction(showDock);
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
