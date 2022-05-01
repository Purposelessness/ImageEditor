#include "crop.h"
#include "../../../../../Data/data.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>

Crop::Crop() : Marquee<MarqueeItem>(tr("Crop")) {}

void Crop::marqueePaintedEvent(const QPainterPath &path) {
    auto view = WidgetData::getInstance().getGraphicsView();
    qDebug() << view->getScene()->sceneRect();

    auto focusItem = new QGraphicsRectItem();
    view->addItem(focusItem);

    focusItem->setBrush(Qt::NoBrush);
    focusItem->setRect(path.boundingRect());

    view->focusOn(focusItem);
}
