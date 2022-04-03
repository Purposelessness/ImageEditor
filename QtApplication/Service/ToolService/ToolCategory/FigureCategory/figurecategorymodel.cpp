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
