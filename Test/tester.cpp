#include "tester.h"

#include "../Library/Bitmap/image.h"
#include "../Library/Bitmap/loader.h"
#include "../Library/Bitmap/saver.h"
#include "../Library/Service/FigureCalculator/figurecalculator.h"
#include "../Library/Service/ColorInverter/colorinverter.h"

const char *src = "D:/simpsonsvr.bmp";
const char *dest = "D:/new.bmp";

void Tester::loadAndSave() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    Bitmap::Saver::save(&bmp, dest);
}

void Tester::invertColors() {
    Bitmap::Image bmp = Bitmap::Loader::load(src);
    uint32_t width = bmp.getWidth();
    uint32_t height = bmp.getHeight();
    uint32_t x_0, y_0, x, y;
    x_0 = width / 2;
    x = width;
    y_0 = 0;
    y = height * 1.5;

    auto ellipse = FigureCalculator::calculateEllipse(x_0, y_0, x, y);
    ColorInverter::start(&bmp, ellipse);
    Bitmap::Saver::save(&bmp, dest);
}
