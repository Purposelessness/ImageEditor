#ifndef IMAGEEDITOR_TOOLCATEGORYMODEL_H
#define IMAGEEDITOR_TOOLCATEGORYMODEL_H


#include "itoolcategorymodel.h"
#include "../Generics/toolcontext.h"
#include "../Tool/tool.h"

template<typename T>
class ToolCategoryModel : protected ToolContext<T>, public IToolCategoryModel {
public:
    ToolCategoryModel();

    void createTools() override = 0;

    virtual void addTool(T *tool);
    void setTool(const QString &name);

    T *getTool() override;
};

#include "toolcategorymodel.inl"


#endif //IMAGEEDITOR_TOOLCATEGORYMODEL_H
