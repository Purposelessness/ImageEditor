#ifndef IMAGEEDITOR_GRAPHICSTRIANGLEITEM_H
#define IMAGEEDITOR_GRAPHICSTRIANGLEITEM_H

#include <QAbstractGraphicsShapeItem>

class GraphicsTriangleItem : public QAbstractGraphicsShapeItem {
public:
    explicit GraphicsTriangleItem(QGraphicsItem *parent = nullptr);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;
    void setRect(const QRectF &rect);

private:
    QPolygonF polygon{3};
};


#endif //IMAGEEDITOR_GRAPHICSTRIANGLEITEM_H
