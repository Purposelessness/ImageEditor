#include "ellipsecolorinverter.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../ColorInverter/colorinverterworker.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "ellipsepixmapitem.h"

#include <QDialog>
#include <QLabel>

EllipseColorInverter::EllipseColorInverter() : Marquee<EllipseMarqueeItem>(tr("EllipseColorInverter")) {}

void EllipseColorInverter::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    auto pixmapItem = new EllipsePixmapItem();
    graphicsView->addItem(pixmapItem);

    auto rect = path.boundingRect().toRect();
    auto itemPos = rect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);

    FigurePoints points = FigureCalculator::calculateEllipse(0, 0, rect.width(), rect.height());
    auto image = graphicsView->grab(rect).toImage();

    auto dialog = new QDialog();
    auto label = new QLabel();
    label->setPixmap(QPixmap::fromImage(image));
    label->setParent(dialog);
    dialog->resize(label->size());
    dialog->show();

    auto newImage = ColorInverterWorker::start(points, image);

    pixmapItem->setPixmap(QPixmap::fromImage(newImage));
    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    qDebug() << rect;
    qDebug() << pixmapItem->pos() << pixmapItem->mapToScene(pixmapItem->pos()) << pixmapItem->boundingRect();

    new AddItemCommand(pixmapItem);

    pixmapItem->setSelected(true);
}
