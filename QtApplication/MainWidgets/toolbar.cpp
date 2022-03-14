#include "toolbar.h"
#include "../ToolStateMachine/toolcontext.h"

#include <QSizePolicy>

ToolBar::ToolBar(QWidget *parent) : QToolBar(parent) {
    setMinimumWidth(50);
    setMinimumHeight(50);

    addTools();
}

void ToolBar::addTools() {
    auto leftExpander = new QWidget();
    auto rightExpander = new QWidget();
    leftExpander->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightExpander->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    addWidget(leftExpander);
    ToolContext::getInstance().setToolBar(this);
    addWidget(rightExpander);
}

