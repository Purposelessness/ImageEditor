#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverter/colorinverterworker.h"
#include "../../../../UndoService/Command/additemcommand.h"

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QRectF &rectF) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    auto pixmapItem = new QGraphicsPixmapItem();
    graphicsView->addItem(pixmapItem);

    QRect rect = rectF.toRect();
    FigurePoints points = FigureCalculator::calculateEllipse(0, 0, rect.width(), rect.height());
    auto image = graphicsView->grab(rect).toImage();
    auto newImage = ColorInverterWorker::start(points, image);
    pixmapItem->setPixmap(QPixmap::fromImage(newImage));

    auto itemPos = rect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);
    new AddItemCommand(pixmapItem);
}
