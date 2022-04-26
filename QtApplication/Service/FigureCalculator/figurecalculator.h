#ifndef IMAGEEDITOR_FIGURECALCULATOR_H
#define IMAGEEDITOR_FIGURECALCULATOR_H


#include <algorithm>

struct FigurePoints {
    FigurePoints(int x, int y, int width, int height) : x(x), y(y), width(width), height(height) {
        this->data = new bool *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new bool[width]{};
        }
    }

    FigurePoints(FigurePoints const &points) : x(points.x), y(points.y), width(points.width), height(points.height) {
        this->data = new bool *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new bool[width]{};
            for (int k = 0; k < width; ++k) {
                this->data[i][k] = points.data[i][k];
            }
        }
    }

    ~FigurePoints() {
        delete[] data;
    }

    [[nodiscard]] bool contains(int x_0, int y_0) const {
        return this->x <= x_0 && x_0 < this->x + width && this->y <= y_0 && y_0 < this->y + height;
    }

    int x = 0, y = 0;
    bool **data = nullptr;
    const int width = 0, height = 0;
};

class FigureCalculator {
public:
    static FigurePoints calculateEllipse(int xLeft, int yTop, int xRight, int yBottom);

private:
    static bool ellipseCheck(double x, double y, double a, double b);
};


#endif //IMAGEEDITOR_FIGURECALCULATOR_H
