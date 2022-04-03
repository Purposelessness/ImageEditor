#ifndef IMAGEEDITOR_FIGURECATEGORY_H
#define IMAGEEDITOR_FIGURECATEGORY_H

#include "../toolcategory.h"
#include "figurecategoryview.h"
#include "figurecategorymodel.h"
#include "ParametersInterface/shapeparametersinterface.h"
#include "ParametersInterface/lineparametersinterface.h"

class FigureCategory : public ToolCategory {
Q_OBJECT

public:
    explicit FigureCategory(const QString &name = tr("FigureCategory"),
                            ToolCategoryView *newView = new FigureCategoryView(tr("FigureCategory")),
                            ToolCategoryModel *newModel = new FigureCategoryModel());

    QWidget *getAlternativeWidget() override;

protected slots:
    void onActionTriggered() override;

private slots:
    void onParametersChanged(FigureData *figureData);
    void showParametersInterface(FigureType figureType);

private:
    ShapeParametersInterface *shapeParametersInterface;
    LineParametersInterface *lineParametersInterface;
    FigureCategoryModel *model;
    FigureCategoryView *view;
};


#endif //IMAGEEDITOR_FIGURECATEGORY_H
