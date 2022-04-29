#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverter/colorinverterworker.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "ellipsepixmapitem.h"

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;


    QRect rect = path.boundingRect().toRect();
    FigurePoints points = FigureCalculator::calculateEllipse(0, 0, rect.width(), rect.height());
    auto image = graphicsView->grab(rect).toImage();
    auto newImage = ColorInverterWorker::start(points, image);
    auto pixmapItem = new EllipsePixmapItem(QPixmap::fromImage(newImage));
    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    graphicsView->addItem(pixmapItem);

    auto itemPos = rect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);
    new AddItemCommand(pixmapItem);

    pixmapItem->setSelected(true);
}
