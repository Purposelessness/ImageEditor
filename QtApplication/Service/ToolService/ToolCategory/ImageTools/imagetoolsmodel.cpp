#include "imagetoolsmodel.h"
#include "../../Tool/Image//EllipseColorInverter/ellipsecolorinverter.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    addTool(ellipse);
    setTool(ellipse->toString());
}
