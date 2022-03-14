#ifndef IMAGEEDITOR_EDITORWINDOW_H
#define IMAGEEDITOR_EDITORWINDOW_H

#include "imageviewer.h"
#include "toolbar.h"
#include "tooldock.h"

#include <QMainWindow>

class EditorWindow : public QMainWindow {
public:
    explicit EditorWindow(QWidget *parent = Q_NULLPTR);

private:
    ImageViewer *imageViewer;
    ToolBar *toolBar;
    ToolDock *sideBar;
};

#endif //IMAGEEDITOR_EDITORWINDOW_H
