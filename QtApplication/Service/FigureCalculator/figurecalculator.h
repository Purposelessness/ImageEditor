#ifndef IMAGEEDITOR_FIGURECALCULATOR_H
#define IMAGEEDITOR_FIGURECALCULATOR_H


struct FigurePoints {
    FigurePoints(int xSize, int ySize) : xSize(xSize), ySize(ySize) {
        this->data = new bool*[ySize]{};
        for (int i = 0; i < ySize; ++i) {
            this->data[i] = new bool[xSize]{};
        }
    }

    ~FigurePoints() {
        delete[] data;
    }

    int x = 0, y = 0;
    bool **data = nullptr;
    const int xSize, ySize;
};

class FigureCalculator {
public:
    static FigurePoints calculateEllipse(int xLeft, int yTop, int xRight, int yBottom);

private:
    static bool ellipseCheck(double x, double y, double x_0, double y_0, double a, double b);
};


#endif //IMAGEEDITOR_FIGURECALCULATOR_H
