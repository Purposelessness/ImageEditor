#ifndef IMAGEEDITOR_TOOLDOCK_H
#define IMAGEEDITOR_TOOLDOCK_H

#include <QDockWidget>
#include <QCloseEvent>

class ToolDock : public QDockWidget {
public:
    explicit ToolDock(QWidget *parent = Q_NULLPTR);

    void setToolWidget(QWidget *widget);

private:
    void setBackgroundColor(const QColor &color);
};


#endif //IMAGEEDITOR_TOOLDOCK_H
