#ifndef IMAGEEDITOR_RECTITEM_H
#define IMAGEEDITOR_RECTITEM_H

#include <QGraphicsRectItem>

#include "rectmodel.h"

class RectItem : public QGraphicsRectItem {
public:
    explicit RectItem(RectModel *model);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    RectModel *model;
};


#endif //IMAGEEDITOR_RECTITEM_H
