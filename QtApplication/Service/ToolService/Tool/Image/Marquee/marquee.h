#ifndef IMAGEEDITOR_MARQUEE_H
#define IMAGEEDITOR_MARQUEE_H


#include "../../tool.h"
#include "marqueemodel.h"

template<typename T>
class Marquee : public Tool {
public:
    explicit Marquee(const QString &name);
};

#include "marquee.inl"


#endif //IMAGEEDITOR_MARQUEE_H
