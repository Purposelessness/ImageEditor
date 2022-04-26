#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../ColorInverter/colorinverterworker.h"

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto pixmapItem = Data::getPixmapItem();
    if (!pixmapItem)
        return;

    qDebug() << "inverting colors";
    auto image = pixmapItem->pixmap().toImage();
    auto rect = path.boundingRect();
    FigurePoints points = FigureCalculator::calculateEllipse(rect.left(), rect.top(), rect.right(), rect.bottom());
    ColorInverterWorker::test(points, image);
//    auto newImage = ColorInverterWorker::start(points, image);
//    pixmapItem->setPixmap(QPixmap::fromImage(newImage));
}
