#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include "imagecontainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QToolBar>
#include <QPushButton>

class ImageViewer : public QWidget {
Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    void scale(float factor);

private slots:
    void onZoomInActionTriggered();
    void onZoomOutActionTriggered();
    void onAdjustSizeActionTriggered();

private:
    void adjustScrollBar(QScrollBar *bar, float factor);
    void createActions();
    void setActionsEnabled(bool value);

    QToolBar *toolBar;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *adjustSizeAction;
    ImageContainer *imageContainer;
    QGridLayout *layout;
    QScrollArea *scrollArea;
    float scaleFactor = 1;
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
