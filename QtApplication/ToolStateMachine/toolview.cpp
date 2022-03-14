#include "toolview.h"

#include <QIcon>

ToolView::ToolView(const QString& name) : action(new QAction(name)), settingsBox(new QGroupBox(name)),
                                          layout(new QVBoxLayout()) {
    settingsBox->setLayout(layout);
    settingsBox->hide();
}

ToolView::ToolView(const QPixmap& pixmap, const QString& name) : ToolView(name) {
    setActionIcon(pixmap);
}

void ToolView::setActionIcon(const QPixmap& pixmap) {
    action->setIcon(QIcon(pixmap));
}

QAction *ToolView::getAction() {
    return action;
}

QWidget *ToolView::getWidget() {
    return settingsBox;
}

void ToolView::addSection(QWidget *section) {
    layout->addWidget(section);
}

void ToolView::addSection(const QString &sectionLabel, QWidget *section) {
    auto *newSection = new QWidget();
    auto *newLayout = new QVBoxLayout();
    newLayout->addWidget(new QLabel(sectionLabel));
    newLayout->addWidget(section);
    newSection->setLayout(newLayout);
    addSection(newSection);
}
