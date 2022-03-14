#ifndef IMAGEEDITOR_TOOLVIEW_H
#define IMAGEEDITOR_TOOLVIEW_H

#include <QPushButton>
#include <QWidget>
#include <QLabel>

class ToolView {
public:
    explicit ToolView(const QString &name);

    virtual QPushButton *getButton();
    virtual QWidget *getWidget();

private:
    QPushButton *button;

    QWidget *widget;
    QLabel *label;
};


#endif //IMAGEEDITOR_TOOLVIEW_H
