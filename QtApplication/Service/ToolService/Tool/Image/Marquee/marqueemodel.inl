#include <QRectF>
#include "marqueemodel.h"
#include "../../../MarqueeItem/marqueeitem.h"

template<typename T>
MarqueeModel<T>::MarqueeModel() : object(new MarqueeModelObject()) {
    static_assert(std::is_base_of<MarqueeItem, T>::value, "Class must derive from MarqueeItem");
}

template<typename T>
QGraphicsItem *MarqueeModel<T>::startDrawing(const Coordinates &coordinates) {
    marqueeItem = new T();
    marqueeItem->setRect(QRectF(coordinates.x_0, coordinates.y_0, 0, 0));
    return marqueeItem;
}

template<typename T>
void MarqueeModel<T>::onDrawing(const Coordinates &coordinates) {
    auto normalizedRect = normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
    marqueeItem->setRect(normalizedRect);
}

template<typename T>
void MarqueeModel<T>::finishDrawing(const Coordinates &coordinates) {
    auto normalizedRect = normalizeRect(coordinates.x_0, coordinates.y_0, coordinates.x, coordinates.y);
    marqueeItem->setSelected(true);
    marqueeItem->setRect(normalizedRect);
    QRectF rect = marqueeItem->boundingRect();
    delete marqueeItem;
    emit object->marqueePainted(rect);
    marqueeItem = nullptr;
}

template<typename T>
MarqueeModelObject *MarqueeModel<T>::getObject() {
    return object;
}
