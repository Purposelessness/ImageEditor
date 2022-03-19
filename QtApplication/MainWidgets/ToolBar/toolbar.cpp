#include "toolbar.h"
#include "../../ToolService/toolservice.h"

#include <QSizePolicy>

ToolBar::ToolBar(QWidget *parent) : QToolBar(parent) {
    setMinimumWidth(50);
    setMinimumHeight(50);
    bindToToolService();
}

void ToolBar::addAction(QAction *action) {
    auto leftExpander = new QWidget();
    auto rightExpander = new QWidget();
    leftExpander->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    rightExpander->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    addWidget(leftExpander);
    QToolBar::addAction(action);
    addWidget(rightExpander);
}

void ToolBar::bindToToolService() {
    ToolService::getInstance().setToolBar(this);
}
