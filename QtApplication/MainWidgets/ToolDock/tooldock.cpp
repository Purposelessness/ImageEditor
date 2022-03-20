#include "tooldock.h"
#include "../../ToolService/toolservice.h"

ToolDock::ToolDock(QWidget *parent) : QDockWidget(parent) {
    setMinimumWidth(320);
    setMinimumHeight(600);
    QDockWidget::setWindowTitle(tr("ToolDock"));
    setAllowedAreas(Qt::RightDockWidgetArea | Qt::LeftDockWidgetArea);

    ToolService::getInstance().setToolDock(this);
}

void ToolDock::setWidget(QWidget *widget) {
    QDockWidget::setWidget(widget);
    widget->show();
}

void ToolDock::setWindowTitle(const QString& title) {
    QWidget::setWindowTitle(title);
}
