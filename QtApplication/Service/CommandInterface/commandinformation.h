#ifndef IMAGEEDITOR_COMMANDINFORMATION_H
#define IMAGEEDITOR_COMMANDINFORMATION_H


#include <QRect>
#include <QColor>
#include <QGraphicsLineItem>
#include <QAbstractGraphicsShapeItem>
#include <QPoint>
#include <QPen>
#include <QBrush>
#include <QGraphicsPixmapItem>

enum class CommandType {
    none,
    ellipse,
    triangle,
    line,
    ellipseColorInverter,
    triangleRotator,
    crop
};

struct CommandLineData {
public:
    CommandLineData() = default;
    explicit CommandLineData(QGraphicsLineItem *line);
    explicit CommandLineData(const QPoint &p1, const QPoint &p2, const QColor &color, int thickness);
    void setLine(const QPoint&p1, const QPoint &p2);

    void update();
    int x1{}, y1{}, x2{}, y2{};
    QColor color{};
    int thickness{};
    QGraphicsLineItem *line = nullptr;
};

struct CommandFigureData {
public:
    CommandFigureData() = default;
    explicit CommandFigureData(QAbstractGraphicsShapeItem *item, const QRect &startRect);
    explicit CommandFigureData(const QRect &rect, const QColor &fillColor, const QColor &borderColor, int thickness);
    void setFillColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setThickness(int nThickness);

    void update();
    QRect rect{};
    QColor fillColor{}, borderColor{};
    int thickness{};
    QAbstractGraphicsShapeItem *item = nullptr;
};

struct CommandColorInverterData {
public:
    CommandColorInverterData() = default;
    explicit CommandColorInverterData(const QRect &srcRect, const QPoint &offset, QGraphicsPixmapItem *item);
    explicit CommandColorInverterData(const QRect &srcRect, const QPoint &offset, const QRect &destRect);

    void update();
    QRect srcRect{}, destRect{};
    QPoint offset{};
    QGraphicsPixmapItem *item = nullptr;
};

struct CommandCropData {
public:
    CommandCropData() = default;
    explicit CommandCropData(const QRect &rect);

    QRect rect{};
};

struct CommandRotatorData {
public:
    CommandRotatorData() = default;
    explicit CommandRotatorData(const QRect &srcRect, const QPoint &offset, QGraphicsPixmapItem *item, int angle);
    explicit CommandRotatorData(const QRect &srcRect, const QPoint &offset, const QRect &destRect, int angle);

    void update();
    QRect srcRect{}, destRect{};
    QPoint offset{};
    QGraphicsPixmapItem *item = nullptr;
    int angle{};
};

struct CommandInformation {
    union {
        CommandFigureData figureData{};
        CommandLineData lineData;
        CommandColorInverterData colorInverterData;
        CommandCropData cropData;
        CommandRotatorData rotatorData;
    };
    CommandType type = CommandType::none;
};


#endif //IMAGEEDITOR_COMMANDINFORMATION_H
