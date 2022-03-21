#ifndef IMAGEEDITOR_EDITORWINDOW_H
#define IMAGEEDITOR_EDITORWINDOW_H

#include "editorwindowview.h"
#include "editorwindowmodel.h"

#include <QObject>

class EditorWindow : QObject {
Q_OBJECT

public:
    explicit EditorWindow(QWidget* parent = Q_NULLPTR);

private slots:
    void onOpenFile();
    void onSaveFile();
    void onShowDock();

private:
    EditorWindowView *view;
    EditorWindowModel *model;
};


#endif //IMAGEEDITOR_EDITORWINDOW_H
