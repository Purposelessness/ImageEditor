#include "imagetoolsmodel.h"
#include "../../Tool/Image/EllipseColorInverter/ellipsecolorinverter.h"
#include "../../Tool/Image/Crop/crop.h"
#include "../../Tool/Image/TriangleRotator/trianglerotator.h"
#include "../../Tool/Image/Glue/glue.h"
#include "../../Tool/Image/Reflector/reflector.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    auto crop = new Crop();
    auto rotator = new TriangleRotator();
    auto glue = new Glue();
    auto reflect = new Reflector();
    addTool(ellipse);
    addTool(crop);
    addTool(rotator);
    addTool(glue);
    addTool(reflect);
    setTool(ellipse->toString());
}
