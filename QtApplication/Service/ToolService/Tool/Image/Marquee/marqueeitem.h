#ifndef IMAGEEDITOR_MARQUEEITEM_H
#define IMAGEEDITOR_MARQUEEITEM_H


#include <QAbstractGraphicsShapeItem>

class MarqueeItem : public QAbstractGraphicsShapeItem {
public:
    explicit MarqueeItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;
    void setRect(const QRectF &rect);

protected:
    virtual void drawItem(QPainter *painter, const QRectF &rect) = 0;

    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

    QRectF rect{};

private:
    static QPen whiteSolidPen;
    static QPen blackDashPen;
};


#endif //IMAGEEDITOR_MARQUEEITEM_H
