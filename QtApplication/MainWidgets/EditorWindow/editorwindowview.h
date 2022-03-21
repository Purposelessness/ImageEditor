#ifndef IMAGEEDITOR_EDITORWINDOWVIEW_H
#define IMAGEEDITOR_EDITORWINDOWVIEW_H

#include <QMainWindow>
#include <QMenuBar>

class EditorWindowView : public QMainWindow {
Q_OBJECT

public:
    explicit EditorWindowView(QWidget *parent = Q_NULLPTR);

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
};

#endif //IMAGEEDITOR_EDITORWINDOWVIEW_H
