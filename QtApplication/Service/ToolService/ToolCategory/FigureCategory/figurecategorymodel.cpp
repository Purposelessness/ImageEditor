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
    tool = dynamic_cast<IFigure *>(tool);
    connect(tool, SIGNAL(showParametersInterface(FigureType)), this, SLOT(onFigureDrawn(FigureType)));
    ToolCategoryModel::addTool(tool);
}

void FigureCategoryModel::onFigureDrawn(FigureType figureType) {
    emit showInterface(figureType);
}

void FigureCategoryModel::setTool(const QString &name) {
    ToolCategoryModel::setTool(name);
    updateFigureData();
}

void FigureCategoryModel::updateFigureParameters(FigureData *figureData, FigureType figureType) {
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
    updateFigureData();
}

void FigureCategoryModel::updateFigureData() {
    if (!getCurrentTool())
        return;
    auto tool = dynamic_cast<IFigure *>(getCurrentTool());
    switch (tool->getType()) {
        case line:
            tool->setData(&lineData);
            break;
        case shape:
            tool->setData(&shapeData);
            break;
        case none:
            break;
    }
}
