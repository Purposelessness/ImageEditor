#ifndef IMAGEEDITOR_EDITORWINDOW_H
#define IMAGEEDITOR_EDITORWINDOW_H

#include "editorwindowview.h"
#include "../ImageViewer/imageviewer.h"
#include "../ToolBar/toolbar.h"
#include "../ToolDock/tooldock.h"

#include <QObject>
#include <QFuture>

class EditorWindow : QObject {
Q_OBJECT

public:
    explicit EditorWindow(QWidget *parent = nullptr);

public slots:
    void openImage(bool temp = false);
    void openTempImage();
    void saveImage(bool temp = false);
    void showDock();

private:
    EditorWindowView *view;
    bool openTempFlag = false;

    QString imagePath;
};


#endif //IMAGEEDITOR_EDITORWINDOW_H
