#ifndef IMAGEEDITOR_TOOLCATEGORYMODEL_H
#define IMAGEEDITOR_TOOLCATEGORYMODEL_H

#include "../toolcontext.h"
#include "../Tool/tool.h"

class ToolCategoryModel : public ToolContext {
Q_OBJECT

public:
    virtual void createTools() = 0;
    virtual void addTool(Tool *tool);

signals:
    void toolAdded(QAction *action);
};


#endif //IMAGEEDITOR_TOOLCATEGORYMODEL_H
