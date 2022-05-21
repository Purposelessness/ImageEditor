#include "imagetoolsmodel.h"
#include "../../Tool/Image/EllipseColorInverter/ellipsecolorinverter.h"
#include "../../Tool/Image/Crop/crop.h"
#include "../../Tool/Image/TriangleRotator/trianglerotator.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    auto crop = new Crop();
    auto rotator = new TriangleRotator();
    addTool(ellipse);
    addTool(crop);
    addTool(rotator);
    setTool(ellipse->toString());
}
