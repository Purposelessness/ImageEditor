#ifndef IMAGEEDITOR_ELLIPSEMARQUEEITEM_H
#define IMAGEEDITOR_ELLIPSEMARQUEEITEM_H


#include "marqueeitem.h"

class EllipseMarqueeItem : public MarqueeItem {
protected:
    void drawItem(QPainter *painter, const QRectF &rect) override;
};


#endif //IMAGEEDITOR_ELLIPSEMARQUEEITEM_H
