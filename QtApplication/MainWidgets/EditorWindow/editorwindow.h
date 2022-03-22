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
    explicit EditorWindow(QWidget *parent = Q_NULLPTR);
    ~EditorWindow() override;

private slots:
    void openImage();
    void loadImage(const QString& fileName);
    void saveImage();
    void showDock();

private:
    EditorWindowView *view;

    ImageViewer *imageViewer;
    ToolBar *toolBar;
    ToolDock *toolDock;

    QFuture<QImage> readFuture;
};


#endif //IMAGEEDITOR_EDITORWINDOW_H
