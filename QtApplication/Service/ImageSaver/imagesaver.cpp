#include "imagesaver.h"
#include "../../logger.h"

#include <QStandardPaths>
#include <QFileDialog>

void ImageSaver::saveImage(const QImage &image) {
    const QStringList picturesLocation = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
    QString fileName = QFileDialog::getSaveFileName(nullptr, QWidget::tr("Save"),
                                                    picturesLocation.isEmpty() ? QDir::currentPath() : picturesLocation.last(),
                                                    QWidget::tr("All files (*.*);;JPEG (*.jpg *.jpeg);;PNG (*.png);;BMP (*.bmp)"));
    if (fileName.isEmpty()) {
        qWarning(fileSystem()) << "Selected invalid file name";
        return;
    }
    image.save(fileName);
}
