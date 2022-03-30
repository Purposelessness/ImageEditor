#include "shapecategory.h"
#include "../../Tool/Shape/shapemodel.h"
#include "../../Tool/Shape/shape.h"


ShapeCategory::ShapeCategory(const QString &name, ToolCategoryView *view, ToolCategoryModel *model) : ToolCategory(name, view, model),
                                                    parametersInterface(new ShapeParametersInterface(tr("ShapeCategory"), this)) {
    connect(parametersInterface, SIGNAL(fillColorChanged(const QColor&)), this, SLOT(onFillColorChanged(const QColor&)));
    connect(parametersInterface, SIGNAL(lineColorChanged(const QColor&)), this, SLOT(onLineColorChanged(const QColor&)));
    connect(parametersInterface, SIGNAL(thicknessChanged(const int&)), this, SLOT(onThicknessChanged(const int&)));
    shapeModel = dynamic_cast<ShapeCategoryModel *>(model);
    parametersInterface->getWidget()->setParent(nullptr);
    parametersInterface->getWidget()->show();
    parametersInterface->resetParameters();
}

QWidget *ShapeCategory::getAlternativeWidget() {
    return parametersInterface->getWidget();
}

void ShapeCategory::onFillColorChanged(const QColor &color) {
    dynamic_cast<Shape *>(shapeModel->getCurrentTool())->setFillColor(color);
}

void ShapeCategory::onLineColorChanged(const QColor &color) {
    dynamic_cast<Shape *>(shapeModel->getCurrentTool())->setLineColor(color);
}

void ShapeCategory::onThicknessChanged(const int &value) {
    dynamic_cast<Shape *>(shapeModel->getCurrentTool())->setThickness(value);
}
