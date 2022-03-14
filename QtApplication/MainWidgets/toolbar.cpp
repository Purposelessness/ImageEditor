#include "toolbar.h"
#include "../ToolStateMachine/toolcontext.h"

ToolBar::ToolBar(QWidget *parent) : QToolBar(parent) {
    setMinimumWidth(50);
    setMinimumHeight(50);

    ToolContext::getInstance().setToolBar(this);
}
