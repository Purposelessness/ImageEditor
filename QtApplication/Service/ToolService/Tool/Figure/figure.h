#ifndef IMAGEEDITOR_FIGURE_H
#define IMAGEEDITOR_FIGURE_H


#include "../tool.h"

#include <QColor>

enum FigureType {
    line,
    shape,
    none
};

struct FigureData {
    QColor fillColor {QColor(Qt::green)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
    FigureType type {none};
};

class QGraphicsItem;

class Figure : public Tool {
Q_OBJECT

public:
    explicit Figure(QString name, ToolUnitView *view, IToolModel *model);

    virtual void setData(FigureData *figureData) {
        qDebug() << "setting data";
    }
    virtual FigureType getType() = 0;
    FigureData *getData();

protected:
    void onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) override;

signals:
    void update(Figure *figure);
    void selected(Figure *figure);
    void deselected();
};

#endif //IMAGEEDITOR_FIGURE_H
