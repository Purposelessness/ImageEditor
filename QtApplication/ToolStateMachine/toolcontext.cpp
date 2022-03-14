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
    updateToolDock();
}

void ToolContext::setToolBar(ToolBar *toolBar) {
    bar = toolBar;
    addToolsToBar();
}

void ToolContext::addToolsToBar() {
    for (auto tool : tools.values()) {
        tool->addToolToBar(bar);
    }
    qDebug(ui()) << "ToolBar linked to ToolContext. Tools added to ToolBar";
}

void ToolContext::setToolDock(ToolDock *toolDock) {
    dock = toolDock;
    qDebug(ui()) << "ToolDock linked to ToolContext";
    updateToolDock();
}

void ToolContext::updateToolDock() {
    if (!dock)
        return;
    currentTool->updateToolDock(dock);
    qDebug(ui()) << "ToolDock content updated";
}
