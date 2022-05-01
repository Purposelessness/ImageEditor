#include "pixmapitem.h"

#include <QPainter>
#include <QStyle>
#include <QStyleOptionGraphicsItem>

QPen PixmapItem::whiteSolidPen{};
QPen PixmapItem::blackDashPen{};

PixmapItem::PixmapItem() {
    createPens();
}

PixmapItem::PixmapItem(const QPixmap &pixmap) : QGraphicsPixmapItem(pixmap) {
    createPens();
}

void PixmapItem::createPens() {
    whiteSolidPen.setStyle(Qt::SolidLine);
    whiteSolidPen.setColor(Qt::white);
    whiteSolidPen.setWidth(0);

    blackDashPen.setStyle(Qt::DashLine);
    blackDashPen.setColor(Qt::black);
    blackDashPen.setWidth(0);
}

void PixmapItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QStyleOptionGraphicsItem newOption(*option);
    newOption.state &= ~QStyle::State_Selected;

    QGraphicsPixmapItem::paint(painter, &newOption, widget);

    if (option->state & (QStyle::State_Selected)) {
        painter->setBrush(Qt::NoBrush);
        painter->setPen(whiteSolidPen);
        painter->drawPath(marqueeShape());

        painter->setPen(blackDashPen);
        painter->drawPath(marqueeShape());
    }
}

QPainterPath PixmapItem::marqueeShape() const {
    return QGraphicsPixmapItem::shape();
}
