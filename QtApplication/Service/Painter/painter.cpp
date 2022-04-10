#include "painter.h"
#include "../ToolService/toolservice.h"
#include "../UndoService/Command/additemcommand.h"
#include "../ToolService/Tool/tool.h"

Painter::Painter(IGraphicsView *graphicsView) : view(graphicsView) {}

void Painter::onMousePressed(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->onMousePressed(mousePos, view);
}

void Painter::onMouseMoved(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->onMouseMoved(mousePos);
}

void Painter::onMouseReleased(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->onMouseReleased(mousePos);
}
