#include "command.h"

Command::Command(const CommandInformation &information) : info(information) {}

void Command::push() {
    CommandInterface::getInstance().push(this);
}

void Command::pop() {
    CommandInterface::getInstance().pop();
}

CommandInformation Command::getInformation() const {
    return info;
}
