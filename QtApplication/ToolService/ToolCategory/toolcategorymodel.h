#ifndef IMAGEEDITOR_TOOLCATEGORYMODEL_H
#define IMAGEEDITOR_TOOLCATEGORYMODEL_H

#include "../toolcontext.h"
#include "../Tool/tool.h"

class ToolCategoryModel : public ToolContext {
Q_OBJECT

public:
    QWidget *getCurrentToolWidget();
    virtual void createTools() = 0;

signals:
    void toolAdded(QAction *action);
    void toolChanged();
    void toolWidgetEnabled(bool value);

protected:
    void addTool(Tool *tool);

protected slots:
    void onToolTriggered(const QString &name) final;
    void onToolChanged() override {}
    void onToolWidgetEnabled(bool value) final;

private:
    QWidget *currentToolWidget;
};


#endif //IMAGEEDITOR_TOOLCATEGORYMODEL_H
