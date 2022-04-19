#ifndef IMAGEEDITOR_MARQUEEMODEL_H
#define IMAGEEDITOR_MARQUEEMODEL_H


#include "../../toolmodel.h"
#include "marqueeobject.h"

template<typename T>
class MarqueeModel : public ToolModel {
public:
    MarqueeModel();

    MarqueeModelObject *getObject();

protected:
    QGraphicsItem *startDrawing(const Coordinates &coordinates) override;
    void onDrawing(const Coordinates &coordinates) override;
    void finishDrawing(const Coordinates &coordinates) override;

private:
    MarqueeModelObject *object;
    T *marqueeItem = nullptr;
};

#include "marqueemodel.inl"


#endif //IMAGEEDITOR_MARQUEEMODEL_H
