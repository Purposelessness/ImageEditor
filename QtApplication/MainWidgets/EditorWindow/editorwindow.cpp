#include "editorwindow.h"
#include "../../Data/data.h"
#include "../../logger.h"
#include "../../Service/ImageLoader/imageloader.h"
#include "../../Service/ImageSaver/imagesaver.h"
#include "../../Service/UndoService/undoservice.h"
#include "../../Service/CommandInterface/commandinterface.h"

#include <QStandardPaths>
#include <QFileDialog>
#include <QLabel>

EditorWindow::EditorWindow(QWidget *parent) : view(new EditorWindowView(parent)) {
    connect(view, SIGNAL(openActionTriggered()), this, SLOT(openImage()));
    connect(view, SIGNAL(saveActionTriggered()), this, SLOT(saveImage()));
    connect(view, SIGNAL(showDockActionTriggered()), this, SLOT(showDock()));
    connect(&CommandInterface::getInstance(), SIGNAL(finished()), this, SLOT(openTempImage()));
    WidgetData::getInstance().setEditorWindow(this);
    view->show();
}

void EditorWindow::openImage(bool temp) {
    QString filePath = temp ? QStandardPaths::writableLocation(QStandardPaths::TempLocation).append("/qt_file.bmp") : QString();
    auto imageLoaderOut = ImageLoader::loadImage(filePath);
    if (!imageLoaderOut.image.isNull()) {
        UndoService::getInstance().clear();
        view->imageViewer->setImage(imageLoaderOut.image);
        imagePath = imageLoaderOut.imagePath;
    }
}

void EditorWindow::saveImage(bool temp) {
    QString filePath = QString();
    if (temp) {
        filePath = QStandardPaths::writableLocation(QStandardPaths::TempLocation).append("/qt_file.bmp");
        openTempFlag = true;
    }

    if (view->useLibAct->isChecked()) {
        ImageSaver::saveImageViaLib(imagePath, filePath);
    } else {
        ImageSaver::saveImage(WidgetData::getInstance().getGraphicsView()->grab().toImage(), filePath);
    }
}

void EditorWindow::showDock() {
    view->toolDock->show();
}

void EditorWindow::openTempImage() {
    if (openTempFlag) {
        openImage(true);
        openTempFlag = false;
    }
}
