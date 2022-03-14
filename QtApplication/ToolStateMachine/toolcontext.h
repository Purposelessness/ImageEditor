#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_SETTINGSCONTEXT_H
#define IMAGEEDITOR_SETTINGSCONTEXT_H

#include "tool.h"
#include "../MainWidgets/toolbar.h"
#include "../MainWidgets/tooldock.h"

#include <QString>
#include "QHash"

class ToolContext : QObject {
Q_OBJECT

public:
    static ToolContext& getInstance();
    void addTool(Tool *tool);
    void setTool(const QString& toolType);
    void setToolBar(ToolBar *toolBar);
    void setToolDock(ToolDock *toolDock);

private:
    ToolContext();
    ToolContext(const ToolContext& root) = delete;
    ToolContext &operator=(const ToolContext&) = delete;

    void createTools();
    void addToolsToBar();
    void updateToolDock();

    QHash<QString, Tool *> tools;
    Tool *currentTool;
    QString currentToolString;
    ToolBar *bar;
    ToolDock *dock;
};


#endif //IMAGEEDITOR_SETTINGSCONTEXT_H