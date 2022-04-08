#include "toolservice.h"
#include "../../logger.h"
#include "ToolCategory/BrushCategory/brushcategory.h"
#include "ToolCategory/FigureCategory/figurecategory.h"

ToolService::ToolService() {
    addCategory(new BrushCategory());
    addCategory(new FigureCategory());
    setCategory("BrushCategory");
}

ToolService &ToolService::getInstance() {
    static ToolService instance;
    return instance;
}

void ToolService::addCategory(ToolCategory *category) {
    Context::addState(category->toString(), category);
    connect(category, SIGNAL(triggered(QString)), this, SLOT(setCategory(QString)));
    connect(category, SIGNAL(updateView()), this, SLOT(updateToolDock()));
    addToolToBar(category);
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
