#ifndef IMAGEEDITOR_FIGURECATEGORY_H
#define IMAGEEDITOR_FIGURECATEGORY_H


#include "../toolcategory.h"
#include "figurecategoryview.h"
#include "figurecategorymodel.h"
#include "ParametersInterface/shapeparametersinterface.h"
#include "ParametersInterface/lineparametersinterface.h"

struct Data {
    QColor fillColor = QColor(0, 168, 243);
    QColor lineColor = Qt::black;
    int thickness = 10;
    bool fillEnabled = true;
    bool lineEnabled = true;
};

class FigureCategory : public ToolCategory {
Q_OBJECT

public:
    explicit FigureCategory(const QString &name = tr("FigureCategory"),
                            FigureCategoryView *newView = new FigureCategoryView(tr("Figure Category")),
                            FigureCategoryModel *newModel = new FigureCategoryModel());

protected slots:
    void onActionTriggered() override;

private slots:
    void onFigureSelected();
    void onFigureDeselected();
    void onParametersUpdated();

private:
    void updateCurrentData(Data *data);
    void updateDataInChildren();
    void showParametersInterface(FigureType figureType);

    ShapeParametersInterface *shapeParametersInterface;
    LineParametersInterface *lineParametersInterface;
    FigureCategoryModel *model;
    FigureCategoryView *view;

    Data currentData {};
    Data mainData {};
};


#endif //IMAGEEDITOR_FIGURECATEGORY_H
