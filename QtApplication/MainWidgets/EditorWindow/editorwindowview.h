#ifndef IMAGEEDITOR_EDITORWINDOWVIEW_H
#define IMAGEEDITOR_EDITORWINDOWVIEW_H

#include "../ImageViewer/imageviewer.h"
#include "../ToolBar/toolbar.h"
#include "../ToolDock/tooldock.h"

#include <QMainWindow>
#include <QMenuBar>

class EditorWindow;

class EditorWindowView : public QMainWindow {
Q_OBJECT

    friend EditorWindow;

public:
    explicit EditorWindowView(QWidget *parent = nullptr);

signals:
    void openActionTriggered();
    void saveActionTriggered();
    void showDockActionTriggered();

private slots:
    void onOpenActionTriggered();
    void onSaveActionTriggered();
    void onShowDockActionTriggered();

private:
    void createActions();

    ImageViewer *imageViewer;
    ToolBar *toolBar;
    ToolDock *toolDock;

    QAction *useLibAct = nullptr;
};

#endif //IMAGEEDITOR_EDITORWINDOWVIEW_H
