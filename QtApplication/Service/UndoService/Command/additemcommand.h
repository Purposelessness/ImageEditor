#ifndef IMAGEEDITOR_ADDITEMCOMMAND_H
#define IMAGEEDITOR_ADDITEMCOMMAND_H


#include "../../CommandInterface/command.h"

#include <QUndoCommand>
#include <QGraphicsItem>

class AddItemCommand : public QUndoCommand, public Command {
public:
    explicit AddItemCommand(QGraphicsItem *item, const CommandInformation &information);
    ~AddItemCommand() override;

    void undo() override;
    void redo() override;

private:
    QGraphicsItem *item;
};


#endif //IMAGEEDITOR_ADDITEMCOMMAND_H
