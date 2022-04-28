#ifndef IMAGEEDITOR_MARQUEE_H
#define IMAGEEDITOR_MARQUEE_H


#include "../../tool.h"
#include "marqueeobject.h"
#include "marqueemodel.h"

template<typename T>
class Marquee : public Tool, public IMarquee {
public:
    explicit Marquee(const QString &name, MarqueeModel<T> *model = new MarqueeModel<T>());

protected:
    void marqueePaintedEvent(const QRectF &rect) override = 0;

private:
    MarqueeObject *object;
    MarqueeModel<T> *model;
};

#include "marquee.inl"


#endif //IMAGEEDITOR_MARQUEE_H
