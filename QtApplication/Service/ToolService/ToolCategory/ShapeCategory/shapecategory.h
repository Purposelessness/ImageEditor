#ifndef IMAGEEDITOR_SHAPECATEGORY_H
#define IMAGEEDITOR_SHAPECATEGORY_H

#include "../toolcategory.h"
#include "shapecategoryview.h"
#include "shapecategorymodel.h"

class ShapeCategory : public ToolCategory {
public:
    explicit ShapeCategory(const QString& name = "ShapeCategory");
};


#endif //IMAGEEDITOR_SHAPECATEGORY_H
