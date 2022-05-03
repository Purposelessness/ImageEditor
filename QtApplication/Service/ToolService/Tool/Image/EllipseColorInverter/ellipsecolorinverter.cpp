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

    auto sceneRect = path.boundingRect();
    auto itemRect = pixmapItem->mapFromScene(path).boundingRect().toRect();
    auto itemPos = itemRect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);

    auto grabRect = QRect(static_cast<int>(sceneRect.left()), static_cast<int>(sceneRect.top()),
                          itemRect.width(), itemRect.height());
    FigurePoints points = FigureCalculator::calculateEllipse(0, 0, grabRect.width(), grabRect.height());
    auto image = graphicsView->grab(grabRect).toImage();

    auto newImage = ColorInverterWorker::start(points, image);

    pixmapItem->setPixmap(QPixmap::fromImage(newImage));
    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    new AddItemCommand(pixmapItem);

    pixmapItem->setSelected(true);
}
