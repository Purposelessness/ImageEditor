#ifndef IMAGEEDITOR_LOGGER_H
#define IMAGEEDITOR_LOGGER_H

#include <QLoggingCategory>

Q_DECLARE_LOGGING_CATEGORY(ui)
Q_DECLARE_LOGGING_CATEGORY(fileSystem)
Q_DECLARE_LOGGING_CATEGORY(service)
Q_DECLARE_LOGGING_CATEGORY(commandInterface)
Q_DECLARE_LOGGING_CATEGORY(toolService)
Q_DECLARE_LOGGING_CATEGORY(core)
Q_DECLARE_LOGGING_CATEGORY(stateMachine)

void initLogger();
void messageHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

#endif //IMAGEEDITOR_LOGGER_H
