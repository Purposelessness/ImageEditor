#ifndef IMAGEEDITOR_IMAGEVIEWER_H
#define IMAGEEDITOR_IMAGEVIEWER_H

#include <QWidget>

class ImageViewer : public QWidget {
public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

private:
    void setBackgroundColor(QColor color);
};


#endif //IMAGEEDITOR_IMAGEVIEWER_H
