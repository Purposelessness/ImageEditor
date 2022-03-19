#include "brushcategorymodel.h"
#include "../../Tool/Brush-like/Brush/brush.h"
#include "../../Tool/Brush-like/Pen/pen.h"

void BrushCategoryModel::createTools() {
    auto brush = new Brush();
    addTool(brush);
    addTool(new Pen());
    setTool(brush->toString());
}
