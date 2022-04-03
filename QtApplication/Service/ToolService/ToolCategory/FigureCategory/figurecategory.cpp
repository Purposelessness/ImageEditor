#include "figurecategory.h"

FigureCategory::FigureCategory(const QString &name, ToolCategoryView *newView, ToolCategoryModel *newModel) :
        ToolCategory(name, newView, newModel), lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
        shapeParametersInterface(new ShapeParametersInterface(tr("FigureCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    connect(shapeParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onParametersChanged(FigureData*)));
    model = static_cast<FigureCategoryModel *>(newModel);
    connect(model, SIGNAL(showInterface(FigureType)), this, SLOT(showParametersInterface(FigureType)));
    view = static_cast<FigureCategoryView *>(newView);
    shapeParametersInterface->resetParameters();
    lineParametersInterface->resetParameters();
}

QWidget *FigureCategory::getAlternativeWidget() {
    return shapeParametersInterface->getWidget();
}

void FigureCategory::onParametersChanged(FigureData *figureData) {
    qDebug() << "Parameters changed" << figureData->fillColor;
    dynamic_cast<IFigure *>(model->getCurrentTool())->setData(figureData);
}

void FigureCategory::showParametersInterface(FigureType figureType) {
    switch (figureType) {
        case line:
            view->setWidget(lineParametersInterface->getWidget());
            break;
        case shape:
            view->setWidget(shapeParametersInterface->getWidget());
            break;
        default:
            view->resetWidget();
            break;
    }
    emit updateView();
}

void FigureCategory::onActionTriggered() {
    showParametersInterface(none);
    ToolCategory::onActionTriggered();
}
