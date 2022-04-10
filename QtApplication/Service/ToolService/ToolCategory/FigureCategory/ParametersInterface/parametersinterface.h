#ifndef IMAGEEDITOR_PARAMETERSINTERFACE_H
#define IMAGEEDITOR_PARAMETERSINTERFACE_H

#include "../../../Generics/toolunitview.h"
#include "../../../Tool/Figure/figure.h"

struct Data {
    QColor fillColor = QColor(0, 168, 243);
    QColor lineColor = Qt::black;
    int thickness = 10;
    bool fillEnabled = true;
    bool lineEnabled = true;
};

class ParametersInterface : public QObject {
Q_OBJECT

public:
    explicit ParametersInterface(QObject *parent = nullptr, FigureType type = none);
    virtual void updateView() = 0;

signals:
    void update(FigureData *data);

protected:
    void dataUpdated();

    static Data data;
    static FigureData figureData;

private:
    FigureType type;
};


#endif //IMAGEEDITOR_PARAMETERSINTERFACE_H
