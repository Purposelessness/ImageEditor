#ifndef IMAGEEDITOR_REFLECTOR_H
#define IMAGEEDITOR_REFLECTOR_H


#include "../Marquee/marquee.h"

class Reflector : public Marquee<MarqueeItem> {
public:
    Reflector();

protected:
    void marqueePaintedEvent(const QPainterPath &path) override;
};


#endif //IMAGEEDITOR_REFLECTOR_H
