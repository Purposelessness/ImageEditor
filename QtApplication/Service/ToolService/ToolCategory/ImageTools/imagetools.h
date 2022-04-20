#ifndef IMAGEEDITOR_IMAGETOOLS_H
#define IMAGEEDITOR_IMAGETOOLS_H


#include "../toolcategory.h"
#include "imagetoolsmodel.h"
#include "../../Tool/Figure/figure.h"

class QGraphicsPixmapItem;

class ImageTools : public ToolCategory {
public:
    explicit ImageTools(const QString &name = "ImageTools", ImageToolsModel *model = new ImageToolsModel());

private:
    ImageToolsModel *model;
};


#endif //IMAGEEDITOR_IMAGETOOLS_H
