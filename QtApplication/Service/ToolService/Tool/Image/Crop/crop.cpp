#include "crop.h"
#include "../../../../../Data/data.h"

#include <QGraphicsRectItem>

Crop::Crop() : Marquee<MarqueeItem>(tr("Crop")) {}

void Crop::marqueePaintedEvent(const QPainterPath &path) {
    auto view = WidgetData::getInstance().getGraphicsView();
    view->fitInView(path.boundingRect());
}
