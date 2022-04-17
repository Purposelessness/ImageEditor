#ifndef IMAGEEDITOR_OTHERTOOLSMODEL_H
#define IMAGEEDITOR_OTHERTOOLSMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class OtherToolsModel : public ToolCategoryModel<Tool> {
public:
    OtherToolsModel() = default;
    void createTools() override;
};


#endif //IMAGEEDITOR_OTHERTOOLSMODEL_H
