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
//    auto rect = path.boundingRect();
    auto rect = QRectF(10, 10, 7000, 4000);
//    ColorInverterWorker::test(rect, destImage);
    auto newImage = ColorInverterWorker::start(rect, image);
    qDebug() << image.size() << newImage.size();
    pixmapItem->setPixmap(QPixmap::fromImage(newImage));
}
