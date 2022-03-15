#ifndef IMAGEEDITOR_TOOL_H
#define IMAGEEDITOR_TOOL_H

#include "../MainWidgets/toolbar.h"
#include "../MainWidgets/tooldock.h"
#include "toolview.h"
#include "toolcore.h"

#include <QHash>
#include <QString>

class Tool : QObject {
Q_OBJECT

public:
    explicit Tool(QString name, ToolView *view, ToolCore *core);
    [[nodiscard]] QString toString() const;

    void addToolToBar(ToolBar *bar);
    void updateToolDock(ToolDock *dock);

private slots:
    void toolTriggeredEvent() const;

private:
    const QString name;
    ToolView *view;
    ToolCore *core;
};

inline bool operator==(const Tool &s1, const Tool &s2)
{
    return s1.toString() == s2.toString();
}

inline uint qHash(const Tool &key, uint seed)
{
    return qHash(key.toString(), seed);
}

#endif //IMAGEEDITOR_TOOL_H
