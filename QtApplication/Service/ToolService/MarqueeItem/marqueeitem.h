#ifndef IMAGEEDITOR_MARQUEEITEM_H
#define IMAGEEDITOR_MARQUEEITEM_H


#include <QAbstractGraphicsShapeItem>

class MarqueeItem : public QAbstractGraphicsShapeItem {
public:
    explicit MarqueeItem();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    [[nodiscard]] QRectF boundingRect() const override;
    virtual void setRect(const QRectF &rect);

protected:
    [[nodiscard]] virtual QPainterPath marqueeShape() const;

private:
    static QPen whiteSolidPen;
    static QPen blackDashPen;

    QRectF rect{};
};


#endif //IMAGEEDITOR_MARQUEEITEM_H
