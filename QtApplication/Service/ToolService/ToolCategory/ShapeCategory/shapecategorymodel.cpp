#include "shapecategorymodel.h"

void ShapeCategoryModel::createTools() {
    auto brush = new Brush();
    addTool(brush);
    addTool(new Pen());
    setTool(brush->toString());
}
