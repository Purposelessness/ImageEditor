#include "tester.h"

#include "../Library/Bitmap/image.h"
#include "../Library/Bitmap/loader.h"
#include "../Library/Bitmap/saver.h"
#include "../Library/Service/FigureCalculator/calculator.h"
#include "../Library/Service/ColorInverter/colorinverter.h"
#include "../Library/Service/Painter/painter.h"
#include "../Library/Service/Benchmark/benchmark.h"

#include <cstdio>
#include <ctime>

const char *src = "D:/simpsonsvr.bmp";
const char *dest = "D:/new.bmp";

void Tester::sizeOf() {
    printf("CoreHeader %llu; V3Header %llu; V4Header %llu; V5Header %llu\n", sizeof(Bitmap::CoreHeader),
           sizeof(Bitmap::V3Header), sizeof(Bitmap::V4Header), sizeof(Bitmap::V5Header));
}

void Tester::loadAndSave() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::invertColors() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();
    int32_t x_0, y_0, x, y;
    x_0 = width / 2;
    x = width;
    y_0 = 0;
    y = height * 1.5;

    auto ellipse = Calculator::calculateEllipse(x_0, y_0, x, y);
    ColorInverter::start(&bmp, ellipse);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintEllipse() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();
    int32_t x_0, y_0, x, y;
    x_0 = width / 2;
    x = width;
    y_0 = 0;
    y = height * 1.5;

    auto ellipse = Calculator::calculateEllipse(x_0, y_0, x, y, 1);
    Painter::start(&bmp, ellipse, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintBorderEllipse() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();
    int32_t x_0, y_0, x, y;
    x_0 = width / 2;
    x = width;
    y_0 = 0;
    y = height * 1.5;

    auto ellipse = Calculator::calculateEllipse(x_0, y_0, x, y, 1, false);
    Painter::start(&bmp, ellipse, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintOnePixelLine() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();
    int32_t x_0, y_0, x, y;
    x_0 = 0;
    x = width;
    y_0 = 0;
    y = height;

    printf("Line\n");
    auto line = Calculator::calculateLine(x_0, y_0, x, y, 1);
    Painter::start(&bmp, line, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintStraightOnePixelLine() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();

    auto line = Calculator::calculateLine(0, 0, width - 1, height - 1, 1);
    Painter::start(&bmp, line, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line1 = Calculator::calculateLine(width / 2, 0, width / 2, height - 1, 1);
    Painter::start(&bmp, line1, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line2 = Calculator::calculateLine(0, 10, width, 10, 3);
    Painter::start(&bmp, line2, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line3 = Calculator::calculateLine(width, 0, width, height, 10);
    Painter::start(&bmp, line3, Rgb{190, 60, 60}, Rgb{60, 70, 190});

    Bitmap::Saver::save(&bmp, dest);
}
