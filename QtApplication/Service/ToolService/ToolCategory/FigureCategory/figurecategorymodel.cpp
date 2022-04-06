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

void FigureCategoryModel::addTool(Tool *tool) {
    auto figure = dynamic_cast<Figure *>(tool);
    connect(figure, SIGNAL(selected(Figure*)), this, SLOT(onFigureSelected(Figure*)));
    connect(figure, SIGNAL(deselected()), this, SLOT(onFigureDeselected()));
    ToolCategoryModel::addTool(tool);
}

void FigureCategoryModel::updateFigureParameters(Figure *figure, FigureData *figureData) {
    if (!figure)
        return;
    switch (figure->getType()) {
        case line:
            lineData = *figureData;
            figure->setData(&lineData);
            break;
        case shape:
            shapeData = *figureData;
            figure->setData(&shapeData);
            break;
        case none:
            break;
    }
}

void FigureCategoryModel::onFigureSelected(Figure *figure) {
    emit figureSelected(figure);
}

void FigureCategoryModel::onFigureDeselected() {
    emit figureDeselected();
}
