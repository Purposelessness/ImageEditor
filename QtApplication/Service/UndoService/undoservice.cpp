#include "undoservice.h"

UndoService::UndoService() : undoAction(createUndoAction(this)), redoAction(createRedoAction(this)) {}

UndoService &UndoService::getInstance() {
    static UndoService instance;
    return instance;
}

QAction *UndoService::getUndoAction() {
    return undoAction;
}

QAction *UndoService::getRedoAction() {
    return redoAction;
}
