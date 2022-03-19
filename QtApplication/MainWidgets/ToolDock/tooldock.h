#ifndef IMAGEEDITOR_TOOLDOCK_H
#define IMAGEEDITOR_TOOLDOCK_H

#include <QDockWidget>
#include <QCloseEvent>

#include "itooldock.h"

class ToolDock : public QDockWidget, IToolDock {
public:
    explicit ToolDock(QWidget *parent = Q_NULLPTR);

    void setWidget(QWidget *widget) override;

private:
    void setBackgroundColor(const QColor &color);
};


#endif //IMAGEEDITOR_TOOLDOCK_H
