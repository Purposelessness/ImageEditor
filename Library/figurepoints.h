#ifndef IMAGEEDITOR_FIGUREPOINTS_H
#define IMAGEEDITOR_FIGUREPOINTS_H


#include <cstdint>

enum type {
    none,
    fill,
    border
};

struct FigurePoints {
    FigurePoints(uint32_t x, uint32_t y, uint32_t width, uint32_t height) : x(x), y(y), width(width), height(height) {
        this->data = new type *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new type[width]{};
        }
    }

    FigurePoints(FigurePoints const &points) : x(points.x), y(points.y), width(points.width), height(points.height) {
        this->data = new type *[height]{};
        for (int i = 0; i < height; ++i) {
            this->data[i] = new type[width]{};
            for (int k = 0; k < width; ++k) {
                this->data[i][k] = points.data[i][k];
            }
        }
    }

    ~FigurePoints() {
        delete[] data;
    }

    [[nodiscard]] bool contains(uint32_t x_0, uint32_t y_0) const {
        return this->x <= x_0 && x_0 < this->x + width && this->y <= y_0 && y_0 < this->y + height;
    }

    uint32_t x = 0, y = 0;
    type **data = nullptr;
    const uint32_t width = 0, height = 0;
};


#endif //IMAGEEDITOR_FIGUREPOINTS_H
