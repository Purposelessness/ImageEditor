#ifndef IMAGEEDITOR_TOOLCATEGORYMODEL_H
#define IMAGEEDITOR_TOOLCATEGORYMODEL_H


#include "itoolcategorymodel.h"
#include "../Generics/toolcontext.h"
#include "../Tool/tool.h"

template<typename T, typename F>
class ToolCategoryModel : protected ToolContext<T, F>, public IToolCategoryModel {};

template<typename T>
class ToolCategoryModel<T, Tool> : protected ToolContext<T, ToolUnit>, public IToolCategoryModel {
Q_OBJECT

public:
    void createTools() override = 0;

    void addTool(Tool *tool);
    void setTool(const QString &name);

    T *getTool() override;
};


#endif //IMAGEEDITOR_TOOLCATEGORYMODEL_H
