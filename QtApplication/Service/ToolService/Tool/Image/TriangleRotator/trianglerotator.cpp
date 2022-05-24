#include "trianglerotator.h"
#include "../../../../../Data/data.h"
#include "../../../../../MainWidgets/ImageViewer/imagecontainer.h"
#include "../../../../UndoService/Command/additemcommand.h"
#include "../PixmapItem/pixmapitem.h"
#include "../../../../FigureExtracterWorker/figureextractorworker.h"
#include "../../../../../../Library/Service/FigureCalculator/calculator.h"

#include <QInputDialog>

TriangleRotator::TriangleRotator() : Marquee<TriangleMarqueeItem>(tr("TriangleRotator")) {}

void TriangleRotator::marqueePaintedEvent(const QPainterPath &path) {
    auto graphicsView = WidgetData::getInstance().getGraphicsView();
    if (!graphicsView)
        return;

    auto pixmapItem = new PixmapItem();
    graphicsView->addItem(pixmapItem);

    auto mappedToSceneRect = path.boundingRect().toRect();

    int x0 = mappedToSceneRect.left();
    int y0 = mappedToSceneRect.top();
    auto cachedRect = mappedToSceneRect;
    FigurePoints points = Calculator::triangle(0, 0, mappedToSceneRect.width(), mappedToSceneRect.height());
    auto image = graphicsView->grab(&mappedToSceneRect).toImage();
    points.x = x0 - mappedToSceneRect.left();
    points.y = y0 - mappedToSceneRect.top();
    QPoint sceneOffset(points.x, points.y);

    auto itemRect = pixmapItem->mapFromScene(mappedToSceneRect).boundingRect().toRect();
    auto itemPos = itemRect.topLeft();
    auto parentPos = pixmapItem->mapToParent(itemPos);
    pixmapItem->setPos(parentPos);

    auto newImage = FigureExtractorWorker::start(points, image);

    auto pixmap = QPixmap::fromImage(newImage).scaledToWidth(itemRect.width());
    pixmapItem->setPixmap(pixmap);
    auto center = pixmapItem->mapFromScene(cachedRect.center());
    pixmapItem->setTransformOriginPoint(center);

    pixmapItem->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);

    bool ok;
    int angle = QInputDialog::getInt(nullptr, tr("Rotation angle"), tr("Angle:"), 0, INT_MIN, INT_MAX, 1, &ok);
    if (!ok) angle = 0;

    auto offset = pixmapItem->mapToParent(pixmapItem->mapFromScene(sceneOffset)).toPoint();
    auto rect = pixmapItem->mapToParent(pixmapItem->mapFromScene(cachedRect)).boundingRect().toRect();
    auto data = CommandRotatorData{rect, offset, pixmapItem, angle};
    auto info = CommandInformation{.rotatorData = data, .type = CommandType::triangleRotator};
    pixmapItem->setRotation(angle);
    new AddItemCommand(pixmapItem, info);

    pixmapItem->setSelected(true);
}
