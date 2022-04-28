#include "marqueeobject.h"

MarqueeObject::MarqueeObject(IMarquee *base, MarqueeModelObject *model, QObject *parent) : QObject(parent), base(base),
                                                                                           model(model) {
    connect(model, SIGNAL(marqueePainted(QRectF)), this, SLOT(onMarqueePainted(QRectF)));
}

void MarqueeObject::onMarqueePainted(const QRectF &rect) {
    base->marqueePaintedEvent(rect);
}
