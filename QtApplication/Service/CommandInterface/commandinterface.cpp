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

    qDebug(commandInterface()) << "Starting worker" << commands.length();
    for (auto command: commands) {
        auto info = command->getInformation();
        qDebug() << "command";
        switch (info.type) {
            case CommandType::none:
                qDebug(commandInterface()) << "NONE!";
                break;
            case CommandType::ellipse:
                qDebug(commandInterface()) << "Ellipse" << info.figureData.rect << info.figureData.fillColor
                                           << info.figureData.borderColor << info.figureData.thickness;
                break;
            case CommandType::triangle:
                qDebug(commandInterface()) << "Triangle" << info.figureData.rect << info.figureData.fillColor
                                           << info.figureData.borderColor << info.figureData.thickness;
                break;
            case CommandType::line:
                qDebug(commandInterface()) << "Line" << info.lineData.x1 << info.lineData.y1 << info.lineData.x2
                                           << info.lineData.y2 << info.lineData.thickness;
                break;
            case CommandType::ellipseColorInverter:
                qDebug(commandInterface()) << "EllipseColorInverter" << info.colorInverterData.srcRect
                                           << info.colorInverterData.destRect;
                break;
            case CommandType::crop:
                qDebug(commandInterface()) << "Crop";
                break;
            default:
                qDebug(commandInterface()) << "DEFAULT";
                break;
        }
    }

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
    qDebug(commandInterface()) << "Pushed" << commands.length();
}

Command *CommandInterface::pop() {
    auto t = commands.back();
    commands.pop_back();
    qDebug(commandInterface()) << "Popped" << commands.length();
    return t;
}

void CommandInterface::onWorkerFinished(ExitCode code) {
    qDebug(commandInterface()) << "Work is finished";
}

//qsizetype CommandInterface::size() const {
//    return commands.size();
//}
//
//Command *CommandInterface::at(qsizetype i) {
//    return commands.at(i);
//}
