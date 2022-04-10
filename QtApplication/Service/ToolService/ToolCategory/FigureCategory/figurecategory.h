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
                            FigureCategoryView *newView = new FigureCategoryView(tr("Figure Category")),
                            FigureCategoryModel *newModel = new FigureCategoryModel());

protected slots:
    void onActionTriggered() override;

private slots:
    void onFigureSelected(Figure *figure);
    void onFigureDeselected();
    void onLineParametersChanged(FigureData *figureData);
    void onShapeParametersChanged(FigureData *figureData);

private:
    void showParametersInterface(FigureType figureType);

    ShapeParametersInterface *shapeParametersInterface;
    LineParametersInterface *lineParametersInterface;
    FigureCategoryModel *model;
    FigureCategoryView *view;

    Figure *selectedFigure = nullptr;
};


#endif //IMAGEEDITOR_FIGURECATEGORY_H
