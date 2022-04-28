#ifndef IMAGEEDITOR_TRIANGLEITEM_H
#define IMAGEEDITOR_TRIANGLEITEM_H


#include "../../../MarqueeItem/marqueeitem.h"

#include <QAbstractGraphicsShapeItem>
#include <QPen>

class IShapeModel;

class TriangleItem : public MarqueeItem {
public:
    explicit TriangleItem(IShapeModel *model);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;
    [[nodiscard]] QPainterPath shape() const override;

    void setRect(const QRectF &rect) override;

protected:
    [[nodiscard]] QPainterPath marqueeShape() const override;
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    static QPainterPath calculateOuterBorder(const QRectF &rect, qreal penWidth);

    qreal x_0 = 0, y_0 = 0, x = 0, y = 0;
    QPainterPath geometry{};

    IShapeModel *model;
};


#endif //IMAGEEDITOR_TRIANGLEITEM_H
