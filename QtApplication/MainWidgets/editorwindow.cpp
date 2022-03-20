#include "editorwindow.h"

#include <QGuiApplication>
#include <QPalette>

EditorWindow::EditorWindow(QWidget *parent) : QMainWindow(parent), imageViewer(new ImageViewer(this)),
                                              toolBar(new ToolBar(this)), toolDock(new ToolDock(this)) {
    resize(1200, 720);
    setCentralWidget(imageViewer);
    addToolBar(Qt::TopToolBarArea, toolBar);
    addDockWidget(Qt::RightDockWidgetArea, toolDock);
}
