#include "imagecontainer.h"
#include "../../logger.h"
#include "../../Service/UndoService/undoservice.h"
#include "../../Data/data.h"
#include "../../Service/ToolService/ToolCategory/FigureCategory/figurecategory.h"

#include <QColorSpace>
#include <QMouseEvent>
#include <QGraphicsItem>

ImageContainer::ImageContainer(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene), painter(Painter(this)) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(-2, -2, -2, -2);
    setBackgroundRole(QPalette::Mid);
    setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(onSelectionChanged()));

    setScene(scene);
    scene->addItem(&eventFilter);

    WidgetData::getInstance().setGraphicsView(this);
}

void ImageContainer::setImage(const QImage& newImage) {
    scaleValue = 1;
    qDebug(ui()) << "Setting image with size" << newImage.size();
    pixmap = QPixmap::fromImage(newImage);
/*  Color space validity
    auto pixmap = new QPixmap(QPixmap::fromImage(newImage));
    image = pixmap->toImage();
    if (image.colorSpace().isValid())
    image.convertToColorSpace(QColorSpace::SRgb); */
    pixmapItem = new QGraphicsPixmapItem;
    pixmapItem->setPixmap(pixmap);
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);
    resize(pixmap.size());
    scene->addItem(pixmapItem);
}

void ImageContainer::scale(float newScaleValue) {
    scaleValue = newScaleValue;
    resize(scaleValue * pixmap.size());
}

void ImageContainer::resizeEvent(QResizeEvent *event) {
    if (pixmapItem)
        pixmapItem->setScale(scaleValue);
    setSceneRect(contentsRect());
    QGraphicsView::resizeEvent(event);
}

void ImageContainer::mousePressEvent(QMouseEvent *event) {
    if (!itemIsSelected) {
        painter.onMousePressed(event->pos());
    } else {
        if (selectedItem && selectedItem != itemAt(event->pos())) {
            selectedItem->setSelected(false);
        }
    }
    QGraphicsView::mousePressEvent(event);
}

void ImageContainer::mouseMoveEvent(QMouseEvent *event) {
    if (!itemIsSelected)
        Painter::onMouseMoved(event->pos());
    QGraphicsView::mouseMoveEvent(event);
    scene->update();
}

void ImageContainer::mouseReleaseEvent(QMouseEvent *event) {
    if (!itemIsSelected)
        Painter::onMouseReleased(event->pos());
    QGraphicsView::mouseReleaseEvent(event);
}

void ImageContainer::onDrawingFinished(QGraphicsItem *item) {
    bool ok = true;
    auto transform = item->itemTransform(pixmapItem, &ok);
    if (!ok) {
        // TODO: error handling
        delete item;
        qCritical(ui()) << "Cannot transform graphics item to pixmap item";
        return;
    }
    item->setParentItem(pixmapItem);
    item->setTransform(transform);
}

void ImageContainer::addItem(QGraphicsItem *item) {
    scene->addItem(item);
    item->setFlags(QGraphicsItem::ItemIsSelectable | QGraphicsItem::ItemIsMovable);
    item->installSceneEventFilter(&eventFilter);
    onDrawingFinished(item);
}

QGraphicsScene *ImageContainer::getScene() {
    return scene;
}

void ImageContainer::onSelectionChanged() {
    auto list = scene->selectedItems();
    if (list.length() <= 0) {
        selectedItem = nullptr;
        itemIsSelected = false;
    } else if (list.length() == 1) {
        selectedItem = list.value(0);
        itemIsSelected = true;
    } else {
        if (!selectedItem)
            selectedItem = list.value(0);
        selectedItem->setSelected(false);
    }
}

QGraphicsPixmapItem *ImageContainer::getPixmapItem() {
    return pixmapItem;
}
