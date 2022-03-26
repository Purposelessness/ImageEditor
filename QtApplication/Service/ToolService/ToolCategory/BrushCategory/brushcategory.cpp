#include "brushcategory.h"

BrushCategory::BrushCategory(const QString& name) : ToolCategory(name, new BrushCategoryView(name),
                                                                 new BrushCategoryModel()) {}
