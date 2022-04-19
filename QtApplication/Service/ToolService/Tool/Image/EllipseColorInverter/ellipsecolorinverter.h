#ifndef IMAGEEDITOR_ELLIPSECOLORINVERTER_H
#define IMAGEEDITOR_ELLIPSECOLORINVERTER_H


#include "../Marquee/marquee.h"
#include "../Marquee/ellipsemarqueeitem.h"

class EllipseColorInverter : public Marquee<EllipseMarqueeItem> {
Q_OBJECT

public:
    EllipseColorInverter();

signals:
    void invertColors(const QPainterPath &path);

protected:
    void marqueePaintedEvent(const QPainterPath &path) override;
};


#endif //IMAGEEDITOR_ELLIPSECOLORINVERTER_H
