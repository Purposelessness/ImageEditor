#ifndef IMAGEEDITOR_BRUSHCATEGORY_H
#define IMAGEEDITOR_BRUSHCATEGORY_H

#include "../toolcategory.h"
#include "brushcategoryview.h"
#include "brushcategorymodel.h"

class BrushCategory : public ToolCategory {
public:
    explicit BrushCategory(const QString& name = "BrushCategory");
};


#endif //IMAGEEDITOR_BRUSHCATEGORY_H
