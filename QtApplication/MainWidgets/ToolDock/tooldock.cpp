#include "tooldock.h"
#include "../../ToolService/toolservice.h"

#include <QGuiApplication>

ToolDock::ToolDock(QWidget *parent) : QDockWidget(parent) {
    setMinimumWidth(320);
    setMinimumHeight(600);
    QDockWidget::setWindowTitle(tr("ToolDock"));
    setBackgroundColor(Qt::white);
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

void ToolDock::setBackgroundColor(const QColor& color) {
    QPalette palette(QGuiApplication::palette());
    palette.setColor(QPalette::Window, color);
    setAutoFillBackground(true);
    setPalette(palette);
}
