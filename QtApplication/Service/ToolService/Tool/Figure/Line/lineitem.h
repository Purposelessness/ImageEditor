#ifndef IMAGEEDITOR_LINEITEM_H
#define IMAGEEDITOR_LINEITEM_H

#include <QGraphicsLineItem>

#include "linemodel.h"

class LineItem : public QGraphicsLineItem {
public:
    explicit LineItem(LineModel *model);

protected:
    QVariant itemChange(QGraphicsItem::GraphicsItemChange change, const QVariant &value) override;

private:
    LineModel *model;
};


#endif //IMAGEEDITOR_LINEITEM_H
