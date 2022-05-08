#include "focusoncommand.h"
#include "../../../MainWidgets/ImageViewer/igraphicsview.h"
#include "../undoservice.h"

FocusOnCommand::FocusOnCommand(IGraphicsView *view, QGraphicsItem *currentItem, QGraphicsItem *previousItem,
                               const CommandInformation &information) : Command(information),
                view(view), currentItem(currentItem), previousItem(previousItem) {
    UndoService::getInstance().push(this);
}

FocusOnCommand::~FocusOnCommand() {
    delete currentItem;
}

void FocusOnCommand::undo() {
    pop();
    view->focusOn(previousItem);
    QUndoCommand::undo();
}

void FocusOnCommand::redo() {
    push();
    view->focusOn(currentItem);
    QUndoCommand::redo();
}
