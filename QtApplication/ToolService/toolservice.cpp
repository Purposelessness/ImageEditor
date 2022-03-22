#include "toolservice.h"
#include "../logger.h"
#include "ToolCategory/BrushCategory/brushcategory.h"
#include "ToolCategory/ShapeCategory/shapecategory.h"

ToolService::ToolService() : bar(Q_NULLPTR), dock(Q_NULLPTR) {
    createTools();
}

void ToolService::createTools() {
    addTool(new BrushCategory());
    addTool(new ShapeCategory());
    setTool("BrushCategory");
}

ToolService &ToolService::getInstance() {
    static ToolService instance;
    return instance;
}

void ToolService::addTool(ToolUnit *tool) {
    ToolContext::addTool(tool);
    if (bar)
        addToolToBar(tool);
}

void ToolService::setTool(const QString &name) {
    ToolContext::setTool(name);
    updateToolDock();
}

void ToolService::setToolBar(IToolBar *toolBar) {
    bar = toolBar;
    for (auto tool : tools)
        addToolToBar(tool);
    qDebug(toolService()) << "ToolBar linked to ToolService";
}

void ToolService::addToolToBar(ToolUnit *tool) {
    bar->addAction(tool->getAction());
}

void ToolService::setToolDock(IToolDock *toolDock) {
    dock = toolDock;
    qDebug(toolService()) << "ToolDock linked to ToolService";
    updateToolDock();
}

void ToolService::updateToolDock() {
    if (!dock)
        return;
    dock->setWidget(getCurrentTool()->getWidget());
}

void ToolService::onToolChanged() {
    updateToolDock();
}

void ToolService::onToolWidgetEnabled(bool value) {
    updateToolDock();
}
