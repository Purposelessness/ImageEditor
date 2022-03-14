#include "tool.h"

#include <utility>
#include "toolcontext.h"

Tool::Tool(QString name, ToolView *view, ToolCore *core) : name(std::move(name)), view(view), core(core) {
    connect(view->getAction(), SIGNAL(triggered(bool)), this, SLOT(toolClickEvent()));
}

QString Tool::toString() const {
    return name;
}

void Tool::addToolToBar(ToolBar *bar) {
    bar->addAction(view->getAction());
}

void Tool::updateToolDock(ToolDock *dock) {
    dock->setToolWidget(view->getWidget());
}

void Tool::toolClickEvent() const {
    ToolContext::getInstance().setTool(toString());
}
