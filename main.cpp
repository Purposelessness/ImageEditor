#include "QtApplication/logger.h"
#include "QtApplication/MainWidgets/EditorWindow/editorwindow.h"
#include "QtApplication/Service/ToolService/toolservice.h"

#include "Library/Bitmap/image.h"
#include "Library/Bitmap/loader.h"
#include "Library/Bitmap/saver.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    ToolService::getInstance();
    EditorWindow w;

    Bitmap::Image bitmap = Bitmap::Loader::load("D:/simpsonsvr.bmp");
    bitmap.printFileHeader();
    bitmap.printInfoHeader();
    Bitmap::Saver::save(&bitmap, "D:/new.bmp");

    return QApplication::exec();
}
