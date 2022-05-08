#include "commandinterface.h"

CommandInterface &CommandInterface::getInstance() {
    static CommandInterface instance;
    return instance;
}

void CommandInterface::push(ICommand *command) {
    commands.push_back(command);
}

ICommand *CommandInterface::pop() {
    auto t = commands.back();
    commands.pop_back();
    return t;
}

//qsizetype CommandInterface::size() const {
//    return commands.size();
//}
//
//ICommand *CommandInterface::at(qsizetype i) {
//    return commands.at(i);
//}
