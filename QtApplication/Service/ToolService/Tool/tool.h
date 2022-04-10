#ifndef IMAGEEDITOR_TOOL_H
#define IMAGEEDITOR_TOOL_H

#include "../Generics/toolunit.h"
#include "../Generics/toolunitview.h"

class Tool : public ToolUnit {
Q_OBJECT

public:
    explicit Tool(QString name, ToolUnitView *newView, IToolModel *newModel);

    QAction *getAction() final;
    void mousePressed(const QPoint &mousePos, IGraphicsView *graphicsView = nullptr);
    void mouseMoved(const QPoint &mousePos, IGraphicsView *graphicsView = nullptr);
    void mouseReleased(const QPoint &mousePos, IGraphicsView *graphicsView = nullptr);

private slots:
    void onActionTriggered();

private:
    ToolUnitView *view;
    IToolModel *model;
};


#endif //IMAGEEDITOR_TOOL_H
