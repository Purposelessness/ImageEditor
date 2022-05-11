#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverterWorker//colorinverterworker.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "ellipsepixmapitem.h"

#include <QDialog>
#include <QLabel>

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    auto pixmapItem = new EllipsePixmapItem();
    graphicsView->addItem(pixmapItem);

    auto sceneRect = path.boundingRect().toRect();

    int x0 = sceneRect.left();
    int y0 = sceneRect.top();
    auto cachedRect = sceneRect;
    FigurePoints points = Calculator::ellipse(0, 0, sceneRect.width(),sceneRect.height());
    auto image = graphicsView->grab(&sceneRect).toImage();
    points.x = x0 - sceneRect.left();
    points.y = y0 - sceneRect.top();
    QPoint sceneOffset(points.x, points.y);

    auto itemRect = pixmapItem->mapFromScene(sceneRect).boundingRect().toRect();
    auto itemPos = itemRect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);

    auto newImage = ColorInverterWorker::start(points, image);

    auto pixmap = QPixmap::fromImage(newImage).scaledToWidth(itemRect.width());
    pixmapItem->setPixmap(pixmap);

    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    auto offset = pixmapItem->mapToParent(pixmapItem->mapFromScene(sceneOffset)).toPoint();
    auto rect = pixmapItem->mapToParent(pixmapItem->mapFromScene(cachedRect)).boundingRect().toRect();
    auto data = CommandColorInverterData{rect, offset, pixmapItem};
    auto info = CommandInformation{.colorInverterData = data, .type = CommandType::ellipseColorInverter};
    new AddItemCommand(pixmapItem, info);

    pixmapItem->setSelected(true);
}
