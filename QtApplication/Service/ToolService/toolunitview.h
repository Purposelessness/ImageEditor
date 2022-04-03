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
    void setWidget(QWidget *widget);
    void resetWidget();

private:
    QWidget *mainWidget = nullptr;
    QWidget *stashedWidget = nullptr;
    QAction *action;
    QVBoxLayout *layout;
};


#endif //IMAGEEDITOR_TOOLUNITVIEW_H
