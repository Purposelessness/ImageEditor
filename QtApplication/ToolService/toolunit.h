#ifndef IMAGEEDITOR_TOOLUNIT_H
#define IMAGEEDITOR_TOOLUNIT_H

#include <QObject>
#include <QAction>
#include <QWidget>

#include "Tool/itoolmodel.h"

class ToolUnit : public QObject {
Q_OBJECT

public:
    explicit ToolUnit(QString name);

signals:
    void toolTriggered(const QString &name);
    void toolChanged();
    void toolWidgetEnabled(bool value);

public:
    virtual QAction *getAction() = 0;
    virtual QWidget *getWidget() = 0;
    virtual IToolModel *getToolModel() = 0;
    void setActive(bool value);
    [[nodiscard]] QString toString() const;

private:
    QString name;
    bool enabled;
};

inline bool operator==(const ToolUnit &s1, const ToolUnit &s2)
{
    return s1.toString() == s2.toString();
}

inline uint qHash(const ToolUnit &key, uint seed)
{
    return qHash(key.toString(), seed);
}

#endif //IMAGEEDITOR_TOOLUNIT_H
