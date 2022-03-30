#ifndef IMAGEEDITOR_SHAPECATEGORYMODEL_H
#define IMAGEEDITOR_SHAPECATEGORYMODEL_H

#include "../toolcategorymodel.h"

class ShapeCategoryModel : public ToolCategoryModel {
public:
    ShapeCategoryModel() = default;
    void createTools() override;
};


#endif //IMAGEEDITOR_SHAPECATEGORYMODEL_H
