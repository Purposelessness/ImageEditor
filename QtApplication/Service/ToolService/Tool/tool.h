#ifndef IMAGEEDITOR_TOOL_H
#define IMAGEEDITOR_TOOL_H

#include "../toolunit.h"
#include "../toolunitview.h"

class Tool : public ToolUnit {
Q_OBJECT

public:
    explicit Tool(QString name, ToolUnitView *view, IToolModel *model);

    QAction *getAction() final;
    QWidget *getWidget() final;
    IToolModel *getModel() final;

private slots:
    void onActionTriggered();

private:
    ToolUnitView *view;
    IToolModel *model;
};


#endif //IMAGEEDITOR_TOOL_H
