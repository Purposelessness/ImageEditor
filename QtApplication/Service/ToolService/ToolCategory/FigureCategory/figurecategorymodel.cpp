#include "figurecategorymodel.h"
#include "figurecategory.h"
#include "../../Tool/Figure/Ellipse/ellipse.h"
#include "../../Tool/Figure/Rect/rect.h"
#include "../../Tool/Figure/Line/line.h"

void FigureCategoryModel::setData(Data *newData) {
    data = newData;
}

Figure *FigureCategoryModel::getFigure() {
    return selectedFigure;
}

void FigureCategoryModel::createTools() {
    auto ellipse = new Ellipse();
    addTool(ellipse);
    auto rect = new Rect();
    addTool(rect);
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

    FigureType type = figureToUpdate->getType();
    figureData.fillColor = data->fillEnabled || type == line ? data->fillColor : QColor();
    figureData.lineColor = data->lineEnabled || type == line ? data->lineColor : QColor();
    figureData.thickness = data->thickness;
    figureData.type = type;
    figureToUpdate->setData(&figureData);
}

void FigureCategoryModel::onFigureSelected(Figure *figure) {
    selectedFigure = figure;
    emit figureSelected();
}

void FigureCategoryModel::onFigureDeselected() {
    selectedFigure = nullptr;
    emit figureDeselected();
}
