#ifndef IMAGEEDITOR_SHAPECATEGORY_H
#define IMAGEEDITOR_SHAPECATEGORY_H

#include "../toolcategory.h"
#include "shapecategoryview.h"
#include "shapecategorymodel.h"
#include "ParametersInterface/shapeparametersinterface.h"
#include "ParametersInterface/lineparametersinterface.h"

class ShapeCategory : public ToolCategory {
Q_OBJECT

public:
    explicit ShapeCategory(const QString &name = tr("ShapeCategory"),
                           ToolCategoryView *view = new ShapeCategoryView(tr("ShapeCategory")),
                           ToolCategoryModel *model = new ShapeCategoryModel());

    QWidget *getAlternativeWidget() override;

private slots:
    void onParametersChanged(FigureData *figureData);

private:
    ShapeParametersInterface *shapeParametersInterface;
    LineParametersInterface *lineParametersInterface;
    ShapeCategoryModel *shapeModel;
};


#endif //IMAGEEDITOR_SHAPECATEGORY_H
