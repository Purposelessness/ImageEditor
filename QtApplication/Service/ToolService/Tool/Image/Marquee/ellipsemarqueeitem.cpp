#include "ellipsemarqueeitem.h"

#include <QPainter>

QPainterPath EllipseMarqueeItem::marqueeShape() const {
    auto path = QPainterPath();
    path.addEllipse(rect);
    return path;
}
