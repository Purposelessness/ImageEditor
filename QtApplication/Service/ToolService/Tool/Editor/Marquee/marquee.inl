#include "marquee.h"

template<typename T>
Marquee<T>::Marquee(const QString &name) : Tool(name, new MarqueeModel<T>()) {}