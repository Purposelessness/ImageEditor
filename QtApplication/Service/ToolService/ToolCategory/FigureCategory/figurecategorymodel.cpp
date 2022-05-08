#include "figurecategorymodel.h"
#include "../../Tool/Figure/Ellipse/ellipse.h"
#include "../../Tool/Figure/Rect/rect.h"
#include "../../Tool/Figure/Line/line.h"
#include "../../Tool/Figure/Triangle/triangle.h"

FigureData *FigureCategoryModel::getData() {
    return &data;
}

void FigureCategoryModel::createTools() {
    auto ellipse = new Ellipse();
    addTool(ellipse);
    auto rect = new Rect();
    addTool(rect);
    auto triangle = new Triangle();
    addTool(triangle);
    auto line = new Line();
    addTool(line);
    setTool(ellipse->toString());
}

void FigureCategoryModel::addTool(Figure *figure) {
    QObject::connect(figure, SIGNAL(update(Figure*)), this, SLOT(updateFigureParameters(Figure*)));
    QObject::connect(figure, SIGNAL(selected(Figure*)), this, SLOT(onFigureSelected(Figure*)));
    QObject::connect(figure, SIGNAL(deselected()), this, SLOT(onFigureDeselected()));
    ToolCategoryModel::addTool(figure);
}

void FigureCategoryModel::updateFigureParameters(Figure *figure) {
    auto figureToUpdate = figure ? figure : selectedFigure;
    if (!figureToUpdate)
        return;

    figureToUpdate->setData(data);
}

void FigureCategoryModel::updateCurrentData(FigureData currentFigureData) {
    if (currentFigureData.type == FigureType::shape) {
        data.fillEnabled = currentFigureData.fillEnabled;
        if (currentFigureData.fillEnabled)
            data.fillColor = currentFigureData.fillColor;
    }
    data.lineEnabled = currentFigureData.lineEnabled && currentFigureData.type != FigureType::line;
    if (currentFigureData.lineEnabled || currentFigureData.type == FigureType::line)
        data.lineColor = currentFigureData.lineColor;
    data.thickness = currentFigureData.thickness;
    data.type = currentFigureData.type;
}

void FigureCategoryModel::onFigureSelected(Figure *figure) {
    selectedFigure = figure;
    updateCurrentData(selectedFigure->getData());
    emit figureSelected();
}

void FigureCategoryModel::onFigureDeselected() {
    if (selectedFigure && selectedFigure->isSelected())
        return;
    selectedFigure = nullptr;
    emit figureDeselected();
}
