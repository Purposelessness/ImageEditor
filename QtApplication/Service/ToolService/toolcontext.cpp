#include "toolcontext.h"
#include "../../logger.h"

void ToolContext::setTool(const QString& name) {
    if (!tools.contains(name)) {
        qCritical(toolService()) << "Tool" << name << "doesn't contain in tools hash";
        return;
    }
    qInfo(toolService()) << "Selected" << name << "tool";
    currentTool = tools.value(name);
}

void ToolContext::addTool(ToolUnit *toolUnit) {
    QString name = toolUnit->toString();
    if (tools.contains(name))
        qInfo(toolService()) << "Tool hash already contains" << name << ". Previous toolUnit was replaced";
    tools.insert(toolUnit->toString(), toolUnit);
    connect(toolUnit, SIGNAL(triggered(QString)), this, SLOT(onToolTriggered(QString)));
    qDebug(toolService()) << "Tool" << name << "added to hash";
}

ToolUnit *ToolContext::getCurrentTool() {
    return currentTool;
}

IToolModel *ToolContext::getCurrentToolModel() {
    return currentTool->getModel();
}

void ToolContext::onToolTriggered(const QString& name) {
    qDebug(toolService()) << "Tool triggered" << name;
    setTool(name);
}
