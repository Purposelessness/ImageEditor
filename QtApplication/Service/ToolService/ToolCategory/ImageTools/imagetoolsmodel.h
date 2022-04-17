#ifndef IMAGEEDITOR_IMAGETOOLSMODEL_H
#define IMAGEEDITOR_IMAGETOOLSMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class ImageToolsModel : public ToolCategoryModel<Tool> {
public:
    void createTools() override;
};


#endif //IMAGEEDITOR_IMAGETOOLSMODEL_H
