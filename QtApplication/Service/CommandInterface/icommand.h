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

struct FigureData {
    QRect rect{};
    QColor fillColor{}, borderColor{};
    int thickness{};
};

struct ColorInverterData {
    QRect srcRect{}, destRect{};
};

struct CommandInformation {
    union {
        FigureData figureData;
        ColorInverterData colorInverterData;
    };
    CommandType type = none;
};

class ICommand {
public:
    [[nodiscard]] virtual CommandInformation getInformation() const = 0;
};


#endif //IMAGEEDITOR_ICOMMAND_H
