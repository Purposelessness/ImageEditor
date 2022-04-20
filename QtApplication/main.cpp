#include "logger.h"
#include "MainWidgets/EditorWindow/editorwindow.h"
#include "Service/ToolService/toolservice.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    ToolService::getInstance();
    EditorWindow w;
    return QApplication::exec();
}
