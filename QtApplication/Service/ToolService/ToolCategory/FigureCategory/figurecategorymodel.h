#ifndef IMAGEEDITOR_FIGURECATEGORYMODEL_H
#define IMAGEEDITOR_FIGURECATEGORYMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

#include <QGraphicsItem>

struct Data {
    QColor fillColor = QColor(0, 168, 243);
    QColor lineColor = Qt::black;
    int thickness = 10;
    bool fillEnabled = true;
    bool lineEnabled = true;
    FigureType type = none;
};

class FigureCategoryModel : public QObject, public ToolCategoryModel<Figure> {
Q_OBJECT

public:
    void setData(Data *data);
    Data *getCurrentData();

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

    Data *data = nullptr;
    Data currentData{};
    FigureData figureData{};

    Figure *selectedFigure = nullptr;
};


#endif //IMAGEEDITOR_FIGURECATEGORYMODEL_H
