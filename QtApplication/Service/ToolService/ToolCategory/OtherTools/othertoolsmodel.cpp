#include "othertoolsmodel.h"
#include "../../Tool/Editor/EllipseColorInverter/ellipsecolorinverter.h"

void OtherToolsModel::createTools() {
    auto ellipse = new EllipseColorInverter();
    addTool(ellipse);
    setTool(ellipse->toString());
}
