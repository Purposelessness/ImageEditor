#include "toolcontext.h"
#include "Tools/Brushes/brush.h"
#include "Tools/Frames/frame.h"

ToolContext::ToolContext() {
    qDebug(service()) << "Tool state machine initialized";
    createTools();
    setTool("Brush");
}

void ToolContext::createTools() {
    addTool(new Brush());
    addTool(new Frame());
}

ToolContext &ToolContext::getInstance() {
    static ToolContext instance;
    return instance;
}

void ToolContext::addTool(Tool *tool) {
    tools.insert(tool->toString(), tool);
}

void ToolContext::setTool(const QString &toolType) {
    if (toolType == currentToolString)
        return;
    if (!tools.contains(toolType)) {
        qCritical(service()) << "Key" << toolType << "doesn't contain in Tools hash";
        return;
    }
    qInfo(service()) << "Tool type changed to" << toolType;
    currentTool = tools.value(toolType);
    currentToolString = toolType;
    if (dock)
        currentTool->updateToolDock(dock);
}

void ToolContext::setToolBar(ToolBar *toolBar) {
    bar = toolBar;
    addToolsToBar();
}

void ToolContext::addToolsToBar() {
    for (auto tool : tools.values()) {
        tool->addToolToBar(bar);
    }
}

void ToolContext::setToolDock(ToolDock *toolDock) {
    dock = toolDock;
    currentTool->updateToolDock(dock);
}
