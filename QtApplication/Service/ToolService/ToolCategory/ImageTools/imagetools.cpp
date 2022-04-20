#include "imagetools.h"

ImageTools::ImageTools(const QString &name, ImageToolsModel *model) : ToolCategory(name, model), model(model) {}

void ImageTools::setPixmapItem(QGraphicsPixmapItem *newPixmapItem) {
    model->setPixmapItem(newPixmapItem);
}
