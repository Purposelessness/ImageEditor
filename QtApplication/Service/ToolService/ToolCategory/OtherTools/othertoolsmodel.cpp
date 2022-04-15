#include "othertoolsmodel.h"
#include "../../Tool/Figure/Ellipse/ellipse.h"

void OtherToolsModel::createTools() {
    auto ellipse = new Ellipse();
    addTool(ellipse);
    setTool(ellipse->toString());
}
