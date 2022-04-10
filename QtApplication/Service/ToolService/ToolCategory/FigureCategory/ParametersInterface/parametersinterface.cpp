#include "parametersinterface.h"

Data ParametersInterface::data {};
FigureData ParametersInterface::figureData {};

ParametersInterface::ParametersInterface(QObject *parent, FigureType newType) : QObject(parent), type(newType) {
    dataUpdated();
}

void ParametersInterface::dataUpdated() {
    if (type == none)
        return;

    figureData.fillColor = data.fillEnabled || type == line ? data.fillColor : QColor();
    figureData.lineColor = data.lineEnabled || type == line ? data.lineColor : QColor();
    figureData.thickness = data.thickness;
    figureData.type = type;

    qDebug() << "Updated" << data.lineColor;

    emit update(&figureData);
}
