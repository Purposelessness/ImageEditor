#ifndef IMAGEEDITOR_ICOMMAND_H
#define IMAGEEDITOR_ICOMMAND_H


#include <QRect>
#include <QColor>

enum CommandType {
    none,
    ellipse,
    triangle,
    line,
    ellipseColorInverter,
    crop
};

struct LineData {
    int x1{}, y1{}, x2{}, y2{};
    QColor color{};
    int thickness;
};

struct FigureData {
    QRect rect{};
    QColor fillColor{}, borderColor{};
    int thickness{};
};

struct ColorInverterData {
    QRect srcRect{}, destRect{};
};

struct CropData {
    QRect rect{};
};

struct CommandInformation {
    union {
        FigureData figureData;
        LineData lineData;
        ColorInverterData colorInverterData;
        CropData cropData;
    };
    CommandType type = none;
};

class ICommand {
public:
    [[nodiscard]] virtual CommandInformation getInformation() const = 0;
};


#endif //IMAGEEDITOR_ICOMMAND_H
