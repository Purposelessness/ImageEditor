#ifndef IMAGEEDITOR_CROP_H
#define IMAGEEDITOR_CROP_H


#include "../Marquee/marquee.h"
#include "../../../MarqueeItem/marqueeitem.h"

class Crop : public Marquee<MarqueeItem> {
public:
    Crop();

protected:
    void marqueePaintedEvent(const QPainterPath &path) override;
};


#endif //IMAGEEDITOR_CROP_H
