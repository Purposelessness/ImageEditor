#include "painter.h"
#include "../ToolService/toolservice.h"
#include "../UndoService/Command/additemcommand.h"
#include "../ToolService/Tool/itoolmodel.h"

Painter::Painter(IGraphicsView *graphicsView) : view(graphicsView) {}

void Painter::onMousePressed(const QPoint& mousePos) {
    ToolService::getInstance().getCurrentToolModel()->mousePressed(mousePos, view);
}

void Painter::onMouseMoved(const QPoint& mousePos) {
    ToolService::getInstance().getCurrentToolModel()->mouseMoved(mousePos, view);
}

void Painter::onMouseReleased(const QPoint& mousePos) {
    ToolService::getInstance().getCurrentToolModel()->mouseReleased(mousePos, view);
}
