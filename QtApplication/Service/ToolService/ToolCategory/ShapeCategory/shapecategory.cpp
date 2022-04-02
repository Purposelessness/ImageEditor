#include "shapecategory.h"
#include "../../Tool/Shape/shapemodel.h"
#include "../../Tool/Shape/shape.h"

ShapeCategory::ShapeCategory(const QString &name, ToolCategoryView *view, ToolCategoryModel *model) :
            ToolCategory(name, view, model), lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
            shapeParametersInterface(new ShapeParametersInterface(tr("ShapeCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    connect(shapeParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    shapeModel = dynamic_cast<ShapeCategoryModel *>(model);
    shapeParametersInterface->getWidget()->setParent(nullptr);
    shapeParametersInterface->getWidget()->show();
    shapeParametersInterface->resetParameters();
}

QWidget *ShapeCategory::getAlternativeWidget() {
    return shapeParametersInterface->getWidget();
}

void ShapeCategory::onParametersChanged(FigureData *figureData) {

}
