#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include <QWidget>
#include <QLabel>
#include <QResizeEvent>

class ImageContainer : public QLabel {
Q_OBJECT

public:
    explicit ImageContainer(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);
    void scale(float scaleValue);

private:
    QPixmap originalPixmap;
    QPixmap pixmap;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
