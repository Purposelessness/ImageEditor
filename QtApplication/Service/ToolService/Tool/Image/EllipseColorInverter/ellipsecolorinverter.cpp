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
//    ColorInverterWorker::test(rect, image);
    auto newImage = ColorInverterWorker::start(rect, image);
    pixmapItem->setPixmap(QPixmap::fromImage(newImage));
}
