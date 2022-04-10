#ifndef IMAGEEDITOR_ITOOLCATEGORYMODEL_H
#define IMAGEEDITOR_ITOOLCATEGORYMODEL_H


#include <QObject>

class Tool;
class QAction;

class ToolCategoryModelObject : public QObject {
Q_OBJECT

signals:
    void toolAdded(QAction *action);
};

class IToolCategoryModel {
public:
    virtual void createTools() = 0;
    virtual Tool *getTool() = 0;

    ToolCategoryModelObject *object = new ToolCategoryModelObject;
};


#endif //IMAGEEDITOR_ITOOLCATEGORYMODEL_H
