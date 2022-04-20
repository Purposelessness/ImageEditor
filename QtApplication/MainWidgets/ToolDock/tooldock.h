#ifndef IMAGEEDITOR_TOOLDOCK_H
#define IMAGEEDITOR_TOOLDOCK_H


#include "itooldock.h"

#include <QDockWidget>

class ToolDock : public QDockWidget, IToolDock {
public:
    explicit ToolDock(QWidget *parent = nullptr);

    void setWidget(QWidget *widget) override;
    void setWindowTitle(const QString &title) override;
    void show() override;
};


#endif //IMAGEEDITOR_TOOLDOCK_H
