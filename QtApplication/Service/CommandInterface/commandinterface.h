#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_COMMANDINTERFACE_H
#define IMAGEEDITOR_COMMANDINTERFACE_H


#include "icommand.h"

#include <QStack>

class CommandInterface {
public:
    static CommandInterface& getInstance();

    void push(ICommand *command);
    ICommand *pop();
    [[nodiscard]] qsizetype size() const;
    ICommand *at(qsizetype i);

private:
    CommandInterface() = default;
    CommandInterface(const CommandInterface& root) = delete;
    CommandInterface& operator=(const CommandInterface&) = delete;

    QStack<ICommand *> stack;
};


#endif //IMAGEEDITOR_COMMANDINTERFACE_H

#pragma clang diagnostic pop