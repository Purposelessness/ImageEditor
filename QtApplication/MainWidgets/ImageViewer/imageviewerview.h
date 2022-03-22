#ifndef IMAGEEDITOR_IMAGEVIEWERVIEW_H
#define IMAGEEDITOR_IMAGEVIEWERVIEW_H

#include "imagecontainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QToolBar>
#include <QPushButton>

class ImageViewer;

class ImageViewerView : public QWidget {
Q_OBJECT

    friend ImageViewer;

public:
    explicit ImageViewerView(QWidget *parent = Q_NULLPTR);

signals:
    void zoomInActionTriggered();
    void zoomOutActionTriggered();
    void adjustSizeActionTriggered();

private slots:
    void onZoomInActionTriggered();
    void onZoomOutActionTriggered();
    void onAdjustSizeActionTriggered();

private:
    void createActions();
    void setActionsEnabled(bool value);

    QToolBar *toolBar;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *adjustSizeAction;
    ImageContainer *imageContainer;
    QGridLayout *layout;
    QScrollArea *scrollArea;
};


#endif //IMAGEEDITOR_IMAGEVIEWERVIEW_H
