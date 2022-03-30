#ifndef IMAGEEDITOR_SHAPECATEGORY_H
#define IMAGEEDITOR_SHAPECATEGORY_H

#include "../toolcategory.h"
#include "shapecategoryview.h"
#include "shapecategorymodel.h"
#include "shapeparametersinterface.h"

class ShapeCategory : public ToolCategory {
Q_OBJECT

public:
    explicit ShapeCategory(const QString &name = tr("ShapeCategory"),
                           ToolCategoryView *view = new ShapeCategoryView(tr("ShapeCategory")),
                           ToolCategoryModel *model = new ShapeCategoryModel());

    QWidget *getAlternativeWidget() override;

private slots:
    void onFillColorChanged(const QColor &color);
    void onLineColorChanged(const QColor &color);
    void onThicknessChanged(const int &value);

private:
    ShapeParametersInterface *parametersInterface;
    ShapeCategoryModel *shapeModel;
};


#endif //IMAGEEDITOR_SHAPECATEGORY_H
