#include "triangle.h"
#include "line.h"
#include "../../FloodFiller/floodfiller.h"

#include <cmath>

FigurePoints Triangle::calculate(int32_t xLeft, int32_t yTop, int32_t xRight, int32_t yBottom, int32_t borderWidth, bool fillFlag) {
    if (borderWidth == 1) {
        int32_t width = xRight - xLeft;
        int32_t height = yBottom - yTop;
        FigurePoints points{xLeft, yTop, width + 1, height + 1};

        int32_t x1 = 0;
        int32_t y1 = height;
        int32_t x2 = width / 2;
        int32_t y2 = 0;
        int32_t x3 = width;
        int32_t y3 = y1;

        Line::bresenhamAlgorithm(&points, x1, x2, y1, y2);
        Line::bresenhamAlgorithm(&points, x2, x3, y2, y3);
        Line::bresenhamAlgorithm(&points, x3, x1, y3, y1);

        if (fillFlag) FloodFiller::start(&points);

        return points;
    }

    if (borderWidth == 3) --borderWidth;

    double dd = borderWidth / 2.0;
    int32_t width = abs(xRight - xLeft);
    int32_t height = abs(yBottom - yTop);
    int32_t a = width / 2;
    int32_t b = height;
    int32_t xm = xLeft + a;
    double c = Line::lineLength(xLeft, yBottom, xm, yTop);
    double cotHalfA = sqrt((c + a)/(c - a));
    double xsd = dd * cotHalfA;
    double ysd = dd * c / a;
    auto d = static_cast<int32_t>(round(dd));
    auto xs = static_cast<int32_t>(round(xsd));
    auto ys = static_cast<int32_t>(round(ysd));

    int32_t xl = xLeft - xs;
    int32_t xr = xRight + xs;
    int32_t yt = yTop - ys;
    int32_t yb = yBottom + d;
    int32_t nw = xr - xl;
    int32_t nh = yb - yt;
    FigurePoints points{xl, yt, nw + 1, nh + 1};

    auto xs2 = static_cast<int32_t>(round(xsd * 2));
    auto ys2 = static_cast<int32_t>(round(ysd * 2));
    auto yspd = static_cast<int32_t>(round(dd + ysd));
    auto ysmd = static_cast<int32_t>(round(ys - dd));

    xm = width / 2;
    int32_t x0o, x1o, x2o, x0i, x1i, x2i, y0o, y1o, y2o, y0i, y1i, y2i;
    x0o = 0;
    x1o = xm + xs;
    x2o = width + xs2;
    y0o = height + yspd;
    y1o = 0;
    y2o = y0o;
    x0i = 0 + xs2;
    x1i = xm + xs;
    x2i = width;
    y0i = 0 + height + ysmd;
    y1i = 0 + ys2;
    y2i = y0i;

    Line::bresenhamAlgorithm(&points, x0o, x1o, y0o, y1o);
    Line::bresenhamAlgorithm(&points, x1o, x2o, y1o, y2o);
    Line::bresenhamAlgorithm(&points, x2o, x0o, y2o, y0o);
    Line::bresenhamAlgorithm(&points, x0i, x1i, y0i, y1i);
    Line::bresenhamAlgorithm(&points, x1i, x2i, y1i, y2i);
    Line::bresenhamAlgorithm(&points, x2i, x0i, y2i, y0i);

    FloodFiller::start(&points, FillType::border, FillType::border);
    if (fillFlag) FloodFiller::start(&points);

    return points;
}
