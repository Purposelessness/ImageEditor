#ifndef IMAGEEDITOR_PARAMETERSINTERFACE_H
#define IMAGEEDITOR_PARAMETERSINTERFACE_H


#include "../../../Generics/toolunitview.h"
#include "../../../Tool/Figure/figure.h"

class ParametersInterface : public QObject {
Q_OBJECT

public:
    explicit ParametersInterface(QObject *parent = nullptr, FigureType type = FigureType::none);

    void setData(FigureData *data);
    virtual void update() = 0;

signals:
    void updated();

protected:
    void dataUpdated();
    FigureData *data = nullptr;

private:
    FigureType type;
};


#endif //IMAGEEDITOR_PARAMETERSINTERFACE_H
