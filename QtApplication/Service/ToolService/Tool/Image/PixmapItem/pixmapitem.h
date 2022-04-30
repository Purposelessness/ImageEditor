#ifndef IMAGEEDITOR_PIXMAPITEM_H
#define IMAGEEDITOR_PIXMAPITEM_H


#include <QGraphicsPixmapItem>

class PixmapItem : public QGraphicsPixmapItem {
public:
    PixmapItem() = default;
    explicit PixmapItem(const QPixmap &pixmap);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;

protected:
    [[nodiscard]] virtual QPainterPath marqueeShape() const;

private:
    static QPen whiteSolidPen;
    static QPen blackDashPen;
};


#endif //IMAGEEDITOR_PIXMAPITEM_H
