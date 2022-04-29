#include "ellipsemarqueeitem.h"

#include <QPainter>

QPainterPath EllipseMarqueeItem::marqueeShape() const {
    return shape();
}

QPainterPath EllipseMarqueeItem::shape() const {
    QPainterPath path = QPainterPath();
    path.addEllipse(boundingRect());
    return path;
}
