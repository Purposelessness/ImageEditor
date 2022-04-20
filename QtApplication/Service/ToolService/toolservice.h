#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"
#ifndef IMAGEEDITOR_TOOLSERVICE_H
#define IMAGEEDITOR_TOOLSERVICE_H


#include "Generics/toolcontext.h"
#include "ToolCategory/toolcategory.h"

class IToolBar;
class IToolDock;

class ToolService : QObject, ToolContext<ToolCategory> {
Q_OBJECT

public:
    static ToolService &getInstance();

    void addCategory(ToolCategory *category);
    ToolCategory *getCategory();
    Tool *getTool();

public slots:
    void setCategory(const QString &name);

private slots:
    void updateToolDock();
    void updateToolBar(ToolUnit *unit = nullptr);

protected:
    void setToolUnit(const QString &name) override;

private:
    ToolService();
    ToolService(const ToolService &root) = delete;
    ToolService &operator=(const ToolService &) = delete;
};


#endif //IMAGEEDITOR_TOOLSERVICE_H