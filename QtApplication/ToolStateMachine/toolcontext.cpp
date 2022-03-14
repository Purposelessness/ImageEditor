#include "toolcontext.h"
#include "../Logger/logger.h"

ToolContext::ToolContext() {
    setState("Brush");
}

ToolContext &ToolContext::getInstance() {
    static ToolContext instance;
    return instance;
}

void ToolContext::setState(const QString &stateName) {
    if (!tools.contains(stateName)) {
        qCritical(service()) << "Key" << stateName << "doesn't contain in Tools hash";
        return;
    }
    auto tool = tools.find(stateName).value();
    tool->updateView(dock);
}

void ToolContext::addToolBar(ToolBar *toolBar) {
    bar = toolBar;
}

void ToolContext::addToolDock(ToolDock *toolDock) {
    dock = toolDock;
}
