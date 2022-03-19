#ifndef IMAGEEDITOR_TOOLUNITVIEW_H
#define IMAGEEDITOR_TOOLUNITVIEW_H

#include <QAction>
#include <QWidget>
#include <QVBoxLayout>

class ToolUnitView {
public:
    explicit ToolUnitView(const QString& name, QWidget *widget = new QWidget());
    explicit ToolUnitView(const QString& name, const QIcon& icon, QWidget *widget = new QWidget());

    QAction *getAction();
    QWidget *getWidget();
    void addWidget(QWidget *widget);

private:
    QWidget *mainWidget;
    QAction *action;
    QVBoxLayout *layout;
};


#endif //IMAGEEDITOR_TOOLUNITVIEW_H
