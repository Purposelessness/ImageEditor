#ifndef IMAGEEDITOR_FIGURECATEGORY_H
#define IMAGEEDITOR_FIGURECATEGORY_H

#include "../toolcategory.h"
#include "shapecategoryview.h"
#include "figurecategorymodel.h"
#include "ParametersInterface/shapeparametersinterface.h"
#include "ParametersInterface/lineparametersinterface.h"

class FigureCategory : public ToolCategory {
Q_OBJECT

public:
    explicit FigureCategory(const QString &name = tr("FigureCategory"),
                            ToolCategoryView *view = new ShapeCategoryView(tr("FigureCategory")),
                            ToolCategoryModel *model = new FigureCategoryModel());

    QWidget *getAlternativeWidget() override;

private slots:
    void onParametersChanged(FigureData *figureData);

private:
    ShapeParametersInterface *shapeParametersInterface;
    LineParametersInterface *lineParametersInterface;
    FigureCategoryModel *figureModel;
};


#endif //IMAGEEDITOR_FIGURECATEGORY_H
