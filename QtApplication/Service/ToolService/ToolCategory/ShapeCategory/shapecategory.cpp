#include "shapecategory.h"

ShapeCategory::ShapeCategory(const QString& name) : ToolCategory(name, new ShapeCategoryView(name),
                                                                 new ShapeCategoryModel()) {}
