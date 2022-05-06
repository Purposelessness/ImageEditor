#ifndef IMAGEEDITOR_FIGUREPOINTS_H
#define IMAGEEDITOR_FIGUREPOINTS_H


#include <cstdint>

enum Type {
    unknown,
    none,
    fill,
    border
};

struct FigurePoints {
    FigurePoints(int32_t x, int32_t y, int32_t width, int32_t height) : x(x), y(y), width(width), height(height) {
        this->data = new Type *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new Type[width]{};
        }
    }

    FigurePoints(FigurePoints const &points) : x(points.x), y(points.y), width(points.width), height(points.height) {
        this->data = new Type *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new Type[width]{};
            for (int k = 0; k < width; ++k) {
                this->data[i][k] = points.data[i][k];
            }
        }
    }

    ~FigurePoints() {
        delete[] data;
    }

    [[nodiscard]] bool contains(int32_t x_0, int32_t y_0) const {
        return this->x <= x_0 && x_0 < this->x + width && this->y <= y_0 && y_0 < this->y + height;
    }

    int32_t x = 0, y = 0;
    Type **data = nullptr;
    const int32_t width = 0, height = 0;
};


#endif //IMAGEEDITOR_FIGUREPOINTS_H
