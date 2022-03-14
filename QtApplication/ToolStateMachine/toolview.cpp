#include "toolview.h"

ToolView::ToolView(const QString &name) : button(new QPushButton(name)), widget(new QWidget()),
                                          label(new QLabel(name, widget)) {
    button->hide();
    widget->hide();
}

QPushButton *ToolView::getButton() {
    return button;
}

QWidget *ToolView::getWidget() {
    return widget;
}
