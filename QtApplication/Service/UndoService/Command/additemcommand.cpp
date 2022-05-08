#include "additemcommand.h"
#include "../undoservice.h"

AddItemCommand::AddItemCommand(QGraphicsItem *item, const CommandInformation &info) : Command(info), item(item) {
    UndoService::getInstance().push(this);
}

void AddItemCommand::undo() {
    pop();
    item->hide();
    QUndoCommand::undo();
}

void AddItemCommand::redo() {
    push();
    item->show();
    QUndoCommand::redo();
}

AddItemCommand::~AddItemCommand() {
    delete item;
}
