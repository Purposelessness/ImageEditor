#include "shapecategorymodel.h"
#include "../../Tool/Shape/Ellipse/ellipse.h"

void ShapeCategoryModel::createTools() {
    auto ellipse = new Ellipse();
    addTool(ellipse);
    setTool(ellipse->toString());
}
