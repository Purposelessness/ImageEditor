#ifndef IMAGEEDITOR_COMMANDINFORMATION_H
#define IMAGEEDITOR_COMMANDINFORMATION_H


#include <QRect>
#include <QColor>

enum class CommandType {
    none,
    ellipse,
    triangle,
    line,
    ellipseColorInverter,
    crop
};

struct CommandLineData {
    int x1{}, y1{}, x2{}, y2{};
    QColor color{};
    int thickness;
};

struct CommandFigureData {
    QRect rect{};
    QColor fillColor{}, borderColor{};
    int thickness{};
};

struct CommandColorInverterData {
    QRect srcRect{}, destRect{};
};

struct CommandCropData {
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
