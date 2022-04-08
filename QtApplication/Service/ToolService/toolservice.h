#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H


#include "../../Core/StateMachine/context.h"
#include "ToolCategory/toolcategory.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "../../MainWidgets/ToolDock/itooldock.h"

class ToolService : Context<ToolCategory>, QObject {
Q_OBJECT

public:
    static ToolService &getInstance();

    void addCategory(ToolCategory *category);
    ToolCategory *getCategory();
    
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