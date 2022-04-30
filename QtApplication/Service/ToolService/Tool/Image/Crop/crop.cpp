#include "crop.h"
#include "../../../../../Data/data.h"

#include <QGraphicsScene>

Crop::Crop() : Marquee<MarqueeItem>(tr("Crop")) {}

void Crop::marqueePaintedEvent(const QPainterPath &path) {
    auto view = WidgetData::getInstance().getGraphicsView();
    qDebug() << view->getScene()->sceneRect();
    view->fitInView(path.boundingRect().toRect());
}
