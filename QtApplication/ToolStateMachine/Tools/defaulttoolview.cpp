#include "defaulttoolview.h"

DefaultToolView::DefaultToolView(const QString &name) : ToolView(name) {
    auto widget = new QWidget();
    widget->setMinimumSize(200, 100);
    addSection(widget);
}

DefaultToolView::DefaultToolView(const QPixmap &pixmap, const QString &name) : ToolView(pixmap, name) {
}
