#include "commandinterface.h"

CommandInterface &CommandInterface::getInstance() {
    static CommandInterface instance;
    return instance;
}

void CommandInterface::push(ICommand *command) {
    stack.push(command);
}

ICommand *CommandInterface::pop() {
    return stack.pop();
}

qsizetype CommandInterface::size() const {
    return stack.size();
}

ICommand *CommandInterface::at(qsizetype i) {
    return stack.at(i);
}
