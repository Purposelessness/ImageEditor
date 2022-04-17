#include "ellipsemarqueeitem.h"

#include <QPainter>

void EllipseMarqueeItem::drawItem(QPainter *painter, const QRectF &rect) {
    painter->drawEllipse(rect);
}
