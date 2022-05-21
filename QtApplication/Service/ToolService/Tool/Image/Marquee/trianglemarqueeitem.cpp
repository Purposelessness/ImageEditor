#include "trianglemarqueeitem.h"

QPainterPath TriangleMarqueeItem::shape() const {
    return QGraphicsItem::shape();
}

QPainterPath TriangleMarqueeItem::marqueeShape() const {
    QPainterPath path;
    auto rect = MarqueeItem::boundingRect();
    path.moveTo(rect.bottomLeft());
    path.lineTo(rect.center().x(), rect.top());
    path.lineTo(rect.bottomRight());
    path.lineTo(rect.bottomLeft());
    return path;
}
