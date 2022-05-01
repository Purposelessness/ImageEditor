#include "focusoncommand.h"
#include "../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../undoservice.h"

FocusOnCommand::FocusOnCommand(IGraphicsView *view, QGraphicsItem *currentItem, QGraphicsItem *previousItem) :
                view(view), currentItem(currentItem), previousItem(previousItem) {
    UndoService::getInstance().push(this);
}

FocusOnCommand::~FocusOnCommand() {
    delete currentItem;
}

void FocusOnCommand::undo() {
    view->focusOn(previousItem);
    QUndoCommand::undo();
}

void FocusOnCommand::redo() {
    view->focusOn(currentItem);
    QUndoCommand::redo();
}
