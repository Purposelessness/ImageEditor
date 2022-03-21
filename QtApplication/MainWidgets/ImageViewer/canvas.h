#ifndef IMAGEEDITOR_CANVAS_H
#define IMAGEEDITOR_CANVAS_H

#include <QWidget>
#include <QLabel>

class Canvas : public QWidget {
public:
    explicit Canvas(QWidget *parent = Q_NULLPTR);

    void setImage(const QImage& newImage);

private:
    QImage image;
    QLabel *imageLabel;
};


#endif //IMAGEEDITOR_CANVAS_H
