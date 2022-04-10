#include "../../logger.h"

template<typename State>
void Context<State>::addState(const QString &name, State *state) {
    if (states.contains(name))
        qInfo(stateMachine()) << "Context already contains" << name << ". Previous state was replaced";
    states.insert(name, state);
    qDebug(stateMachine()) << "State" << name << "added to hash";
}

template<typename State>
void Context<State>::setState(const QString &name) {
    if (!states.contains(name)) {
        qCritical(stateMachine()) << "State" << name << "doesn't contain in context";
        return;
    }
    currentState = states.value(name);
    qDebug(stateMachine()) << "Selected" << name << "state";
}

template<typename State>
State *Context<State>::getState() {
    return currentState;
}
