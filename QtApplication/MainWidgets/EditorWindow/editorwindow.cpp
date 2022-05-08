#include "editorwindow.h"
#include "../../Data/data.h"
#include "../../logger.h"
#include "../../Service/ImageLoader/imageloader.h"
#include "../../Service/ImageSaver/imagesaver.h"

#include <QStandardPaths>
#include <QFileDialog>
#include <QLabel>

EditorWindow::EditorWindow(QWidget *parent) : view(new EditorWindowView(parent)) {
    connect(view, SIGNAL(openActionTriggered()), this, SLOT(openImage()));
    connect(view, SIGNAL(saveActionTriggered()), this, SLOT(saveImage()));
    connect(view, SIGNAL(showDockActionTriggered()), this, SLOT(showDock()));
    view->show();
}

void EditorWindow::openImage() {
    auto imageLoaderOut = ImageLoader::loadImage();
    if (!imageLoaderOut.image.isNull()) {
        view->imageViewer->setImage(imageLoaderOut.image);
        imagePath = imageLoaderOut.imagePath;
    }
}

void EditorWindow::saveImage() {
    if (view->useLibAct->isChecked()) {
        ImageSaver::saveImageViaLib(imagePath);
    } else {
        ImageSaver::saveImage(WidgetData::getInstance().getGraphicsView()->grab().toImage());
    }
}

void EditorWindow::showDock() {
    view->toolDock->show();
}
