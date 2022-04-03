#include "toolunitview.h"

#include <QLabel>

ToolUnitView::ToolUnitView(const QString& name, QWidget *widget) : action(new QAction(name)), mainWidget(widget) {
    if (widget) {
        layout = new QVBoxLayout();
        layout->setAlignment(Qt::AlignTop);
        widget->setLayout(layout);
    }
}

ToolUnitView::ToolUnitView(const QString& name, const QIcon &icon, QWidget *widget) : ToolUnitView(name, widget) {
    action->setIcon(icon);
}

QAction *ToolUnitView::getAction() {
    return action;
}

QWidget *ToolUnitView::getWidget() {
    return mainWidget;
}

void ToolUnitView::addWidget(QWidget *widget) {
    layout->addWidget(widget);
}

void ToolUnitView::setWidget(QWidget *widget) {
    if (!stashedWidget)
        stashedWidget = mainWidget;
    mainWidget = widget;
}

void ToolUnitView::resetWidget() {
    if (!stashedWidget) {
        qDebug() << "StashedWidget is null";
        return;
    }
    qDebug() << "StashedWidget is not null";
    mainWidget = stashedWidget;
    stashedWidget = nullptr;
}
