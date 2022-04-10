#ifndef IMAGEEDITOR_BRUSHCATEGORY_H
#define IMAGEEDITOR_BRUSHCATEGORY_H


#include "../toolcategory.h"
#include "brushcategoryview.h"
#include "brushcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class BrushCategory : public ToolCategory {
public:
    explicit BrushCategory(const QString& name = "BrushCategory", BrushCategoryView *view = new BrushCategoryView(tr("Brush Category")),
                           BrushCategoryModel *model = new BrushCategoryModel());
};


#endif //IMAGEEDITOR_BRUSHCATEGORY_H
