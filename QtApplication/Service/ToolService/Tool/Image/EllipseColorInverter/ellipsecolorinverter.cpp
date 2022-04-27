#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverter/colorinverterworker.h"

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    qDebug() << "inverting colors";
    auto rectF = path.boundingRect();
    QRect rect = rectF.toRect();
    FigurePoints points = FigureCalculator::calculateEllipse(0, 0, rectF.width(), rectF.height());
    auto image = graphicsView->grab(rect).toImage();
    auto newImage = ColorInverterWorker::start(points, image);
    auto mainPixmapItem = graphicsView->getPixmapItem();
    auto newPixmapItem = new QGraphicsPixmapItem(QPixmap::fromImage(newImage));
    graphicsView->addItem(newPixmapItem);
}
