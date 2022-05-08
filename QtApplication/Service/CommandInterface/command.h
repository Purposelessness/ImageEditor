#ifndef IMAGEEDITOR_COMMAND_H
#define IMAGEEDITOR_COMMAND_H


#include "commandinformation.h"
#include "commandinterface.h"

#include <QGraphicsItem>

class Command {
public:
    explicit Command(const CommandInformation &information);
    [[nodiscard]] CommandInformation getInformation() const;
    void push();
    static void pop();

private:
    CommandInformation info{};
};


#endif //IMAGEEDITOR_COMMAND_H
