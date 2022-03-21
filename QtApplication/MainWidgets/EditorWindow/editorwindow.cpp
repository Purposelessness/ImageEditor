#include "editorwindow.h"

EditorWindow::EditorWindow(QWidget *parent) : view(new EditorWindowView(parent)), model(new EditorWindowModel(view)) {
    connect(view, SIGNAL(openActionTriggered()), this, SLOT(onOpenFile()));
    connect(view, SIGNAL(saveActionTriggered()), this, SLOT(onSaveFile()));
    connect(view, SIGNAL(showDockActionTriggered()), this, SLOT(onShowDock()));
}

void EditorWindow::onOpenFile() {
    model->openFile();
}

void EditorWindow::onSaveFile() {
    model->saveFile();
}

void EditorWindow::onShowDock() {
    model->showDock();
}
