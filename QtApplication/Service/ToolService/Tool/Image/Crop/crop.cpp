#include "crop.h"
#include "../../../../../Data/data.h"
#include "../../../../UndoService/Command/focusoncommand.h"

#include <QGraphicsRectItem>
#include <QGraphicsScene>

Crop::Crop() : Marquee<MarqueeItem>(tr("Crop")) {}

void Crop::marqueePaintedEvent(const QPainterPath &path) {
    auto view = WidgetData::getInstance().getGraphicsView();
    if (!view)
        return;

    auto pixmapRect = view->getPixmapItem()->boundingRect();

    auto focusItem = new QGraphicsRectItem();
    view->addItem(focusItem);

    focusItem->setBrush(Qt::NoBrush);
    focusItem->setPen(Qt::NoPen);
    auto mappedFromSceneRect = focusItem->mapFromScene(path.boundingRect()).boundingRect();
    auto intersectedRect = pixmapRect.intersected(mappedFromSceneRect);
    focusItem->setRect(intersectedRect);

    auto rect = focusItem->mapToParent(focusItem->boundingRect().toRect()).boundingRect().toRect();
    auto data = CommandCropData{rect};
    auto info = CommandInformation{.cropData = data, .type = CommandType::crop};
    new FocusOnCommand(view, focusItem, view->getFocusItem(), info);
    view->focusOn(focusItem);
}
