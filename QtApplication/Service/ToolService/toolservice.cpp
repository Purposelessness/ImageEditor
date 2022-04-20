#include "toolservice.h"
#include "../../Data/data.h"
#include "../../MainWidgets/ToolDock/itooldock.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "ToolCategory/ImageTools/imagetools.h"
#include "ToolCategory/FigureCategory/figurecategory.h"

ToolService::ToolService() {
    auto widgetData = &WidgetData::getInstance();
    connect(widgetData, SIGNAL(toolDockUpdated()), this, SLOT(updateToolDock()));
    connect(widgetData, SIGNAL(toolBarUpdated()), this, SLOT(updateToolBar()));

    addCategory(new ImageTools());
    addCategory(new FigureCategory());
    setCategory("ImageTools");
}

ToolService &ToolService::getInstance() {
    static ToolService instance;
    return instance;
}

void ToolService::addCategory(ToolCategory *category) {
    ToolContext::addToolUnit(category);
    QObject::connect(category, SIGNAL(updated()), this, SLOT(updateToolDock()));
    updateToolBar(category);
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

void ToolService::updateToolBar(ToolUnit *unit) {
    auto toolBar = WidgetData::getInstance().getToolBar();
    if (!toolBar)
        return;

    if (unit) {
        toolBar->addAction(unit->getAction());
        return;
    }
    for (auto category: states) {
        toolBar->addAction(category->getAction());
    }
}

void ToolService::updateToolDock() {
    auto toolDock = WidgetData::getInstance().getToolDock();
    if (!toolDock)
        return;
    toolDock->show();
    toolDock->setWidget(getCategory()->getWidget());
}

Tool *ToolService::getTool() {
    return getCategory()->getTool();
}
