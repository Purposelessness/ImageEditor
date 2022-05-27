#include "imagetoolsmodel.h"
#include "../../Tool/Image/EllipseColorInverter/ellipsecolorinverter.h"
#include "../../Tool/Image/Crop/crop.h"
#include "../../Tool/Image/TriangleRotator/trianglerotator.h"
#include "../../Tool/Image/Glue/glue.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    auto crop = new Crop();
    auto rotator = new TriangleRotator();
    auto glue = new Glue();
    addTool(ellipse);
    addTool(crop);
    addTool(rotator);
    addTool(glue);
    setTool(ellipse->toString());
}
