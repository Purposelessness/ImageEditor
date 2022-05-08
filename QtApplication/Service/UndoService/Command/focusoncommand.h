#ifndef IMAGEEDITOR_FOCUSONCOMMAND_H
#define IMAGEEDITOR_FOCUSONCOMMAND_H


#include "../../CommandInterface/command.h"

#include <QUndoCommand>
#include <QGraphicsItem>

class IGraphicsView;

class FocusOnCommand : public QUndoCommand, public Command {
public:
    explicit FocusOnCommand(IGraphicsView *view, QGraphicsItem *currentItem, QGraphicsItem *previousItem,
                            const CommandInformation &information);
    ~FocusOnCommand() override;

    void undo() override;
    void redo() override;

private:
    IGraphicsView *view;
    QGraphicsItem *currentItem;
    QGraphicsItem *previousItem;
};


#endif //IMAGEEDITOR_FOCUSONCOMMAND_H
