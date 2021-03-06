#include "tester.h"

#include "../Library/Bitmap/image.h"
#include "../Library/Bitmap/loader.h"
#include "../Library/Bitmap/saver.h"
#include "../Library/Service/FigureCalculator/calculator.h"
#include "../Library/Service/ColorInverter/colorinverter.h"
#include "../Library/Service/Painter/painter.h"
#include "../Library/Service/Benchmark/benchmark.h"
#include "../Library/Service/Scaler/scaler.h"
#include "../Library/Service/Rotator/rotator.h"
#include "../Library/Service/Outliner/outliner.h"
#include "../Library/Service/Glue/glue.h"

#include <cstdio>

const char *src = "D:/BMP/red_big.bmp";
const char *marbles = "D:/BMP/marbles.bmp";
const char *srcSmall = "D:/BMP/red_small.bmp";
const char *simpson = "D:/BMP/simpson.bmp";
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

    auto ellipse = Calculator::ellipse(x_0, y_0, x, y);
    ColorInverter::start(&bmp, ellipse);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintEllipse() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();
    int32_t x_0, y_0, x, y;
    x_0 = 0 + 50;
    x = width - 50;
    y_0 = 50;
    y = height - 50;

    auto ellipse = Calculator::ellipse(x_0, y_0, x, y, 10, false);
    Painter::start(&bmp, ellipse, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto ellipse1 = Calculator::ellipse(50, 50, width / 2 - 50, height - 50, 0);
    Painter::start(&bmp, ellipse1, Rgb{190, 60, 60}, Rgb{60, 70, 190});

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

    auto ellipse = Calculator::ellipse(x_0, y_0, x, y, 1, false);
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
    auto line = Calculator::line(x_0, y_0, x, y, 1);
    Painter::start(&bmp, line, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintSimpleLines() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();

    auto line = Calculator::line(0, 0, width - 1, height - 1, 1);
    Painter::start(&bmp, line, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line1 = Calculator::line(width / 2, 0, width / 2, height - 1, 1);
    Painter::start(&bmp, line1, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line2 = Calculator::line(0, 10, width, 10, 3);
    Painter::start(&bmp, line2, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line3 = Calculator::line(width, 0, width, height, 10);
    Painter::start(&bmp, line3, Rgb{190, 60, 60}, Rgb{60, 70, 190});

    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintComplexLines() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();

    auto line = Calculator::line(10, 100, width - 10, 500, 50);
    Painter::start(&bmp, line, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto line1 = Calculator::line(10, 500, width - 10, 100, 50);
    Painter::start(&bmp, line1, Rgb{190, 60, 60}, Rgb{60, 70, 190});

    Bitmap::Saver::save(&bmp, dest);
}

void Tester::paintTriangle() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();

    auto triangle = Calculator::triangle(50, 50, width / 2, 55, 3);
    Painter::start(&bmp, triangle, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto triangle1 = Calculator::triangle(width / 2 + 50, 50, width - 50, height / 2, 1);
    Painter::start(&bmp, triangle1, Rgb{190, 60, 60}, Rgb{60, 70, 190});
    auto triangle2 = Calculator::triangle(0 + 50, height / 2, width / 2 - 50, height - 50);
    Painter::start(&bmp, triangle2, Rgb{190, 60, 60}, Rgb{60, 70, 190});

    Bitmap::Saver::save(&bmp, dest);
}

void Tester::invertDifferentImages() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    Bitmap::Image srcBmp = bmp;
    int32_t width = bmp.getWidth();
    int32_t height = bmp.getHeight();

    auto ellipse = Calculator::ellipse(width / 2, -10, width - 100, height / 2);
    ColorInverter::start(&bmp, Point{20, height / 2}, &srcBmp, ellipse);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::scale() {
    Bitmap::Image bmp = Bitmap::Loader::load(simpson);
    auto nBmp = Scaler::startBmp(bmp, bmp.getWidth() * 4, bmp.getHeight() * 4);
    Bitmap::Saver::save(&nBmp, dest);
}

void Tester::scaleArea() {
    Bitmap::Image bmp = Bitmap::Loader::load(simpson);
    FigurePoints p{bmp.getWidth() / 2, bmp.getHeight() / 2, bmp.getWidth() / 2, bmp.getHeight() / 2};
    auto nBmp = Scaler::startBmp(bmp, bmp.getWidth(), bmp.getHeight(), p);
    Bitmap::Saver::save(&nBmp, dest);
}

void Tester::rotate() {
    Bitmap::Image bmp = Bitmap::Loader::load(simpson);
    auto triangle = Calculator::triangle(bmp.getWidth() / 4, bmp.getHeight() / 4, bmp.getWidth() * 3 / 4,bmp.getHeight() * 3 / 4);
    Rotator::startBmpShear(&bmp, {0, 0}, triangle, 30);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::outline() {
    Bitmap::Image bmp = Bitmap::Loader::load(marbles);
    Outliner::start(&bmp, Rgb{255, 255, 255}, Rgb{255, 0, 255}, 1);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::glue() {
    Bitmap::Image bmp1 = Bitmap::Loader::load(marbles);
    Bitmap::Image bmp2 = Bitmap::Loader::load(simpson);
    Glue::start(&bmp1, &bmp2);
    Bitmap::Saver::save(&bmp1, dest);
}
