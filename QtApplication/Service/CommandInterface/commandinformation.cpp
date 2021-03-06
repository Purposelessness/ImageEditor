#include "commandinformation.h"

#include <utility>
#include <cstring>

CommandLineData::CommandLineData(QGraphicsLineItem *line) : line(line) {}

CommandLineData::CommandLineData(const QPoint &p1, const QPoint &p2, const QColor &color, int thickness)
               : color(color), thickness(thickness) {
        setLine(p1, p2);
}

void CommandLineData::update() {
    if (line) {
        QPoint p1 = line->mapToParent(line->line().p1()).toPoint();
        QPoint p2 = line->mapToParent(line->line().p2()).toPoint();
        setLine(p1, p2);
        color = line->pen().color();
        thickness = line->pen().width();
    }
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

CommandFigureData::CommandFigureData(QAbstractGraphicsShapeItem *item, const QRect &rect)
                 : item(item), rect(rect.normalized()) {}

CommandFigureData::CommandFigureData(const QRect &rect, const QColor &fillColor, const QColor &borderColor, int thickness)
                 : rect(rect.normalized()), thickness(thickness) {
    setFillColor(fillColor);
    setBorderColor(borderColor);
    setThickness(thickness);
}

void CommandFigureData::update() {
    if (item) {
        auto newCenter = item->mapToParent(item->boundingRect()).boundingRect().toRect().normalized().center();
        rect.moveCenter(newCenter);
        setFillColor(item->brush().style() != Qt::NoBrush ? item->brush().color() : QColor{});
        setBorderColor(item->pen().color());
        setThickness(item->pen().width());
    }
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

CommandColorInverterData::CommandColorInverterData(const QRect &srcRect, const QPoint &offset, QGraphicsPixmapItem *item)
                        : srcRect(srcRect.normalized()), offset(offset), item(item) {}

CommandColorInverterData::CommandColorInverterData(const QRect &srcRect, const QPoint &offset, const QRect &destRect)
                        : srcRect(srcRect.normalized()), offset(offset), destRect(destRect.normalized()) {}

void CommandColorInverterData::update() {
    if (item) {
        auto rot = item->rotation();
        item->setRotation(0);
        destRect = item->mapToParent(item->boundingRect()).boundingRect().toRect().normalized();
        item->setRotation(rot);
    }
}

CommandCropData::CommandCropData(const QRect &rect) : rect(rect.normalized()) {}

CommandRotatorData::CommandRotatorData(const QRect &srcRect, const QPoint &offset, QGraphicsPixmapItem *item, int angle)
                  : srcRect(srcRect.normalized()), offset(offset), item(item), angle(angle) {}

CommandRotatorData::CommandRotatorData(const QRect &srcRect, const QPoint &offset, const QRect &destRect, int angle)
                  : srcRect(srcRect.normalized()), offset(offset), destRect(destRect.normalized()), angle(angle) {}

void CommandRotatorData::update() {
    if (item) {
        angle = static_cast<int>(item->rotation());
        item->setRotation(0);
        destRect = item->mapToParent(item->boundingRect()).boundingRect().toRect().normalized();
        item->setRotation(angle);
    }
}

CommandOutlinerData::CommandOutlinerData(int width, const QColor &color, const QColor &destColor)
                   : width(width), color(color), destColor(destColor) {}

CommandGlueData::CommandGlueData(const char *path) {
    imagePath = new char[strlen(path) + 1]{};
    strcpy(imagePath, path);
}

CommandReflectorData::CommandReflectorData(const QRect &rect) : rect(rect) {}
