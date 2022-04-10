#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H


#include <QGraphicsItem>

#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

struct Data;

class FigureCategoryModel : public QObject, public ToolCategoryModel<Figure> {
Q_OBJECT

public:
    void setData(Data *data);
    Figure *getFigure();

signals:
    void figureSelected();
    void figureDeselected();

public slots:
    void updateFigureParameters(Figure *figure = nullptr);
    void onFigureSelected(Figure *figure);
    void onFigureDeselected();

protected:
    void addTool(Figure *figure) override;

private:
    void createTools() override;

    Data *data = nullptr;
    FigureData figureData {};

    Figure *selectedFigure = nullptr;
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
