#ifndef IMAGEEDITOR_ITOOLBAR_H
#define IMAGEEDITOR_ITOOLBAR_H

#include <QAction>

class IToolBar {
public:
    virtual void addAction(QAction *action) = 0;
};


#endif //IMAGEEDITOR_ITOOLBAR_H
