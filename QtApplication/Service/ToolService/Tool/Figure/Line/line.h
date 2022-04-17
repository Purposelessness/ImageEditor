#ifndef IMAGEEDITOR_LINE_H
#define IMAGEEDITOR_LINE_H


#include "../figure.h"
#include "../../tool.h"
#include "linemodel.h"

class ToolUnitView;

class Line : public Figure {
Q_OBJECT

public:
    explicit Line(const QString &name = tr("Line"), LineModel *model = new LineModel());

    void setData(const FigureData &figureData) override;
    FigureType getType() override;

private:
    LineModel *model;
};


#endif //IMAGEEDITOR_LINE_H
