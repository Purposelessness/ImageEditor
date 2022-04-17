#ifndef IMAGEEDITOR_TRIANGLEITEM_H
#define IMAGEEDITOR_TRIANGLEITEM_H


#include <QAbstractGraphicsShapeItem>
#include <QRubberBand>
#include <QPen>

class TriangleModel;

class TriangleItem : public QAbstractGraphicsShapeItem {
public:
    explicit TriangleItem(TriangleModel *model);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;
    [[nodiscard]] QPainterPath shape() const override;

    void setRect(const QRectF &rect);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    static QPainterPath calculateOuterBorder(const QRectF &rect, qreal penWidth);

    qreal x_0, y_0, x, y;
    QRectF rect{};
    QPainterPath geometry{};

    QPen whitePen;
    QPen blackDotPen;

    TriangleModel *model;
};


#endif //IMAGEEDITOR_TRIANGLEITEM_H
