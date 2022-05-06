#include "QtApplication/logger.h"
#include "QtApplication/MainWidgets/EditorWindow/editorwindow.h"
#include "QtApplication/Service/ToolService/toolservice.h"

#include "Test/tester.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    initLogger();
    ToolService::getInstance();
    EditorWindow w;

//    Tester::invertColors();
//    Tester::paintEllipse();
//    Tester::paintBorderEllipse();
//    Tester::paintOnePixelLine();
//    Tester::paintSimpleLines();
//    Tester::paintComplexLines();
    Tester::paintTriangle();

    return QApplication::exec();
}
