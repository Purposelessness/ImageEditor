#ifndef IMAGEEDITOR_FIGURE_H
#define IMAGEEDITOR_FIGURE_H


#include "../tool.h"
#include "figuremodel.h"

#include <QColor>

enum FigureType {
    line,
    shape,
    none
};

struct FigureData {
    QColor fillColor {QColor(0, 168, 243)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
    bool fillEnabled {true};
    bool lineEnabled {true};
    FigureType type {none};
};

class QGraphicsItem;

class Figure : public Tool {
Q_OBJECT

public:
    explicit Figure(QString name, ToolUnitView *view, FigureModel *model);

    virtual void setData(const FigureData &figureData) = 0;
    virtual FigureType getType() = 0;
    [[nodiscard]] FigureData getData() const;
    [[nodiscard]] bool isSelected() const;

    void onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) override;
    void onMouseMoved(const QPoint &mousePos) override;
    void onMouseReleased(const QPoint &mousePos) override;

signals:
    void update(Figure *figure);
    void selected(Figure *figure);
    void deselected();

protected slots:
    void onItemSelected();
    void onItemDeselected();

private:
    FigureModel *model;

    bool isSelectedFlag = false, prevItemWasSelected = false;
};

#endif //IMAGEEDITOR_FIGURE_H
