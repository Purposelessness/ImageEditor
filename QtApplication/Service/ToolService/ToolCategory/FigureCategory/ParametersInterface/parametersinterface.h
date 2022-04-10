#ifndef IMAGEEDITOR_PARAMETERSINTERFACE_H
#define IMAGEEDITOR_PARAMETERSINTERFACE_H


#include "../../../Generics/toolunitview.h"
#include "../../../Tool/Figure/figure.h"

struct Data;

class ParametersInterface : public QObject {
Q_OBJECT

public:
    explicit ParametersInterface(QObject *parent = nullptr, FigureType type = none);

    void setData(Data *data);
    virtual void update() = 0;

signals:
    void updated();

protected:
    void dataUpdated();
    Data *data = nullptr;

private:
    FigureType type;
};


#endif //IMAGEEDITOR_PARAMETERSINTERFACE_H
