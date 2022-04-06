#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H

#include <QGraphicsItem>

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class Shape;

class FigureCategoryModel : public ToolCategoryModel {
Q_OBJECT

public:
    FigureCategoryModel() = default;

    void createTools() override;
    void updateFigureParameters(Figure *figure, FigureData *figureData);

signals:
    void figureSelected(Figure *figure);
    void figureDeselected();

protected:
    void addTool(Tool *tool) override;

private slots:
    void onFigureSelected(Figure *figure);
    void onFigureDeselected();

private:
    FigureData lineData {};
    FigureData shapeData {};
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
