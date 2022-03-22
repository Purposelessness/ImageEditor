#ifndef IMAGEEDITOR_ICANVAS_H
#define IMAGEEDITOR_ICANVAS_H

#include <QImage>

class ICanvas {
public:
    virtual void scale(float scaleFactor) = 0;
};

#endif //IMAGEEDITOR_ICANVAS_H
