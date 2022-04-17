#ifndef IMAGEEDITOR_RECTITEM_H
#define IMAGEEDITOR_RECTITEM_H

#include <QGraphicsRectItem>

class IShapeModel;

class RectItem : public QGraphicsRectItem {
public:
    explicit RectItem(IShapeModel *model);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    IShapeModel *model;
};


#endif //IMAGEEDITOR_RECTITEM_H
