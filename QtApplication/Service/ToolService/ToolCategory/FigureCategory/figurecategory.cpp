#include "figurecategory.h"

FigureCategory::FigureCategory(const QString &name, FigureCategoryView *newView, FigureCategoryModel *newModel) :
        ToolCategory(name, newView, newModel),
        model (newModel), view(newView),
        lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
        shapeParametersInterface(new ShapeParametersInterface(tr("FigureCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onLineParametersChanged(FigureData*)));
    connect(shapeParametersInterface, SIGNAL(update(FigureData*)), this, SLOT(onShapeParametersChanged(FigureData*)));
    connect(model, SIGNAL(figureSelected(Figure*)), this, SLOT(onFigureSelected(Figure*)));
    connect(model, SIGNAL(figureDeselected()), this, SLOT(onFigureDeselected()));
}

void FigureCategory::onLineParametersChanged(FigureData *figureData) {
    model->updateFigureParameters(selectedFigure, figureData);
}

void FigureCategory::onShapeParametersChanged(FigureData *figureData) {
    model->updateFigureParameters(selectedFigure, figureData);
}

void FigureCategory::showParametersInterface(FigureType figureType) {
    switch (figureType) {
        case line:
            lineParametersInterface->updateView();
            view->setWidget(lineParametersInterface->getWidget());
            break;
        case shape:
            shapeParametersInterface->updateView();
            view->setWidget(shapeParametersInterface->getWidget());
            break;
        default:
            view->resetWidget();
            break;
    }
    emit updated();
}

void FigureCategory::onActionTriggered() {
    view->resetWidget();
    emit updated();
    ToolCategory::onActionTriggered();
}

void FigureCategory::onFigureSelected(Figure *figure) {
    selectedFigure = figure;
    showParametersInterface(selectedFigure->getType());
}

void FigureCategory::onFigureDeselected() {
    selectedFigure = nullptr;
    showParametersInterface(none);
}
