#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H

#include "toolcontext.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "../../MainWidgets/ToolDock/itooldock.h"

#include <QString>
#include "QHash"

class ToolService : ToolContext {
Q_OBJECT

public:
    static ToolService& getInstance();
    void setTool(const QString& name) final;
    void addTool(ToolUnit *tool) final;
    void setToolBar(IToolBar *toolBar);
    void setToolDock(IToolDock *toolDock);

protected slots:
    void onToolChanged() final;
    void onToolWidgetEnabled(bool value) final;

private:
    ToolService();
    ToolService(const ToolService& root) = delete;
    ToolService& operator=(const ToolService&) = delete;

    void createTools();
    void addToolToBar(ToolUnit *tool);
    void updateToolDock();

    IToolBar *bar;
    IToolDock *dock;
};


#endif //IMAGEEDITOR_TOOLSERVICE_H