#ifndef IMAGEEDITOR_TOOLCONTEXTOBJECT_H
#define IMAGEEDITOR_TOOLCONTEXTOBJECT_H


#include <QObject>

class IToolContext;

class ToolContextObject : public QObject {
Q_OBJECT

public:
    explicit ToolContextObject(IToolContext *self);

public slots:
    void setToolUnit(const QString &name);

private:
    IToolContext *self;
};

class IToolContext {
    friend class ToolContextObject;

protected:
    virtual void setToolUnit(const QString &name) = 0;
};


#endif //IMAGEEDITOR_TOOLCONTEXTOBJECT_H
