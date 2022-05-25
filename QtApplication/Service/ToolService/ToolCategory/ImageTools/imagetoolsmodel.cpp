#include "imagetoolsmodel.h"
#include "../../Tool/Image/EllipseColorInverter/ellipsecolorinverter.h"
#include "../../Tool/Image/Crop/crop.h"
#include "../../Tool/Image/TriangleRotator/trianglerotator.h"
#include "../../Tool/Image/Outliner/outliner.h"

void ImageToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    auto crop = new Crop();
    auto rotator = new TriangleRotator();
    auto outliner = new Outliner();
    addTool(ellipse);
    addTool(crop);
    addTool(rotator);
    addTool(outliner);
    setTool(ellipse->toString());
}
