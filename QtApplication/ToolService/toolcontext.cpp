#include "toolcontext.h"
#include "../Logger/logger.h"

void ToolContext::setTool(const QString &name) {
    if (!tools.contains(name)) {
        qCritical(toolService()) << "Tool" << name << "doesn't contain in tools hash";
        return;
    }
    qInfo(toolService()) << "Selected" << name << "tool";
    currentTool = tools.value(name);
    updateToolModel();
}

void ToolContext::addTool(ToolUnit *toolUnit) {
    QString name = toolUnit->toString();
    if (tools.contains(name))
        qInfo(toolService()) << "Tool hash already contains" << name << ". Previous toolUnit was replaced";
    tools.insert(toolUnit->toString(), toolUnit);
    connect(toolUnit, SIGNAL(toolTriggered(QString)), this, SLOT(onToolTriggered(QString)));
    connect(toolUnit, SIGNAL(toolChanged()), this, SLOT(onToolChanged()));
    connect(toolUnit, SIGNAL(toolWidgetEnabled(bool)), this, SLOT(onToolWidgetEnabled(bool)));
    qDebug(toolService()) << "Tool" << name << "added to hash";
}

ToolUnit *ToolContext::getCurrentTool() {
    return currentTool;
}

IToolModel *ToolContext::getCurrentToolModel() {
    return currentToolModel;
}

void ToolContext::onToolTriggered(const QString &name) {
    qDebug(toolService()) << "Tool triggered" << name;
    setTool(name);
}

void ToolContext::updateToolModel() {
    currentToolModel = currentTool->getToolModel();
}
