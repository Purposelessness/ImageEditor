#ifndef IMAGEEDITOR_SHAPECATEGORY_H
#define IMAGEEDITOR_SHAPECATEGORY_H

#include "../toolcategory.h"
#include "shapecategoryview.h"
#include "shapecategorymodel.h"
#include "shapeparametersinterface.h"

class ShapeCategory : public ToolCategory {
public:
    explicit ShapeCategory(const QString& name = tr("ShapeCategory"));

    QWidget *getAlternativeWidget() override;

private:
    ShapeParametersInterface *parametersInterface;
};


#endif //IMAGEEDITOR_SHAPECATEGORY_H
