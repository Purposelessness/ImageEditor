#ifndef IMAGEEDITOR_TOOLBAR_H
#define IMAGEEDITOR_TOOLBAR_H

#include <QToolBar>

class ToolBar : public QToolBar {
public:
    explicit ToolBar(QWidget *parent = Q_NULLPTR);

private:
    void addTools();
};


#endif //IMAGEEDITOR_TOOLBAR_H
