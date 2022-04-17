#ifndef IMAGEEDITOR_TRIANGLE_H
#define IMAGEEDITOR_TRIANGLE_H


#include "../shape.h"
#include "trianglemodel.h"

class Triangle : public Shape {
public:
    explicit Triangle(const QString &name = QWidget::tr("Triangle"), TriangleModel *model = new TriangleModel());
};


#endif //IMAGEEDITOR_TRIANGLE_H
