#include "logger.h"
#include "MainWidgets/EditorWindow/editorwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    EditorWindow w;
    return QApplication::exec();
}
