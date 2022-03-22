#ifndef IMAGEEDITOR_IMAGEVIEWERVIEW_H
#define IMAGEEDITOR_IMAGEVIEWERVIEW_H

#include "imagecontainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QToolBar>
#include <QSlider>

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
    void sliderValueChanged(int value);

private slots:
    void onZoomInActionTriggered();
    void onZoomOutActionTriggered();
    void onAdjustSizeActionTriggered();
    void onSliderValueChanged(int value);

private:
    void createActions();
    void setActionsEnabled(bool value);

    QToolBar *toolBar;
    ImageContainer *imageContainer;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *adjustSizeAction;
    QSlider *slider;
    QGridLayout *layout;
    QScrollArea *scrollArea;
};


#endif //IMAGEEDITOR_IMAGEVIEWERVIEW_H
