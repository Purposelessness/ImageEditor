#ifndef IMAGEEDITOR_IMAGEVIEWERVIEW_H
#define IMAGEEDITOR_IMAGEVIEWERVIEW_H

#include "imagecontainer.h"

#include <QWidget>
#include <QGridLayout>
#include <QScrollArea>
#include <QToolBar>
#include <QSlider>
#include <QLineEdit>

class ImageViewer;

class ImageViewerView : public QWidget {
Q_OBJECT

    friend ImageViewer;

public:
    explicit ImageViewerView(QWidget *parent = nullptr);

signals:
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
    void setSliderValue(int value);
    void resetScaleValue();

    QToolBar *toolBar;
    ImageContainer *imageContainer;
    QAction *zoomInAction;
    QAction *zoomOutAction;
    QAction *adjustSizeAction;
    QSlider *slider;
    QGridLayout *layout;
    QScrollArea *scrollArea;

    const int defaultScale = 100, minScale = 10, maxScale = 500;
    const int sliderMinValue = 0, sliderMaxValue = 200;
    const int zoomStep = sliderMaxValue / 10;
};


#endif //IMAGEEDITOR_IMAGEVIEWERVIEW_H
