#include "marqueeobject.h"

MarqueeObject::MarqueeObject(IMarquee *base, MarqueeModelObject *model, QObject *parent) : QObject(parent), base(base),
                                                                                           model(model) {
    connect(model, SIGNAL(marqueePainted(QPainterPath)), this, SLOT(onMarqueePainted(QPainterPath)));
}

void MarqueeObject::onMarqueePainted(const QPainterPath &path) {
    base->marqueePaintedEvent(path);
}
