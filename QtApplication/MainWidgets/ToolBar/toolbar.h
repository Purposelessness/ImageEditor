#ifndef IMAGEEDITOR_TOOLBAR_H
#define IMAGEEDITOR_TOOLBAR_H

#include "itoolbar.h"

#include <QToolBar>

class ToolBar : public QToolBar, IToolBar {
public:
    explicit ToolBar(QWidget *parent = Q_NULLPTR);

    void addAction(QAction *action) override;

private:
    void bindToToolService();
// TODO: unbind tool bar from service
    void unbindFromToolService();
};


#endif //IMAGEEDITOR_TOOLBAR_H
