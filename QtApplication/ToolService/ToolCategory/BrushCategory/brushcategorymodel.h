#ifndef IMAGEEDITOR_BRUSHCATEGORYMODEL_H
#define IMAGEEDITOR_BRUSHCATEGORYMODEL_H

#include "../toolcategorymodel.h"

class BrushCategoryModel : public ToolCategoryModel {
public:
    BrushCategoryModel() = default;
    void createTools() override;
};


#endif //IMAGEEDITOR_BRUSHCATEGORYMODEL_H
