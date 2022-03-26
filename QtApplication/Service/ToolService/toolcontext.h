#ifndef IMAGEEDITOR_TOOLCONTEXT_H
#define IMAGEEDITOR_TOOLCONTEXT_H

#include <QObject>
#include <QHash>

#include "toolunit.h"

class ToolContext : public QObject {
Q_OBJECT

public:
    virtual void setTool(const QString& name);
    virtual void addTool(ToolUnit *toolUnit);
    ToolUnit *getCurrentTool();
    IToolModel *getCurrentToolModel();

protected:
    QHash<QString, ToolUnit *> tools;

protected slots:
    virtual void onToolTriggered(const QString& name);
    virtual void onToolChanged() = 0;
    virtual void onToolWidgetEnabled(bool value) = 0;

private:
    void updateToolModel();

    ToolUnit *currentTool;
    IToolModel *currentToolModel;
};


#endif //IMAGEEDITOR_TOOLCONTEXT_H
