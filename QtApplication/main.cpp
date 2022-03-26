#include "logger.h"
#include "MainWidgets/EditorWindow/editorwindow.h"
//#include "MainWidgets/iv.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    EditorWindow w;
//    IV iv;
//    iv.show();
    return QApplication::exec();
}
