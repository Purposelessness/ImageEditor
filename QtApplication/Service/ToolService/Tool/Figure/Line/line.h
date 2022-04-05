#ifndef IMAGEEDITOR_LINE_H
#define IMAGEEDITOR_LINE_H

#include "../ifigure.h"
#include "../../tool.h"
#include "linemodel.h"

class ToolUnitView;

class Line : public IFigure {
Q_OBJECT

public:
    explicit Line(QString name = tr("Line"), ToolUnitView *view = new ToolUnitView(tr("Line")), LineModel *model = new LineModel());

    void setData(FigureData *figureData) override;
    FigureType getType() override;

protected slots:
    void onLineDrawn();

private:
    LineModel *model;
};


#endif //IMAGEEDITOR_LINE_H
