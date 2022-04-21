#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../ColorInverter/colorinverter.h"

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto pixmapItem = Data::getPixmapItem();
    if (!pixmapItem)
        return;

    qDebug() << "inverting colors";
    auto image = pixmapItem->pixmap().toImage();
    auto rect = path.boundingRect();
    int x_0 = static_cast<int>(rect.x()), y_0 = static_cast<int>(rect.y());
    auto width = static_cast<int>(rect.width()), height = static_cast<int>(rect.height());
    auto size = static_cast<size_t>(rect.width() * rect.height());
    qDebug() << rect.size() << rect.width() * rect.height() << size;
    auto *pixelData = new PixelData[size];
    for (int x = 0, i = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y, ++i) {
            int x_1 = x_0 + x, y_1 = y_0 + y;
            auto rgb = image.pixel(x_1, y_1);
            pixelData[i] = {x_1, y_1, qRed(rgb), qGreen(rgb), qBlue(rgb)};
        }
    }
//    for (int i = 0; i < size; ++i) {
//        auto point = polygon.at(i).toPoint();
//        auto point = rect.x
//        auto rgb = image.pixel(point);
//        pixelData[i] = {point.x(), point.y(), qRed(rgb), qGreen(rgb), qBlue(rgb)};
//        qDebug() << point.x() << point.y();
//    }
    ColorInverter::invert(pixelData, size);
    for (int i = 0; i < size; ++i) {
        auto data = pixelData[i];
        image.setPixel(data.x, data.y, qRgb(data.red, data.green, data.blue));
    }
    pixmapItem->setPixmap(QPixmap::fromImage(image));
}
