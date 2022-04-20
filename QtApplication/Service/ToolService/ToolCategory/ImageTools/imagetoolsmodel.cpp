#include "imagetoolsmodel.h"
#include "../../Tool/Image//EllipseColorInverter/ellipsecolorinverter.h"

ImageToolsModel::ImageToolsModel() : object(new ImageToolsModelObject(this)) {}

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    addTool(ellipse);
    QObject::connect(ellipse, SIGNAL(invertColors(QPainterPath)), object, SLOT(invertColors(QPainterPath)));
    setTool(ellipse->toString());
}

void ImageToolsModel::invertColors(const QPainterPath &path) {

}

ImageToolsModelObject::ImageToolsModelObject(IImageToolsModel *base, QObject *parent) : QObject(parent), base(base) {}

void ImageToolsModelObject::invertColors(const QPainterPath &path) {
    base->invertColors(path);
}

void ImageToolsModel::setPixmapItem(QGraphicsPixmapItem *newPixmapItem) {
    pixmapItem = newPixmapItem;
}
