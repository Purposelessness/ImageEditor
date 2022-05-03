#include "editorwindow.h"
#include "../../logger.h"
#include "../../Service/imageio.h"

#include <QtConcurrent>
#include <QStandardPaths>
#include <QFileDialog>

EditorWindow::EditorWindow(QWidget *parent) : view(new EditorWindowView(parent)) {
    connect(view, SIGNAL(openActionTriggered()), this, SLOT(openImage()));
    connect(view, SIGNAL(saveActionTriggered()), this, SLOT(saveImage()));
    connect(view, SIGNAL(showDockActionTriggered()), this, SLOT(showDock()));
    view->show();
}

void EditorWindow::openImage() {
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString fileName = QFileDialog::getOpenFileName(view, QWidget::tr("Open"),
                                                    picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                    QWidget::tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if (fileName.isEmpty())
        qWarning(fileSystem()) << "Selected invalid file";
    else
        loadImage(fileName);
}

void EditorWindow::loadImage(const QString &fileName) {
// TODO: make load destImage by tiles with multithreading in ImageReader
    readFuture = QtConcurrent::run(ImageReader::loadImage, fileName);
    view->imageViewer->setImage(readFuture.result());
}

void EditorWindow::saveImage() {
    auto writeFuture = QtConcurrent::run(ImageWriter::saveImage, QImage());
}

void EditorWindow::showDock() {
    view->toolDock->show();
}

EditorWindow::~EditorWindow() {
    if (readFuture.isRunning())
        readFuture.cancel();
}
