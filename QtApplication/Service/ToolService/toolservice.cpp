#include "toolservice.h"
#include "ToolCategory/OtherTools/othertools.h"
#include "ToolCategory/FigureCategory/figurecategory.h"

ToolService::ToolService() {
    addCategory(new OtherTools());
    addCategory(new FigureCategory());
    setCategory("OtherTools");
}

ToolService &ToolService::getInstance() {
    static ToolService instance;
    return instance;
}

void ToolService::addCategory(ToolCategory *category) {
    ToolContext::addToolUnit(category);
    QObject::connect(category, SIGNAL(updated()), this, SLOT(updateToolDock()));
    addToolToBar(category);
}

void ToolService::setToolUnit(const QString &name) {
    ToolContext::setToolUnit(name);
    updateToolDock();
}

void ToolService::setCategory(const QString &name) {
    Context::setState(name);
    updateToolDock();
}

ToolCategory *ToolService::getCategory() {
    return getState();
}

void ToolService::setToolBar(IToolBar *newToolBar) {
    toolBar = newToolBar;
    for (auto category: states)
        addToolToBar(category);
    qDebug(toolService()) << "ToolBar linked to ToolService";
}

void ToolService::addToolToBar(ToolUnit *tool) {
    if (toolBar)
        toolBar->addAction(tool->getAction());
}

void ToolService::setToolDock(IToolDock *newToolDock) {
    toolDock = newToolDock;
    qDebug(toolService()) << "ToolDock linked to ToolService";
    updateToolDock();
}

void ToolService::updateToolDock() {
    if (toolDock) {
        toolDock->show();
        toolDock->setWidget(getCategory()->getWidget());
    }
}

Tool *ToolService::getTool() {
    return getCategory()->getTool();
}
