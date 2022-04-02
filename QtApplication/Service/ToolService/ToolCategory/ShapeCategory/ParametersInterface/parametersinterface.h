#ifndef IMAGEEDITOR_PARAMETERSINTERFACE_H
#define IMAGEEDITOR_PARAMETERSINTERFACE_H

#include "../../../toolunitview.h"

struct FigureData {
    QColor fillColor {QColor(Qt::green)};
    QColor lineColor {QColor(Qt::black)};
    int thickness {10};
};

class ParametersInterface : public QObject {
Q_OBJECT

public:
    explicit ParametersInterface(QObject *parent = nullptr);

protected:
    FigureData figureData;

signals:
    void update(FigureData *data);
};


#endif //IMAGEEDITOR_PARAMETERSINTERFACE_H
