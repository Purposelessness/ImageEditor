#include "figure.h"

#include <utility>

Figure::Figure(QString name, ToolUnitView *view, IToolModel *model) : Tool(std::move(name), view, model) {}

void Figure::onMousePressed(const QPoint &mousePos, IGraphicsView *graphicsView) {
    emit update(this);
    Tool::onMousePressed(mousePos, graphicsView);
}
