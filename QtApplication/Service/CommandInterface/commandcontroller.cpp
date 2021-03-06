#include "commandcontroller.h"
#include "command.h"

#include "../../../Library/Bitmap/image.h"
#include "../../../Library/Bitmap/loader.h"
#include "../../../Library/Bitmap/saver.h"
#include "../../../Library/Service/FigureCalculator/calculator.h"
#include "../../../Library/Service/ColorInverter/colorinverter.h"
#include "../../../Library/Service/Painter/painter.h"
#include "../../../Library/Service/Rotator/rotator.h"
#include "../../../Library/Service/Outliner/outliner.h"
#include "../../../Library/Service/Glue/glue.h"
#include "../../../Library/Service/Reflector/reflector.h"

#include <utility>

CommandController::CommandController(QString srcFileName, QString destFileName, QVector<Command *> commands)
                 : srcFileName(std::move(srcFileName)), destFileName(std::move(destFileName)), commands(std::move(commands))  {}

void CommandController::start() {
    auto image = Bitmap::Loader::load(srcFileName.toUtf8().constData());
    ExitCode code = ExitCode::success;
    for (auto command: commands) {
        auto info = command->getInformation();
        code = processImage(&image, info);
    }
    Bitmap::Saver::save(&image, destFileName.toUtf8().constData());
    emit finished(code);
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
        case CommandType::triangleRotator:
            rotateTriangle(image, info.rotatorData);
            break;
        case CommandType::outline:
            outline(image, info.outlinerData);
            break;
        case CommandType::glue:
            glue(image, info.glueData);
            break;
        case CommandType::reflector:
            reflect(image, info.reflectorData);
            break;
        default:
            return ExitCode::unknown;
    }
    return ExitCode::success;
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
    int x1s, y1s, ws, hs;
    int x1d, y1d, wd, hd;
    data.srcRect.getRect(&x1s, &y1s, &ws, &hs);
    data.destRect.getRect(&x1d, &y1d, &wd, &hd);
    auto ellipse = Calculator::ellipse(x1s, y1s, x1s + ws - 1, y1s + hs - 1);
    x1d += data.offset.x();
    y1d += data.offset.y();
    ColorInverter::start(image, Point{x1d, y1d}, &srcImage, ellipse);
}

void CommandController::cropImage(Bitmap::Image *image, CommandCropData data) {
    int xl, yt, w, h;
    data.rect.getRect(&xl, &yt, &w, &h);
    image->setCropRect(Rect{xl, yt, w, h});
}

Rgb CommandController::convertQColorToRgb(const QColor &color) {
    return color.isValid() ? Rgb{static_cast<uint8_t>(color.blue()),
                                 static_cast<uint8_t>(color.green()),
                                 static_cast<uint8_t>(color.red())}
                           : Rgb{};
}

void CommandController::rotateTriangle(Bitmap::Image *image, CommandRotatorData data) {
    data.update();
    int x1s, y1s, x2s, y2s;
    int x1d, y1d, wd, hd;
    data.srcRect.getCoords(&x1s, &y1s, &x2s, &y2s);
    data.destRect.getRect(&x1d, &y1d, &wd, &hd);
    auto ellipse = Calculator::triangle(x1s, y1s, x2s, y2s);
    x1d += data.offset.x();
    y1d += data.offset.y();
    Rotator::startBmpShear(image, Point{x1d, y1d}, ellipse, data.angle);
}

void CommandController::outline(Bitmap::Image *image, CommandOutlinerData data) {
    Outliner::start(image, convertQColorToRgb(data.color), convertQColorToRgb(data.destColor), data.width);
}

void CommandController::glue(Bitmap::Image *image, CommandGlueData data) {
    auto i2 = Bitmap::Loader::load(data.imagePath);
    Glue::start(image, &i2);
}

void CommandController::reflect(Bitmap::Image *image, CommandReflectorData data) {
    int x, y, w, h;
    data.rect.getRect(&x, &y, &w, &h);
    Reflector::start(image, {x, y, w, h}, Orientation::vertical);
}
