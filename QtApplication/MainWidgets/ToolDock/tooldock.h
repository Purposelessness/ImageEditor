#ifndef IMAGEEDITOR_TOOLDOCK_H
#define IMAGEEDITOR_TOOLDOCK_H

#include <QDockWidget>

#include "itooldock.h"

class ToolDock : public QDockWidget, IToolDock {
public:
    explicit ToolDock(QWidget *parent = nullptr);

    void setWidget(QWidget *widget) override;
    void setWindowTitle(const QString &title) override;
};


#endif //IMAGEEDITOR_TOOLDOCK_H
