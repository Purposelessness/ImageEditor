#ifndef IMAGEEDITOR_TRIANGLE_H
#define IMAGEEDITOR_TRIANGLE_H


#include "../shape.h"
#include "trianglemodel.h"

class Triangle : public Shape {
public:
    explicit Triangle(QString name = QWidget::tr("Triangle"),
                      ToolUnitView *view = new ToolUnitView(QWidget::tr("Triangle")),
                      TriangleModel *model = new TriangleModel());
};


#endif //IMAGEEDITOR_TRIANGLE_H
