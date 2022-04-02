#include "figurecategory.h"

FigureCategory::FigureCategory(const QString &name, ToolCategoryView *view, ToolCategoryModel *model) :
            ToolCategory(name, view, model), lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
            shapeParametersInterface(new ShapeParametersInterface(tr("FigureCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    connect(shapeParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    figureModel = dynamic_cast<FigureCategoryModel *>(model);
    shapeParametersInterface->getWidget()->setParent(nullptr);
    shapeParametersInterface->getWidget()->show();
    shapeParametersInterface->resetParameters();
}

QWidget *FigureCategory::getAlternativeWidget() {
    return shapeParametersInterface->getWidget();
}

void FigureCategory::onParametersChanged(FigureData *figureData) {
    dynamic_cast<IFigure *>(figureModel->getCurrentTool())->setData(figureData);
}
