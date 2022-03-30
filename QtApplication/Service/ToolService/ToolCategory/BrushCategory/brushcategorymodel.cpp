#include "brushcategorymodel.h"
#include "../../Tool/Shape/Ellipse/ellipse.h"

void BrushCategoryModel::createTools() {
    auto ellipse = new Ellipse();
    addTool(ellipse);
    setTool(ellipse->toString());
}
