#ifndef IMAGEEDITOR_ADDITEMCOMMAND_H
#define IMAGEEDITOR_ADDITEMCOMMAND_H


#include <QUndoCommand>
#include <QGraphicsItem>

class AddItemCommand : QUndoCommand {
public:
    explicit AddItemCommand(QGraphicsItem *item);
    ~AddItemCommand() override;

    void undo() override;
    void redo() override;

private:
    QGraphicsItem *item;
};


#endif //IMAGEEDITOR_ADDITEMCOMMAND_H
