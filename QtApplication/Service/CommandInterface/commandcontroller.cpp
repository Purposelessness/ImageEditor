#include "commandcontroller.h"
#include "command.h"

#include "../../../Library/Bitmap/image.h"
#include "../../../Library/Bitmap/loader.h"
#include "../../../Library/Bitmap/saver.h"
#include "../../../Library/Service/FigureCalculator/calculator.h"
#include "../../../Library/Service/ColorInverter/colorinverter.h"
#include "../../../Library/Service/Painter/painter.h"

#include <utility>

CommandController::CommandController(QString srcFileName, QString destFileName, QVector<Command *> commands)
                 : srcFileName(std::move(srcFileName)), destFileName(std::move(destFileName)), commands(std::move(commands))  {}

void CommandController::start() {
    auto image = Bitmap::Loader::load(srcFileName.toUtf8().constData());
    for (auto command: commands) {
        auto info = command->getInformation();
        processImage(&image, info);
    }
    Bitmap::Saver::save(&image, destFileName.toUtf8().constData());
    emit finished(ExitCode::success);
}

void CommandController::terminate() {

}

ExitCode CommandController::processImage(Bitmap::Image *image, const CommandInformation &info) {
    switch (info.type) {
        case CommandType::none:
            return ExitCode::invalid;
        case CommandType::ellipse:
            drawEllipse(image, info.figureData);
            break;
        case CommandType::triangle:
            drawTriangle(image, info.figureData);
            break;
        case CommandType::line:
            drawLine(image, info.lineData);
            break;
        case CommandType::ellipseColorInverter:
            invertColorsInEllipse(image, info.colorInverterData);
            break;
        case CommandType::crop:
            cropImage(image, info.cropData);
            break;
    }
    return ExitCode::unknown;
}

void CommandController::drawEllipse(Bitmap::Image *image, CommandFigureData data) {
    data.update();
    int x1, y1, x2, y2;
    data.rect.getCoords(&x1, &y1, &x2, &y2);
    auto fillColor = data.fillColor;
    auto borderColor = data.borderColor;

    auto ellipse = Calculator::ellipse(x1, y1, x2, y2, data.thickness, fillColor.isValid());
    Painter::start(image, ellipse, convertQColorToRgb(fillColor), convertQColorToRgb(borderColor));
}

void CommandController::drawTriangle(Bitmap::Image *image, CommandFigureData data) {
    data.update();
    int x1, y1, x2, y2;
    data.rect.getCoords(&x1, &y1, &x2, &y2);
    auto fillColor = data.fillColor;
    auto borderColor = data.borderColor;

    auto triangle = Calculator::triangle(x1, y1, x2, y2, data.thickness, fillColor.isValid());
    Painter::start(image, triangle, convertQColorToRgb(fillColor), convertQColorToRgb(borderColor));
}

void CommandController::drawLine(Bitmap::Image *image, CommandLineData data) {
    data.update();
    auto line = Calculator::line(data.x1, data.y1, data.x2, data.y2, data.thickness);
    Painter::start(image, line, Rgb{}, convertQColorToRgb(data.color));
}

void CommandController::invertColorsInEllipse(Bitmap::Image *image, CommandColorInverterData data) {
    Bitmap::Image srcImage = *image;
    data.update();
    int x1s, y1s, x2s, y2s;
    int x1d, y1d, x2d, y2d;
    data.srcRect.getCoords(&x1s, &y1s, &x2s, &y2s);
    data.destRect.getCoords(&x1d, &y1d, &x2d, &y2d);
    auto ellipse = Calculator::ellipse(x1s, y1s, x2s, y2s);
    ColorInverter::start(image, Point{x1d, y1d}, &srcImage, ellipse);
}

void CommandController::cropImage(Bitmap::Image *image, CommandCropData data) {

}

Rgb CommandController::convertQColorToRgb(const QColor &color) {
    return color.isValid() ? Rgb{static_cast<uint8_t>(color.green()),
                                 static_cast<uint8_t>(color.red()),
                                 static_cast<uint8_t>(color.blue()),}
                           : Rgb{};
}
