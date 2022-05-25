#ifndef IMAGEEDITOR_CONTEXT_H
#define IMAGEEDITOR_CONTEXT_H


#include <QHash>

template<typename State>
class Context {
public:
    virtual void addState(const QString &name, State *state);
    virtual void setState(const QString &name);
    State *getState();

protected:
    QHash<QString, State *> states;

private:
    State *currentState;
};

#include "context.inl"


#endif //IMAGEEDITOR_CONTEXT_H
