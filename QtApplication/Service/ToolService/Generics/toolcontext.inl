template<typename T>
void ToolContext<T>::addToolUnit(T *toolUnit) {
    Context<T>::addState(toolUnit->toString(), toolUnit);
    QObject::connect(toolUnit, SIGNAL(triggered(QString)), object, SLOT(setToolUnit(QString)));
}

template<typename T>
void ToolContext<T>::setToolUnit(const QString &name) {
    Context<T>::setState(name);
}
