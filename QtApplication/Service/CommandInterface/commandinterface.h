#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_COMMANDINTERFACE_H
#define IMAGEEDITOR_COMMANDINTERFACE_H


#include "commandcontroller.h"
#include "icommand.h"

#include <QVector>
#include <QObject>

class CommandInterface : QObject {
Q_OBJECT

public:
    static CommandInterface& getInstance();

    void processImage(const QString &srcFileName, const QString &destFileName);
    void push(ICommand *command);
    ICommand *pop();

private slots:
    void onWorkerFinished(ExitCode code);

private:
    CommandInterface() = default;
    CommandInterface(const CommandInterface& root) = delete;
    CommandInterface& operator=(const CommandInterface&) = delete;

    QVector<ICommand *> commands;
};


#endif //IMAGEEDITOR_COMMANDINTERFACE_H

#pragma clang diagnostic pop