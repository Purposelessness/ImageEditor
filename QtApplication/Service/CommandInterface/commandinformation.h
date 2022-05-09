#ifndef IMAGEEDITOR_COMMANDINFORMATION_H
#define IMAGEEDITOR_COMMANDINFORMATION_H


#include <QRect>
#include <QColor>
#include <QGraphicsLineItem>
#include <QAbstractGraphicsShapeItem>
#include <QPoint>
#include <QPen>
#include <QBrush>

enum class CommandType {
    none,
    ellipse,
    triangle,
    line,
    ellipseColorInverter,
    crop
};

struct CommandLineData {
public:
    CommandLineData() = default;
    explicit CommandLineData(QGraphicsLineItem *line);
    explicit CommandLineData(const QPoint &p1, const QPoint &p2, const QColor &color, int thickness);
    CommandLineData get();
    void setLine(const QPoint&p1, const QPoint &p2);
private:
    int x1{}, y1{}, x2{}, y2{};
    QColor color{};
    int thickness{};
    QGraphicsLineItem *line = nullptr;
};

struct CommandFigureData {
public:
    CommandFigureData() = default;
    explicit CommandFigureData(QAbstractGraphicsShapeItem *item);
    explicit CommandFigureData(const QRect &rect, const QColor &fillColor, const QColor &borderColor, int thickness);
    CommandFigureData get();
    void setFillColor(const QColor &color);
    void setBorderColor(const QColor &color);
    void setThickness(int nThickness);
private:
    QRect rect{};
    QColor fillColor{}, borderColor{};
    int thickness{};
    QAbstractGraphicsShapeItem *item = nullptr;
};

struct CommandColorInverterData {
public:
    CommandColorInverterData() = default;
    explicit CommandColorInverterData(QAbstractGraphicsShapeItem *item);
    explicit CommandColorInverterData(const QRect &srcRect, const QRect &destRect);
    CommandColorInverterData get();
private:
    QRect srcRect{}, destRect{};
    QAbstractGraphicsShapeItem *item = nullptr;
};

struct CommandCropData {
public:
    CommandCropData() = default;
    explicit CommandCropData(const QRect &rect);
    CommandCropData get();
private:
    QRect rect{};
};

struct CommandInformation {
    union {
        CommandFigureData figureData{};
        CommandLineData lineData;
        CommandColorInverterData colorInverterData;
        CommandCropData cropData;
    };
    CommandType type = CommandType::none;
};


#endif //IMAGEEDITOR_COMMANDINFORMATION_H
