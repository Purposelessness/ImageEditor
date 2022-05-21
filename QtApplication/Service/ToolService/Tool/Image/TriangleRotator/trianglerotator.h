#ifndef IMAGEEDITOR_TRIANGLEROTATOR_H
#define IMAGEEDITOR_TRIANGLEROTATOR_H


#include "../Marquee/marquee.h"
#include "../Marquee/trianglemarqueeitem.h"

class TriangleRotator : public Marquee<TriangleMarqueeItem> {
public:
    TriangleRotator();

protected:
    void marqueePaintedEvent(const QPainterPath &path) override;
};


#endif //IMAGEEDITOR_TRIANGLEROTATOR_H
