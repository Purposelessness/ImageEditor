#include "trianglerotator.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverterWorker//colorinverterworker.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "../PixmapItem/pixmapitem.h"

TriangleRotator::TriangleRotator() : Marquee<TriangleMarqueeItem>(tr("TriangleRotator")) {}

void TriangleRotator::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    auto pixmapItem = new PixmapItem();
    graphicsView->addItem(pixmapItem);

    auto sceneRect = path.boundingRect().toRect();

    int x0 = sceneRect.left();
    int y0 = sceneRect.top();
    auto cachedRect = sceneRect;
    FigurePoints points = Calculator::triangle(0, 0, sceneRect.width(),sceneRect.height());
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
    pixmapItem->setTransformOriginPoint(pixmapItem->boundingRect().center());

    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    auto offset = pixmapItem->mapToParent(pixmapItem->mapFromScene(sceneOffset)).toPoint();
    auto rect = pixmapItem->mapToParent(pixmapItem->mapFromScene(cachedRect)).boundingRect().toRect();
    auto data = CommandColorInverterData{rect, offset, pixmapItem};
    auto info = CommandInformation{.colorInverterData = data, .type = CommandType::triangleRotator};
    pixmapItem->setRotation(90);
    new AddItemCommand(pixmapItem, info);

    pixmapItem->setSelected(true);
}
