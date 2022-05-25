#include "outliner.h"
#include "../../../../../Data/data.h"
#include "../../../../CommandInterface/commandinformation.h"
#include "../../../../UndoService/Command/additemcommand.h"

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

Outliner::Outliner() : Tool(tr("Outliner")) {
    connect(this, SIGNAL(triggered(QString)), this, SLOT(use()));
}

void Outliner::use() {
    auto view = WidgetData::getInstance().getGraphicsView();
    auto rect = view->getPixmapItem()->boundingRect();
    auto image = view->grab().toImage();
    editImage(&image, 1, Qt::white, Qt::red);
    auto pixmap = new QGraphicsPixmapItem(QPixmap::fromImage(image.scaledToWidth(rect.width())));
    view->addItem(pixmap);

    auto data = CommandOutlinerData{1, Qt::white, Qt::red};
    auto info = CommandInformation{.outlinerData = data, .type = CommandType::outline};
    new AddItemCommand(pixmap, info);
}

void Outliner::editImage(QImage *image, int width, const QColor &color, const QColor &destColor) {
    auto srcImage = *image;
    auto imWidth = image->width();
    auto imHeight = image->height();

    auto srcRgb = color.rgb();
    qDebug() << qRed(srcRgb) << qGreen(srcRgb) << qBlue(srcRgb);

    for (int y = 0; y < imHeight; ++y) {
        for (int x = 0; x < imWidth; ++x) {
            QRgb pixel = srcImage.pixel(x, y);
            if (pixel == srcRgb) {
                for (int j = y - width; j <= y + width; ++j) {
                    for (int i = x - width; i <= x + width; ++i) {
                        auto *line = reinterpret_cast<QRgb *>(image->scanLine(j));
                        if (j >= 0 && i >= 0 && j < imHeight && i < imWidth) {
                            auto p = line[i];
                            if (p != srcRgb) {
                                line[i] = destColor.rgb();
                            }
                        }
                    }
                }
            }
        }
    }
}


