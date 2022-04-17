#include "toolcategoryview.h"
#include "../../../logger.h"

#include <QLabel>
#include <QToolButton>

ToolCategoryView::ToolCategoryView(const QString &name) : ToolUnitView(name), toolLayout(new QHBoxLayout()),
                                                          toolBox(new QGroupBox(name)) {
    createWidget();
}

ToolCategoryView::ToolCategoryView(const QString &name, const QIcon &icon) : ToolUnitView(name, icon),
                                                                             toolLayout(new QHBoxLayout()),
                                                                             toolBox(new QGroupBox(name)) {
    createWidget();
}

void ToolCategoryView::addToolAction(QAction *action) {
    auto button = new QToolButton();
    button->setDefaultAction(action);
    toolLayout->addWidget(button);
}

void ToolCategoryView::createWidget() {
    toolLayout->setAlignment(Qt::AlignLeft);
    toolBox->setLayout(toolLayout);
    addWidget(toolBox);
}
