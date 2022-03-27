#include "additemcommand.h"
#include "../undoservice.h"

AddItemCommand::AddItemCommand(QGraphicsItem *item) : item(item) {
    UndoService::getInstance().push(this);
}

void AddItemCommand::undo() {
    item->hide();
}

void AddItemCommand::redo() {
    item->show();
}

AddItemCommand::~AddItemCommand() {
    delete item;
}
