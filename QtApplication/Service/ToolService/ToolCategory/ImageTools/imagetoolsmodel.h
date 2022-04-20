#ifndef IMAGEEDITOR_IMAGETOOLSMODEL_H
#define IMAGEEDITOR_IMAGETOOLSMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class ImageToolsModelObject;

class IImageToolsModel {
public:
    virtual void invertColors(const QPainterPath &path) = 0;
};

class ImageToolsModel : public ToolCategoryModel<Tool>, public IImageToolsModel {
public:
    ImageToolsModel();

    void createTools() override;
    void setPixmapItem(QGraphicsPixmapItem *pixmapItem);

protected:
    void invertColors(const QPainterPath &path) override;

private:
    ImageToolsModelObject *object;
    QGraphicsPixmapItem *pixmapItem = nullptr;
};

class ImageToolsModelObject : public QObject {
Q_OBJECT

public:
    explicit ImageToolsModelObject(IImageToolsModel *base, QObject *parent = nullptr);

public slots:
    void invertColors(const QPainterPath &path);

private:
    IImageToolsModel *base;
};


#endif //IMAGEEDITOR_IMAGETOOLSMODEL_H
