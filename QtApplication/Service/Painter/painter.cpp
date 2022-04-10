#include "painter.h"
#include "../ToolService/toolservice.h"
#include "../UndoService/Command/additemcommand.h"
#include "../ToolService/Tool/tool.h"

Painter::Painter(IGraphicsView *graphicsView) : view(graphicsView) {}

void Painter::onMousePressed(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->mousePressed(mousePos, view);
}

void Painter::onMouseMoved(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->mouseMoved(mousePos, view);
}

void Painter::onMouseReleased(const QPoint& mousePos) {
    ToolService::getInstance().getTool()->mouseReleased(mousePos, view);
}
