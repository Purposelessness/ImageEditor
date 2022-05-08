#ifndef IMAGEEDITOR_SHAPEMODEL_H
#define IMAGEEDITOR_SHAPEMODEL_H


#include "figuremodel.h"
#include "ishapemodel.h"

#include <QAbstractGraphicsShapeItem>

template<typename T>
class ShapeModel : public FigureModel, public IShapeModel {
public:
    ShapeModel();

    void setType(CommandType type);

    void setFillColor(const QColor &color = QColor());
    void setLineColor(const QColor &color = QColor());
    void setThickness(const int &value);

    [[nodiscard]] FigureData getData() const override;
    void onItemSelected(QAbstractGraphicsShapeItem *abstractGraphicsShapeItem) override;
    void onItemDeselected() override;

protected:
    QGraphicsItem *startDrawing(const Coordinates &coordinates) override;
    void onDrawing(const Coordinates &coordinates) override;
    void finishDrawing(const Coordinates &coordinates) override;
    void addCommand(const Coordinates &coordinates) override;

private:
    static QBrush brush;
    static QPen pen;
    static int thickness;

    T *item = nullptr;
    QAbstractGraphicsShapeItem *selectedItem = nullptr;
    CommandType type = CommandType::none;
};

#include "shapemodel.inl"


#endif //IMAGEEDITOR_SHAPEMODEL_H
