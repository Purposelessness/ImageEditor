#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H

#include <QGraphicsItem>

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class FigureCategoryModel : public QObject, public ToolCategoryModel<Figure> {
Q_OBJECT

signals:
    void figureSelected(Figure *figure);
    void figureDeselected();

public slots:
    void onFigureSelected(Figure *figure);
    void onFigureDeselected();

public:
    void createTools() override;
    void updateFigureParameters(Figure *figure, FigureData *figureData);

protected:
    void addTool(Figure *figure) override;
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
