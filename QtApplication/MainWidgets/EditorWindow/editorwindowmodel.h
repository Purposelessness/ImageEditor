#ifndef IMAGEEDITOR_EDITORWINDOWMODEL_H
#define IMAGEEDITOR_EDITORWINDOWMODEL_H

#include "../ImageViewer/imageviewer.h"
#include "../ToolBar/toolbar.h"
#include "../ToolDock/tooldock.h"

#include <QMainWindow>
#include <QObject>

class EditorWindowModel {
public:
    explicit EditorWindowModel(QMainWindow *widget = Q_NULLPTR);

    void openFile();
    void saveFile();
    void showDock();

private:
    void loadFile(const QString& fileName);

    QMainWindow *view;
    ImageViewer *imageViewer;
    ToolBar *toolBar;
    ToolDock *toolDock;
};


#endif //IMAGEEDITOR_EDITORWINDOWMODEL_H
