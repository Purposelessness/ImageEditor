#ifndef IMAGEEDITOR_TRIANGLEITEM_H
#define IMAGEEDITOR_TRIANGLEITEM_H


#include <QAbstractGraphicsShapeItem>
#include <QRubberBand>

class TriangleModel;

class TriangleItem : public QAbstractGraphicsShapeItem {
public:
    explicit TriangleItem(TriangleModel *model);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;

    void setRect(const QRectF &rect);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    QRectF rect{};
    QPolygonF geometry{};

    TriangleModel *model;
};


#endif //IMAGEEDITOR_TRIANGLEITEM_H
