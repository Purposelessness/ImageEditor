#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H

#include <QGraphicsItem>

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class FigureCategoryModelObject : public QObject {
Q_OBJECT

signals:
    void figureSelected(Figure *figure);
    void figureDeselected();

public slots:
    void onFigureSelected(Figure *figure);
    void onFigureDeselected();
};

class FigureCategoryModel : public ToolCategoryModel<Figure> {
public:
    void createTools() override;
    void updateFigureParameters(FigureType figureType, FigureData *figureData);
    void updateFigureParameters(Figure *figure, FigureData *figureData);

    FigureCategoryModelObject *object = new FigureCategoryModelObject();

protected:
    void addTool(Figure *figure) override;

private:
    FigureData lineData {};
    FigureData shapeData {};
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
