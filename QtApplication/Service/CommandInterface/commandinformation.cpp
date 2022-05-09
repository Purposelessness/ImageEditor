#include "commandinformation.h"

CommandLineData::CommandLineData(QGraphicsLineItem *line) : line(line) {}

CommandLineData::CommandLineData(const QPoint &p1, const QPoint &p2, const QColor &color, int thickness)
               : color(color), thickness(thickness) {
        setLine(p1, p2);
}

CommandLineData CommandLineData::get() {
    if (line) {
        QPoint p1 = line->mapToParent(line->line().p1()).toPoint();
        QPoint p2 = line->mapToParent(line->line().p2()).toPoint();
        setLine(p1, p2);
        color = line->pen().color();
        thickness = line->pen().width();
    }
    return CommandLineData{QPoint{x1, y1}, QPoint{x2, y2}, color, thickness};
}

void CommandLineData::setLine(const QPoint &p1, const QPoint &p2) {
    if (p1.x() > p2.x()) {
        x1 = p2.x();
        y1 = p2.y();
        x2 = p1.x();
        y2 = p1.y();
    } else {
        x1 = p1.x();
        y1 = p1.y();
        x2 = p2.x();
        y2 = p2.y();
    }
}

CommandFigureData::CommandFigureData(QAbstractGraphicsShapeItem *item) : item(item) {}

CommandFigureData::CommandFigureData(const QRect &rect, const QColor &fillColor, const QColor &borderColor, int thickness)
                 : rect(rect.normalized()), thickness(thickness) {
    setFillColor(fillColor);
    setBorderColor(borderColor);
    setThickness(thickness);
}

CommandFigureData CommandFigureData::get() {
    if (item) {
        rect = item->mapToParent(item->boundingRect()).boundingRect().toRect().normalized();
        setFillColor(item->brush().color());
        setBorderColor(item->brush().color());
        setThickness(item->pen().width());
    }
    return CommandFigureData{rect, fillColor, borderColor, thickness};
}

void CommandFigureData::setFillColor(const QColor &color) {
    fillColor = color.isValid() && color.alpha() > 0 ? color : QColor{};
}

void CommandFigureData::setBorderColor(const QColor &color) {
    borderColor = color.isValid() && color.alpha() > 0 ? color : QColor{};
}

void CommandFigureData::setThickness(int nThickness) {
    thickness = borderColor.isValid() ? nThickness : 0;
}

CommandColorInverterData::CommandColorInverterData(QAbstractGraphicsShapeItem *item) : item(item) {}

CommandColorInverterData::CommandColorInverterData(const QRect &srcRect, const QRect &destRect)
                        : srcRect(srcRect.normalized()), destRect(destRect.normalized()) {}

CommandColorInverterData CommandColorInverterData::get() {
    if (item) {
        destRect = item->mapToParent(item->boundingRect()).boundingRect().toRect().normalized();
    }
    return CommandColorInverterData{srcRect, destRect};
}

CommandCropData::CommandCropData(const QRect &rect) : rect(rect.normalized()) {}

CommandCropData CommandCropData::get() {
    return CommandCropData{rect};
}
