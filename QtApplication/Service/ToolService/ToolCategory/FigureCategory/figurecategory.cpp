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
    data = *newData;
    updateDataInChildren();
}

void FigureCategory::updateDataInChildren() {
    model->setData(&data);
    shapeParametersInterface->setData(&data);
    lineParametersInterface->setData(&data);
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
            qDebug() << "Showing shape parameters interface";
            shapeParametersInterface->update();
            view->setWidget(shapeParametersInterface->getWidget());
            break;
        default:
            qDebug() << "Reset parameters interface";
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
    Data *newData = model->getCurrentData();
    updateCurrentData(newData);
    qDebug() << (newData->type == shape);
    showParametersInterface(newData->type);
}

void FigureCategory::onFigureDeselected() {
    showParametersInterface(none);
}
