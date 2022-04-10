#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H


#include "Generics/toolcontext.h"
#include "ToolCategory/toolcategory.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "../../MainWidgets/ToolDock/itooldock.h"

class IToolService;

class ToolServiceObject : public QObject {
Q_OBJECT

public:
    explicit ToolServiceObject(IToolService *self);

public slots:
    void setCategory(const QString &name);
    void updateToolDock();

private:
    IToolService *self;
};

class IToolService {
    friend class ToolServiceObject;

protected:
    virtual void setCategory(const QString &name) = 0;
    virtual void updateToolDock() = 0;
};

class ToolService : ToolContext<ToolCategory>, IToolService {
public:
    static ToolService &getInstance();

    void addCategory(ToolCategory *category);
    void setCategory(const QString &name) override;
    ToolCategory *getCategory();
    Tool *getTool();

    void setToolBar(IToolBar *toolBar);
    void setToolDock(IToolDock *toolDock);

private:
    ToolService();
    ToolService(const ToolService &root) = delete;
    ToolService &operator=(const ToolService &) = delete;

    void addToolToBar(ToolUnit *tool);
    void updateToolDock() override;

    IToolBar *toolBar = nullptr;
    IToolDock *toolDock = nullptr;

    ToolServiceObject *object = new ToolServiceObject(this);
};


#endif //IMAGEEDITOR_TOOLSERVICE_H