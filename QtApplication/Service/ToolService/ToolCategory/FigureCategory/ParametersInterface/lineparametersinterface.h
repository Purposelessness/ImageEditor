#ifndef IMAGEEDITOR_LINEPARAMETERSINTERFACE_H
#define IMAGEEDITOR_LINEPARAMETERSINTERFACE_H

#include "parametersinterface.h"

#include <QSlider>
#include <QPushButton>
#include <QToolButton>

class LineParametersInterface : public ParametersInterface, public ToolUnitView {
Q_OBJECT

public:
    explicit LineParametersInterface(const QString &name, QObject *parent = nullptr, QWidget *widget = new QWidget());

    void updateView() override;

private slots:
    void onThicknessChanged(int value);
    void pickColor();

private:
    void updateLine();
    void updateThickness();

    void createColorPicker(const QString &name, QPushButton *colorPickerButton);
    void setColor(const QColor &newColor);

    QSlider *thicknessSlider;
    QPushButton *colorPicker;
};


#endif //IMAGEEDITOR_LINEPARAMETERSINTERFACE_H
