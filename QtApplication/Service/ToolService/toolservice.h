#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H


#include "Generics/toolcontext.h"
#include "ToolCategory/itoolcategory.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "../../MainWidgets/ToolDock/itooldock.h"

class ToolService : ToolContext<IToolCategory, ToolUnit> {
Q_OBJECT

public:
    static ToolService &getInstance();

    void addCategory(IToolCategory *category);
    IToolCategory *getCategory();

    void setToolBar(IToolBar *toolBar);
    void setToolDock(IToolDock *toolDock);

public slots:
    void setCategory(const QString &name);

private slots:
    void updateToolDock();

private:
    ToolService();
    ToolService(const ToolService &root) = delete;
    ToolService &operator=(const ToolService &) = delete;

    void addToolToBar(ToolUnit *tool);

    IToolBar *toolBar = nullptr;
    IToolDock *toolDock = nullptr;
};


#endif //IMAGEEDITOR_TOOLSERVICE_H