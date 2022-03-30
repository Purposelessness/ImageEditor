#include "shapecategory.h"
#include "../../Tool/Shape/shapemodel.h"

ShapeCategory::ShapeCategory(const QString &name) : ToolCategory(name, new ShapeCategoryView(name),new ShapeCategoryModel()),
                                                    parametersInterface(new ShapeParametersInterface(tr("ShapeCategory"), this)) {
    connect(parametersInterface, SIGNAL(fillColorChanged(const QColor&)), this, SLOT(onFillColorChanged(const QColor&)));
    connect(parametersInterface, SIGNAL(lineColorChanged(const QColor&)), this, SLOT(onLineColorChanged(const QColor&)));
    connect(parametersInterface, SIGNAL(thicknessChanged(const int&)), this, SLOT(onThicknessChanged(const int&)));
}

QWidget *ShapeCategory::getAlternativeWidget() {
    return parametersInterface->getWidget();
}

void ShapeCategory::onFillColorChanged(const QColor &color) {
    ShapeModel::setFillColor(color);
}

void ShapeCategory::onLineColorChanged(const QColor &color) {
    ShapeModel::setLineColor(color);
}

void ShapeCategory::onThicknessChanged(const int &value) {
    ShapeModel::setThickness(value);
}


