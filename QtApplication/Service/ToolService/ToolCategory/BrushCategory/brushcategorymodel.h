#ifndef IMAGEEDITOR_BRUSHCATEGORYMODEL_H
#define IMAGEEDITOR_BRUSHCATEGORYMODEL_H

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class BrushCategoryModel : public ToolCategoryModel<Figure> {
public:
    BrushCategoryModel() = default;
    void createTools() override;
};


#endif //IMAGEEDITOR_BRUSHCATEGORYMODEL_H
