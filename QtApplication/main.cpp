#include "Logger/logger.h"
#include "MainWidgets/editorwindow.h"
#include "ToolStateMachine/toolcontext.h"

#include <QApplication>
#include <QImageReader>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    EditorWindow w;

    w.show();
    return QApplication::exec();
}
