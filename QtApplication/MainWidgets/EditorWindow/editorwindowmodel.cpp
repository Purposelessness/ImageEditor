#include "editorwindowmodel.h"
#include "../../Logger/logger.h"

#include <QStandardPaths>
#include <QFileDialog>
#include <QImageReader>
#include <QGuiApplication>
#include <QMessageBox>

EditorWindowModel::EditorWindowModel(QMainWindow *widget) : view(widget), imageViewer(new ImageViewer()),
                                                            toolBar(new ToolBar()), toolDock(new ToolDock()) {
    view->setCentralWidget(imageViewer);
    view->addToolBar(Qt::TopToolBarArea, toolBar);
    view->addDockWidget(Qt::RightDockWidgetArea, toolDock);
}

void EditorWindowModel::openFile() {
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString fileName = QFileDialog::getOpenFileName(view, QWidget::tr("Open"),
                                                    picturesLocation.isEmpty() ? QDir::currentPath()
                                                                               : picturesLocation.last(),
                                                    QWidget::tr(
                                                            "All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if (fileName.isEmpty())
        qWarning(fileSystem()) << "Selected invalid file";
    else
        loadFile(fileName);
}

void EditorWindowModel::saveFile() {
    qDebug(fileSystem()) << "File saved";
}

void EditorWindowModel::showDock() {
    toolDock->show();
}

void EditorWindowModel::loadFile(const QString& fileName) {
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(view, QGuiApplication::applicationDisplayName(),
                                 QWidget::tr("Cannot load %1: %2").arg(QDir::toNativeSeparators(fileName),
                                                              reader.errorString()));
        return;
    }

    imageViewer->setImage(newImage);
}
