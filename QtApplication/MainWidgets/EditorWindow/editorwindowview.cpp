#include "editorwindowview.h"

#include <QStandardPaths>
#include <QDir>

EditorWindowView::EditorWindowView(QWidget *parent) : QMainWindow(parent) {
    resize(1200, 720);
    createActions();
    show();
}

void EditorWindowView::createActions() {
    auto fileMenu = menuBar()->addMenu(tr("&File"));

    fileMenu->addAction(tr("&Open"), this, SLOT(onOpenActionTriggered()));
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
