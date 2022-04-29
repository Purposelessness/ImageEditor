#ifndef IMAGEEDITOR_ELLIPSEPIXMAPITEM_H
#define IMAGEEDITOR_ELLIPSEPIXMAPITEM_H


#include "../PixmapItem/pixmapitem.h"

class EllipsePixmapItem : public PixmapItem {
public:
    explicit EllipsePixmapItem(const QPixmap &pixmap);

protected:
    [[nodiscard]] QPainterPath marqueeShape() const override;
};


#endif //IMAGEEDITOR_ELLIPSEPIXMAPITEM_H
