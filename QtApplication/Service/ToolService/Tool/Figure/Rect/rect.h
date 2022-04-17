#ifndef IMAGEEDITOR_RECT_H
#define IMAGEEDITOR_RECT_H


#include "../shape.h"
#include "rectmodel.h"

class Rect : public Shape {
public:
    explicit Rect(const QString &name = QWidget::tr("Rect"), ShapeModel *model = new RectModel());
};


#endif //IMAGEEDITOR_RECT_H
