#ifndef IMAGEEDITOR_EDITORWINDOW_H
#define IMAGEEDITOR_EDITORWINDOW_H

#include "ImageViewer/imageviewer.h"
#include "ToolBar/toolbar.h"
#include "ToolDock/tooldock.h"

#include <QMainWindow>
#include <QMenuBar>

class EditorWindow : public QMainWindow {
public:
    explicit EditorWindow(QWidget *parent = Q_NULLPTR);

private:
    void createActions();

    ImageViewer *imageViewer;
    ToolBar *toolBar;
    ToolDock *toolDock;
};

#endif //IMAGEEDITOR_EDITORWINDOW_H
