#include "tool.h"

#include <utility>
#include "toolcontext.h"

Tool::Tool(QString name, ToolView *view, ToolCore *core) : name(std::move(name)), view(view), core(core) {
    connect(view->getButton(), SIGNAL(clicked(bool)), this, SLOT(toolClickEvent()));
}

QString Tool::toString() const {
    return name;
}

void Tool::updateView(ToolDock *dock) {
    dock->setWidget(view->getWidget());
}

void Tool::toolClickEvent() const {
    ToolContext::getInstance().setState(toString());
}
