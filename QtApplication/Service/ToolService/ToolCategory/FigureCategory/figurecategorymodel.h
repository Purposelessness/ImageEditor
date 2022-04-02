#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H

#include "../toolcategorymodel.h"

class Shape;

class FigureCategoryModel : public ToolCategoryModel {
public:
    FigureCategoryModel() = default;
    void createTools() override;
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
