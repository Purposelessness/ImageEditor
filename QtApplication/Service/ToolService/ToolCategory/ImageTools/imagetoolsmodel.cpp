#include "imagetoolsmodel.h"
#include "../../Tool/Image/EllipseColorInverter/ellipsecolorinverter.h"
#include "../../Tool/Image/Crop/crop.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    auto crop = new Crop();
    addTool(ellipse);
    addTool(crop);
    setTool(ellipse->toString());
}
