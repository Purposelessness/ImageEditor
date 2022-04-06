#ifndef IMAGEEDITOR_ELLIPSEITEM_H
#define IMAGEEDITOR_ELLIPSEITEM_H

#include <QGraphicsEllipseItem>

#include "ellipsemodel.h"

class EllipseItem : public QGraphicsEllipseItem {
public:
    explicit EllipseItem(EllipseModel *model);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    EllipseModel *model;
};


#endif //IMAGEEDITOR_ELLIPSEITEM_H
