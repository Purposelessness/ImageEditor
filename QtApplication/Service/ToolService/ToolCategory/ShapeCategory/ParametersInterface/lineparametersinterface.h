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

    [[nodiscard]] QColor getColor() const;
    [[nodiscard]] int getThicknessValue() const;
    void resetParameters();

private slots:
    void onThicknessChanged(int value);
    void pickColor();

private:
    void createColorPicker(const QString &name, QPushButton *colorPickerButton);
    void setColor(const QColor &newColor);

    QSlider *thicknessSlider;
    QPushButton *colorPicker;
    QColor defaultColor = QColor(Qt::black);
};


#endif //IMAGEEDITOR_LINEPARAMETERSINTERFACE_H
