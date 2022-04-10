#include "../../logger.h"

#include <iostream>
#include <QCoreApplication>
#include <QDir>
#include <QFile>
#include <QDateTime>
#include <QTextStream>

Q_LOGGING_CATEGORY(ui, "UI")
Q_LOGGING_CATEGORY(fileSystem, "FileSystem")
Q_LOGGING_CATEGORY(service, "Service")
Q_LOGGING_CATEGORY(toolService, "ToolService", QtInfoMsg)
Q_LOGGING_CATEGORY(core, "Core")
Q_LOGGING_CATEGORY(stateMachine, "StateMachine", QtInfoMsg)

QString fileName;

void initLogger() {
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy_MM_dd_hh_mm");
    fileName = QString("%1/logs/log_%2.txt").arg(QCoreApplication::applicationDirPath(), currentDateTime);
    qInstallMessageHandler(messageHandler);
}

void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString& msg) {
    QString dirName = "logs";
    if (!QDir(dirName).exists())
        QDir().mkdir(dirName);

    QFile logFile(fileName);
    if (!logFile.open(QFile::Append | QFile::Text)) {
        return;
    }

    QTextStream logText(&logFile);
    QString logDateTime = "[" + QDateTime::currentDateTime().toString("dd.MM.yyyy hh:mm:ss.zzz") + "]";
    QString messageType;
    QString contextInfo = QString("%1 (line %2) : %3").arg(context.function, QString::number(context.line), context.file);
    switch (type) {
        case QtDebugMsg:
            messageType = "|DBG|";
            break;
        case QtInfoMsg:
            messageType = "|INF|";
            break;
        case QtWarningMsg:
            messageType = "|WRN|";
            break;
        case QtCriticalMsg:
            messageType = "|CRT|";
            break;
        case QtFatalMsg:
            messageType = "|FTL|";
            abort();
        default:
            break;
    }

    logText << QString("%1 %2 %3: %4 at %5").arg(logDateTime, messageType, context.category, msg, contextInfo) << Qt::endl;
    std::cout << QString("%1 %2: %3 at %4").arg(messageType, context.category, msg, contextInfo).toStdString() << std::endl;

    logText.flush();
    logFile.flush();
    logFile.close();
}
