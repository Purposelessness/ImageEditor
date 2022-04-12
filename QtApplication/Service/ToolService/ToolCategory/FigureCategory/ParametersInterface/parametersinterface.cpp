#include "parametersinterface.h"
#include "../figurecategory.h"

ParametersInterface::ParametersInterface(QObject *parent, FigureType newType) : QObject(parent), type(newType) {}

void ParametersInterface::setData(Data *newData) {
    data = newData;
    qDebug() << data->fillColor;
    update();
}

void ParametersInterface::dataUpdated() {
    if (type == none)
        return;
    emit updated();
}
