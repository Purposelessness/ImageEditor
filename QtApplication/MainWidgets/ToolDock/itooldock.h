#ifndef IMAGEEDITOR_ITOOLDOCK_H
#define IMAGEEDITOR_ITOOLDOCK_H

#include <QWidget>

class IToolDock {
public:
    virtual void setWidget(QWidget *widget) = 0;
};


#endif //IMAGEEDITOR_ITOOLDOCK_H
