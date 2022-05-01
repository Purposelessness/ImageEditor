#include "imagecontainer.h"
#include "../../logger.h"
#include "../../Service/UndoService/undoservice.h"
#include "../../Data/data.h"
#include "../../Service/ToolService/ToolCategory/FigureCategory/figurecategory.h"

#include <QColorSpace>
#include <QMouseEvent>
#include <QGraphicsItem>

ImageContainer::ImageContainer(QWidget *parent) : QGraphicsView(parent), scene(new QGraphicsScene),
                                                  painter(Painter(this)) {
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setViewportMargins(-2, -2, -2, -2);
//    setBackgroundRole(QPalette::Mid);
    setViewportUpdateMode(QGraphicsView::MinimalViewportUpdate);

    connect(scene, SIGNAL(selectionChanged()), this, SLOT(onSelectionChanged()));

    setScene(scene);
    scene->addItem(&eventFilter);

    WidgetData::getInstance().setGraphicsView(this);
}

void ImageContainer::setImage(const QImage &newImage) {
    qDebug(ui()) << "Setting destImage with size" << newImage.size();
    pixmap = QPixmap::fromImage(newImage);
    focusItem = nullptr;
    pixmapItem = new QGraphicsPixmapItem;
    pixmapItem->setPixmap(pixmap);
    pixmapItem->setTransformationMode(Qt::SmoothTransformation);
    scale(1);
    resize();
    scene->addItem(pixmapItem);
}

void ImageContainer::scale(float newScaleValue) {
    scaleValue = newScaleValue;
    if (pixmapItem)
        pixmapItem->setScale(scaleValue);
    resize();
}

void ImageContainer::resize() {
    if (focusItem) {
        auto rect = focusItem->mapToScene(focusItem->boundingRect()).boundingRect();
        QGraphicsView::resize(rect.size().toSize());
        setSceneRect(rect);
        fitInView(focusItem);
    } else if (pixmapItem) {
        auto rect = pixmapItem->mapToScene(pixmapItem->boundingRect()).boundingRect();
        QGraphicsView::resize(rect.size().toSize());
        setSceneRect(rect);
        fitInView(pixmapItem);
    }
}

void ImageContainer::resizeEvent(QResizeEvent *event) {
    QGraphicsView::resizeEvent(event);
}

void ImageContainer::mousePressEvent(QMouseEvent *event) {
    if (!itemIsSelected) {
        painter.onMousePressed(mapToScene(event->pos()).toPoint());
    } else if (selectedItem != nullptr && selectedItem != itemAt(event->pos())) {
        selectedItem->setSelected(false);
    }
    QGraphicsView::mousePressEvent(event);
}

void ImageContainer::mouseMoveEvent(QMouseEvent *event) {
    if (!itemIsSelected)
        Painter::onMouseMoved(mapToScene(event->pos()).toPoint());
    QGraphicsView::mouseMoveEvent(event);
    scene->update();
}

void ImageContainer::mouseReleaseEvent(QMouseEvent *event) {
    if (!itemIsSelected)
        Painter::onMouseReleased(mapToScene(event->pos()).toPoint());
    QGraphicsView::mouseReleaseEvent(event);
}

void ImageContainer::mapItemToPixmap(QGraphicsItem *item) {
    bool ok = true;
    auto transform = item->itemTransform(pixmapItem, &ok);
    if (!ok) {
        // TODO: error handling
        delete item;
        qCritical(ui()) << "Cannot transform graphics item to pixmap item";
        return;
    }
    item->setTransform(transform);
    item->setParentItem(pixmapItem);
}

void ImageContainer::addItem(QGraphicsItem *item) {
    scene->addItem(item);
    item->installSceneEventFilter(&eventFilter);
    mapItemToPixmap(item);
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
        selectedItem = nullptr;
    }
}

QGraphicsPixmapItem *ImageContainer::getPixmapItem() {
    return pixmapItem;
}

QPixmap ImageContainer::grab(const QRect &rect) {
    if (focusItem) {
        qDebug() << focusItem->boundingRect();
//        rect.getc
//        return QGraphicsView::grab(correctedRect);
    }
    return QGraphicsView::grab(rect);
}

void ImageContainer::focusOn(const QGraphicsItem *item) {
    focusItem = const_cast<QGraphicsItem *>(item);
    resize();
}

QGraphicsItem *ImageContainer::getFocusItem() {
    return focusItem;
}
