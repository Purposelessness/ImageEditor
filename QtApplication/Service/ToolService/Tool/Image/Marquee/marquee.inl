#include "marquee.h"

template<typename T>
Marquee<T>::Marquee(const QString &name, MarqueeModel<T> *model) : Tool(name, model), model(model),
                                                                   object(new MarqueeObject(this, model->getObject())) {}