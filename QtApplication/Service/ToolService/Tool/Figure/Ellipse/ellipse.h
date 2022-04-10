#ifndef IMAGEEDITOR_ELLIPSE_H
#define IMAGEEDITOR_ELLIPSE_H

#include "../shape.h"
#include "ellipsemodel.h"
#include "../../../Generics/toolunitview.h"

class Ellipse : public Shape {
public:
    explicit Ellipse(QString name = QWidget::tr("Ellipse"), ToolUnitView *view = new ToolUnitView(QWidget::tr("Ellipse")), ShapeModel *model = new EllipseModel());
};


#endif //IMAGEEDITOR_ELLIPSE_H
