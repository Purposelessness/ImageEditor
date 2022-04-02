#ifndef IMAGEEDITOR_LINE_H
#define IMAGEEDITOR_LINE_H

#include "../ifigure.h"
#include "../../tool.h"
#include "linemodel.h"

class ToolUnitView;

class Line : public IFigure, public Tool {
public:
    explicit Line(QString name = tr("Line"), ToolUnitView *view = new ToolUnitView(tr("Line")), LineModel *model = new LineModel());

    void setData(FigureData *figureData) override;

private:
    LineModel *model;
};


#endif //IMAGEEDITOR_LINE_H
