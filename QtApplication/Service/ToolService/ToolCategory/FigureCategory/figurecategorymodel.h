#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

#include <QGraphicsItem>

class FigureCategoryModel : public QObject, public ToolCategoryModel<Figure> {
Q_OBJECT

public:
    FigureData *getData();

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
    void updateCurrentData(FigureData currentFigureData);

    FigureData data{};

    Figure *selectedFigure = nullptr;
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
