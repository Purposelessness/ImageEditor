#ifndef IMAGEEDITOR_IMAGETOOLSMODEL_H
#define IMAGEEDITOR_IMAGETOOLSMODEL_H


#include "../toolcategorymodel.h"
#include "../../Tool/Figure/figure.h"

class IImageToolsModel {
public:
    virtual void invertColors(const QPainterPath &path) = 0;
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

class ImageToolsModel : public ToolCategoryModel<Tool>, public IImageToolsModel {
public:
    ImageToolsModel();

    void createTools() override;

protected:
    void invertColors(const QPainterPath &path) override;

private:
    ImageToolsModelObject *object;
};


#endif //IMAGEEDITOR_IMAGETOOLSMODEL_H
