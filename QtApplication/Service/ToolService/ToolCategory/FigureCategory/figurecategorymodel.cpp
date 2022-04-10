#include "figurecategorymodel.h"
#include "../../Tool/Figure/Ellipse/ellipse.h"
#include "../../Tool/Figure/Rect/rect.h"
#include "../../Tool/Figure/Line/line.h"

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
    QObject::connect(figure, SIGNAL(selected(Figure*)), this, SLOT(onFigureSelected(Figure*)));
    QObject::connect(figure, SIGNAL(deselected()), this, SLOT(onFigureDeselected()));
    ToolCategoryModel::addTool(figure);
}

void FigureCategoryModel::updateFigureParameters(Figure *figure, FigureData *figureData) {
    if (!figure)
        return;
    figure->setData(figureData);
}

void FigureCategoryModel::onFigureSelected(Figure *figure) {
    emit figureSelected(figure);
}

void FigureCategoryModel::onFigureDeselected() {
    emit figureDeselected();
}
