#ifndef IMAGEEDITOR_ELLIPSEITEM_H
#define IMAGEEDITOR_ELLIPSEITEM_H

#include <QGraphicsEllipseItem>

class IShapeModel;

class EllipseItem : public QGraphicsEllipseItem {
public:
    explicit EllipseItem(IShapeModel *model);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    IShapeModel *model;
};


#endif //IMAGEEDITOR_ELLIPSEITEM_H
