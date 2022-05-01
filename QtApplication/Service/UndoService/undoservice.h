#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_UNDOSERVICE_H
#define IMAGEEDITOR_UNDOSERVICE_H


#include <QUndoStack>
#include <QAction>

class UndoService : public QUndoStack {
public:
    static UndoService& getInstance();
    ~UndoService() override;

    QAction *getUndoAction();
    QAction *getRedoAction();

private:
    UndoService();
    UndoService(const UndoService& root) = delete;
    UndoService& operator=(const UndoService&) = delete;

    QAction *undoAction;
    QAction *redoAction;
};


#endif //IMAGEEDITOR_UNDOSERVICE_H