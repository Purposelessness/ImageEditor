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
    QWidget *getWidget() override;
    IToolModel *getModel() final;
    QWidget *getAlternativeWidget() override;

private slots:
    void onToolAdded(QAction *action);
    void onActionTriggered();

private:
    ToolCategoryView *view;
    ToolCategoryModel *model;
};


#endif //IMAGEEDITOR_TOOLCATEGORY_H
