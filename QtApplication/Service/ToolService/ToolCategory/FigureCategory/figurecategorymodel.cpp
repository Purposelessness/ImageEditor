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
    QObject::connect(figure, SIGNAL(selected(Figure*)), object, SLOT(onFigureSelected(Figure*)));
    QObject::connect(figure, SIGNAL(deselected()), object, SLOT(onFigureDeselected()));
    ToolCategoryModel::addTool(figure);
}

void FigureCategoryModel::updateFigureParameters(FigureType figureType, FigureData *figureData) {
    switch (figureType) {
        case line:
            lineData = *figureData;
            break;
        case shape:
            shapeData = *figureData;
            break;
        case none:
            break;
    }
}

void FigureCategoryModel::updateFigureParameters(Figure *figure, FigureData *figureData) {
    if (!figure)
        return;
    updateFigureParameters(figure->getType(), figureData);
    switch (figure->getType()) {
        case line:
            figure->setData(&lineData);
            break;
        case shape:
            figure->setData(&shapeData);
            break;
        case none:
            break;
    }
}

void FigureCategoryModelObject::onFigureSelected(Figure *figure) {
    emit figureSelected(figure);
}

void FigureCategoryModelObject::onFigureDeselected() {
    emit figureDeselected();
}
