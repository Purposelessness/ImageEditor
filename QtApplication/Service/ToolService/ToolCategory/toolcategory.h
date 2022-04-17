#ifndef IMAGEEDITOR_TOOLCATEGORY_H
#define IMAGEEDITOR_TOOLCATEGORY_H


#include "../Generics/toolunit.h"
#include "toolcategoryview.h"
#include "itoolcategorymodel.h"

class ToolCategory : public ToolUnit {
Q_OBJECT

public:
    explicit ToolCategory(const QString &name, IToolCategoryModel *model);

    QAction *getAction() override;
    QWidget *getWidget();

    Tool *getTool();

signals:
    void updated();

protected slots:
    virtual void onToolAdded(QAction *action);
    virtual void onActionTriggered();

protected:
    ToolCategoryView *view;

private:
    IToolCategoryModel *model;
};


#endif //IMAGEEDITOR_TOOLCATEGORY_H
