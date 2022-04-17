#ifndef IMAGEEDITOR_TOOL_H
#define IMAGEEDITOR_TOOL_H


#include "../Generics/toolunit.h"
#include "../Generics/toolunitview.h"

class Tool : public ToolUnit {
Q_OBJECT

public:
    explicit Tool(const QString &name, ToolModel *newModel);

    QAction *getAction() final;
    virtual void onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView);
    virtual void onMouseMoved(const QPoint &mousePos);
    virtual void onMouseReleased(const QPoint &mousePos);

private slots:
    void onActionTriggered();

private:
    ToolUnitView *view;
    ToolModel *model;
};


#endif //IMAGEEDITOR_TOOL_H
