#ifndef IMAGEEDITOR_OTHERTOOLS_H
#define IMAGEEDITOR_OTHERTOOLS_H


#include "../toolcategory.h"
#include "othertoolsview.h"
#include "othertoolsmodel.h"
#include "../../Tool/Figure/figure.h"

class OtherTools : public ToolCategory {
public:
    explicit OtherTools(const QString& name = "OtherTools", OtherToolsView *view = new OtherToolsView(tr("Other Tools")),
                        OtherToolsModel *model = new OtherToolsModel());
};


#endif //IMAGEEDITOR_OTHERTOOLS_H
