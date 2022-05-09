#include "commandinterface.h"

#include "../../logger.h"

#include <QThread>

CommandInterface &CommandInterface::getInstance() {
    static CommandInterface instance;
    return instance;
}

void CommandInterface::processImage(const QString &srcFileName, const QString &destFileName) {
    auto worker = new CommandController(srcFileName, destFileName, commands);
    auto thread = new QThread();

    connect(thread, SIGNAL(started()), worker, SLOT(start()));
    connect(worker, SIGNAL(finished(ExitCode)), this, SLOT(onWorkerFinished(ExitCode)));
    connect(worker, SIGNAL(finished(ExitCode)), thread, SLOT(quit()));
    connect(worker, SIGNAL(finished(ExitCode)), worker, SLOT(deleteLater()));
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));

    worker->moveToThread(thread);
    thread->start();
}

void CommandInterface::push(Command *command) {
    commands.push_back(command);
}

Command *CommandInterface::pop() {
    auto t = commands.back();
    commands.pop_back();
    return t;
}

void CommandInterface::onWorkerFinished(ExitCode code) {
    qDebug(commandInterface()) << "Work is finished";
}
