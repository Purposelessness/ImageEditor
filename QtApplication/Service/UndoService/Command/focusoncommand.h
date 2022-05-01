#ifndef IMAGEEDITOR_FOCUSONCOMMAND_H
#define IMAGEEDITOR_FOCUSONCOMMAND_H


#include <QUndoCommand>
#include <QGraphicsItem>

class IGraphicsView;

class FocusOnCommand : public QUndoCommand {
public:
    explicit FocusOnCommand(IGraphicsView *view, QGraphicsItem *currentItem, QGraphicsItem *previousItem);
    ~FocusOnCommand() override;

    void undo() override;
    void redo() override;

private:
    IGraphicsView *view;
    QGraphicsItem *currentItem;
    QGraphicsItem *previousItem;
};


#endif //IMAGEEDITOR_FOCUSONCOMMAND_H
