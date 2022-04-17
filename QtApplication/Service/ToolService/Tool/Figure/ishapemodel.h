#ifndef IMAGEEDITOR_ISHAPEMODEL_H
#define IMAGEEDITOR_ISHAPEMODEL_H


class QAbstractGraphicsShapeItem;

class IShapeModel {
public:
    virtual void onItemSelected(QAbstractGraphicsShapeItem *item) = 0;
    virtual void onItemDeselected() = 0;
};


#endif //IMAGEEDITOR_ISHAPEMODEL_H
