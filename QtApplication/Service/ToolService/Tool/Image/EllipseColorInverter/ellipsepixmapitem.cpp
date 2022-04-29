#include "ellipsepixmapitem.h"

EllipsePixmapItem::EllipsePixmapItem(const QPixmap &pixmap) : PixmapItem(pixmap) {}

QPainterPath EllipsePixmapItem::marqueeShape() const {
    auto newPath = QPainterPath();
    newPath.addEllipse(PixmapItem::shape().boundingRect());
    return newPath;
}
