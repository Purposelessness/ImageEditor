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
    static ToolContext &getInstance();
    void setState(const QString &name);
    void addToolBar(ToolBar *toolBar);
    void addToolDock(ToolDock *toolDock);

private:
    ToolContext();
    ToolContext(const ToolContext &root) = delete;
    ToolContext &operator=(const ToolContext &) = delete;

    QHash<QString, Tool *> tools;
    ToolBar *bar;
    ToolDock *dock;
};


#endif //IMAGEEDITOR_SETTINGSCONTEXT_H