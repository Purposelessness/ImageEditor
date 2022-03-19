#ifndef IMAGEEDITOR_TOOLCATEGORY_H
#define IMAGEEDITOR_TOOLCATEGORY_H

#include "../toolunit.h"
#include "../toolunitview.h"
#include "toolcategoryview.h"
#include "toolcategorymodel.h"

class ToolCategory : public ToolUnit {
Q_OBJECT

public:
    explicit ToolCategory(QString name, ToolCategoryView *view, ToolCategoryModel *model);

    QAction *getAction() final;
    QWidget *getWidget() final;
    IToolModel *getToolModel() final;

private slots:
    void onToolAdded(QAction *action);
    void onActionTriggered();
    void onToolChanged();
    void onToolWidgetEnabled(bool value);

private:
    void connectSignals();
    ToolCategoryView *view;
    ToolCategoryModel *model;
    bool toolWidgetState = false;
};


#endif //IMAGEEDITOR_TOOLCATEGORY_H
