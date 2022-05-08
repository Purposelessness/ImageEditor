#include "imageloader.h"
#include "../../logger.h"

#include <QImageReader>
#include <QStandardPaths>
#include <QFileDialog>

ImageLoaderOut ImageLoader::loadImage() {
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString fileName = QFileDialog::getOpenFileName(nullptr, QWidget::tr("Open"),
                                                    picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                    QWidget::tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if (fileName.isEmpty()) {
        qWarning(fileSystem()) << "Selected invalid file";
        return ImageLoaderOut{};
    }
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    return newImage.isNull() ? ImageLoaderOut{} : ImageLoaderOut{.image = newImage, .imagePath = fileName};
}
