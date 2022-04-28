#ifndef IMAGEEDITOR_ELLIPSEMARQUEEITEM_H
#define IMAGEEDITOR_ELLIPSEMARQUEEITEM_H


#include "../../../MarqueeItem/marqueeitem.h"

class EllipseMarqueeItem : public MarqueeItem {
protected:
    [[nodiscard]] QPainterPath marqueeShape() const override;
};


#endif //IMAGEEDITOR_ELLIPSEMARQUEEITEM_H
