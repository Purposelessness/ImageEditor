#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H


#include "Generics/toolcontext.h"
#include "ToolCategory/toolcategory.h"
#include "../../MainWidgets/ToolBar/itoolbar.h"
#include "../../MainWidgets/ToolDock/itooldock.h"

class ToolService : QObject, ToolContext<ToolCategory> {
Q_OBJECT

public:
    static ToolService &getInstance();

    void addCategory(ToolCategory *category);
    ToolCategory *getCategory();
    Tool *getTool();

    void setToolBar(IToolBar *toolBar);
    void setToolDock(IToolDock *toolDock);
    void setGraphicsView(IGraphicsView *graphicsView);

public slots:
    void setCategory(const QString &name);

private slots:
    void updateToolDock();

protected:
    void setToolUnit(const QString &name) override;

private:
    ToolService();
    ToolService(const ToolService &root) = delete;
    ToolService &operator=(const ToolService &) = delete;

    void addToolToBar(ToolUnit *tool);

    IToolBar *toolBar = nullptr;
    IToolDock *toolDock = nullptr;
    IGraphicsView *graphicsView;
};


#endif //IMAGEEDITOR_TOOLSERVICE_H