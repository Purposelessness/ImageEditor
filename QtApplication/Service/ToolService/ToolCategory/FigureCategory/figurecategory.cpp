#include "figurecategory.h"

FigureCategory::FigureCategory(const QString &name, FigureCategoryView *newView, FigureCategoryModel *newModel) :
        ToolCategory(name, newView, newModel),
        model (newModel), view(newView),
        lineParametersInterface(new LineParametersInterface(tr("LineCategory"), this)),
        shapeParametersInterface(new ShapeParametersInterface(tr("FigureCategory"), this)) {
    connect(lineParametersInterface, SIGNAL(updated()), model, SLOT(updateFigureParameters()));
    connect(shapeParametersInterface, SIGNAL(updated()), model, SLOT(updateFigureParameters()));
    connect(model, SIGNAL(figureSelected()), this, SLOT(onFigureSelected()));
    connect(model, SIGNAL(figureDeselected()), this, SLOT(onFigureDeselected()));
    updateDataInChildren(model->getData());
}

void FigureCategory::updateDataInChildren(FigureData *data) {
    if (data) {
        shapeParametersInterface->setData(data);
        lineParametersInterface->setData(data);
    } else {
        shapeParametersInterface->update();
        lineParametersInterface->update();
    }
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
    updateDataInChildren(model->getData());
    showParametersInterface(model->getData()->type);
}

void FigureCategory::onFigureDeselected() {
    showParametersInterface(none);
}
