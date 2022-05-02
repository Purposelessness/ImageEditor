#include "QtApplication/logger.h"
#include "QtApplication/MainWidgets/EditorWindow/editorwindow.h"
#include "QtApplication/Service/ToolService/toolservice.h"
#include "Library/Bitmap/image.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    ToolService::getInstance();
    EditorWindow w;

    Bitmap::Image image;
    image.read(R"(D:\simpsonsvr.bmp)");
    image.write(R"(D:\new.bmp)");

    return QApplication::exec();
}
