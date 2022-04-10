#include "figurecategory.h"

FigureCategory::FigureCategory(const QString &name, FigureCategoryView *newView, FigureCategoryModel *newModel) :
        ToolCategory(name, newView, newModel),
        model (newModel), view(newView),
        lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
        shapeParametersInterface(new ShapeParametersInterface(tr("FigureCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(updated()), this, SLOT(onParametersUpdated()));
    connect(shapeParametersInterface, SIGNAL(updated()), this, SLOT(onParametersUpdated()));
    connect(model, SIGNAL(figureSelected()), this, SLOT(onFigureSelected()));
    connect(model, SIGNAL(figureDeselected()), this, SLOT(onFigureDeselected()));
    updateDataInChildren();
}

void FigureCategory::updateCurrentData(Data *newData) {
    currentData = *newData;
    updateDataInChildren();
}

void FigureCategory::updateDataInChildren() {
    model->setData(&currentData);
    shapeParametersInterface->setData(&currentData);
    lineParametersInterface->setData(&currentData);
}

void FigureCategory::onParametersUpdated() {
    model->updateFigureParameters();
}

void FigureCategory::showParametersInterface(FigureType figureType) {
    switch (figureType) {
        case line:
            lineParametersInterface->update();
            view->setWidget(lineParametersInterface->getWidget());
            break;
        case shape:
            shapeParametersInterface->update();
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

void FigureCategory::onFigureSelected() {
    showParametersInterface(model->getFigure()->getType());
}

void FigureCategory::onFigureDeselected() {
    showParametersInterface(none);
}
