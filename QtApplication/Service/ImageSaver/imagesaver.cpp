#include "imagesaver.h"
#include "../CommandInterface/commandinterface.h"
#include "../../logger.h"

#include <QStandardPaths>
#include <QFileDialog>

void ImageSaver::saveImage(const QImage &image, const QString &destFilePath) {
    QString fileName;
    if (destFilePath.isEmpty()) {
        const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        fileName = QFileDialog::getSaveFileName(nullptr, QWidget::tr("Save"),
                                                        picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                        QWidget::tr("BMP (*.bmp);;JPEG (*.jpg *.jpeg);;PNG (*.png)"));

    } else {
        fileName = destFilePath;
    }
    if (fileName.isEmpty()) {
        qWarning(fileSystem()) << "Selected invalid file name";
        return;
    }
    image.save(fileName);
}

void ImageSaver::saveImageViaLib(const QString &srcImage, const QString &destFilePath) {
    QString fileName;
    if (destFilePath.isEmpty()) {
        const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        fileName = QFileDialog::getSaveFileName(nullptr, QWidget::tr("Save"),
                                                picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                QWidget::tr("BMP (*.bmp);;JPEG (*.jpg *.jpeg);;PNG (*.png)"));

    } else {
        fileName = destFilePath;
    }
    if (fileName.isEmpty()) {
        qWarning(fileSystem()) << "Selected invalid file name";
        return;
    }
    CommandInterface::getInstance().processImage(srcImage, fileName);
}
