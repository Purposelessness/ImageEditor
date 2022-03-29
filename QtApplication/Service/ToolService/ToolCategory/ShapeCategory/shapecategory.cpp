#include "shapecategory.h"

ShapeCategory::ShapeCategory(const QString &name) : ToolCategory(name, new ShapeCategoryView(name),new ShapeCategoryModel()),
                                                    parametersInterface(new ShapeParametersInterface(tr("ShapeCategory"), this)) {
}

QWidget *ShapeCategory::getAlternativeWidget() {
    return parametersInterface->getWidget();
}
