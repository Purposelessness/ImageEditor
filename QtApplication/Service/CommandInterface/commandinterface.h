#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_COMMANDINTERFACE_H
#define IMAGEEDITOR_COMMANDINTERFACE_H


#include "icommand.h"

#include <QVector>

class CommandInterface {
public:
    static CommandInterface& getInstance();

    void push(ICommand *command);
    ICommand *pop();

private:
    CommandInterface() = default;
    CommandInterface(const CommandInterface& root) = delete;
    CommandInterface& operator=(const CommandInterface&) = delete;

    QVector<ICommand *> commands;
};


#endif //IMAGEEDITOR_COMMANDINTERFACE_H

#pragma clang diagnostic pop