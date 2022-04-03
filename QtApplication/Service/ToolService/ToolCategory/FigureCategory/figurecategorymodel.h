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
    void setTool(const QString &name) override;
    void updateFigureParameters(FigureData *figureData, FigureType figureType);

signals:
    void showInterface(FigureType figureType);

private slots:
    void onFigureDrawn(FigureType figureType);

private:
    void updateFigureData();

    FigureData lineData {};
    FigureData shapeData {};
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
