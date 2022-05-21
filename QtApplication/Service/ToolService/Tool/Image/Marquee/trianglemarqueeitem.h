#ifndef IMAGEEDITOR_TRIANGLEMARQUEEITEM_H
#define IMAGEEDITOR_TRIANGLEMARQUEEITEM_H


#include "../../../MarqueeItem/marqueeitem.h"

class TriangleMarqueeItem : public MarqueeItem {
public:
    [[nodiscard]] QPainterPath shape() const override;

protected:
    [[nodiscard]] QPainterPath marqueeShape() const override;
};


#endif //IMAGEEDITOR_TRIANGLEMARQUEEITEM_H
