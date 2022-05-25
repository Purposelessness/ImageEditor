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

void CommandInterface::clear() {
    commands.clear();
}

void CommandInterface::onWorkerFinished(ExitCode code) {
    if (code == ExitCode::invalid) {
        qInfo(commandInterface()) << "Work is finished but some actions cannot be done";
    } else if (code == ExitCode::unknown) {
        qWarning(commandInterface()) << "Some commands are unknown";
    } else {
        qDebug(commandInterface()) << "Work is finished";
    }
    emit finished();
}
