#include "toolcategoryview.h"
#include "../../Logger/logger.h"

#include <QLabel>
#include <QGuiApplication>
#include <QToolButton>

ToolCategoryView::ToolCategoryView(const QString& name) : ToolUnitView(name) {
    makeWidget(name);
}

ToolCategoryView::ToolCategoryView(const QString& name, const QIcon& icon) : ToolUnitView(name, icon) {
    makeWidget(name);
}

void ToolCategoryView::addAction(QAction *action) {
    auto button = new QToolButton();
    button->setDefaultAction(action);
    toolLayout->addWidget(button);
}

void ToolCategoryView::makeWidget(const QString& name) {
    toolLayout = new QHBoxLayout();
    toolLayout->setAlignment(Qt::AlignLeft);
    toolBox = new QGroupBox(name);
    toolBox->setLayout(toolLayout);
    addWidget(toolBox);
}
