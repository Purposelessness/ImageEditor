#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/ifigure.h"

class Shape;

class FigureCategoryModel : public ToolCategoryModel {
Q_OBJECT

public:
    FigureCategoryModel() = default;

    void createTools() override;
    void addTool(Tool *tool) override;

signals:
    void showInterface(FigureType figureType);

private slots:
    void onFigureDrawn(FigureType figureType);
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
