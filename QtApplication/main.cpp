#include "Logger/logger.h"
#include "MainWidgets/EditorWindow/editorwindow.h"
#include "MainWidgets/iv.h"
#include "ToolService/toolservice.h"

#include <QApplication>
#include <QImageReader>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    EditorWindow w;
//    IV iv;
//    iv.show();
    return QApplication::exec();
}
