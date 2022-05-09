#include "crop.h"
#include "../../../../../Data/data.h"
#include "../../../../UndoService/Command/focusoncommand.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>

Crop::Crop() : Marquee<MarqueeItem>(tr("Crop")) {}

void Crop::marqueePaintedEvent(const QPainterPath &path) {
    auto view = WidgetData::getInstance().getGraphicsView();

    auto focusItem = new QGraphicsRectItem();
    view->addItem(focusItem);

    focusItem->setBrush(Qt::NoBrush);
    focusItem->setPen(Qt::NoPen);
    focusItem->setRect(focusItem->mapFromScene(path.boundingRect()).boundingRect());

    auto rect = focusItem->mapToParent(focusItem->boundingRect().toRect()).boundingRect().toRect();
    auto data = CommandCropData{rect};
    auto info = CommandInformation{.cropData = data, .type = CommandType::crop};
    new FocusOnCommand(view, focusItem, view->getFocusItem(), info);
    view->focusOn(focusItem);
}
