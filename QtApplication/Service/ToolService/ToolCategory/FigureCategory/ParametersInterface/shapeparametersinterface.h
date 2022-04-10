#ifndef IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H
#define IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H


#include "../../../Generics/toolunitview.h"
#include "parametersinterface.h"

#include <QSlider>
#include <QPushButton>
#include <QToolButton>

class ShapeParametersInterface : public ParametersInterface, public ToolUnitView {
Q_OBJECT

public:
    explicit ShapeParametersInterface(const QString &name, QObject *parent = nullptr, QWidget *widget = new QWidget());

    void update() override;

private slots:
    void onNoneFillAction();
    void onSolidFillAction();
    void onNoneLineAction();
    void onSolidLineAction();
    void onThicknessChanged(int value);
    void pickFillColor();
    void pickLineColor();

private:
    void updateFillButton();
    void updateLineButton();
    void updateThicknessSlider();

    void createColorPicker(const QString &name, QPushButton *colorPickerButton, QToolButton *materialPickerButton);
    void setFillColor(const QColor &color);
    void setLineColor(const QColor &color);

    QSlider *thicknessSlider;
    QPushButton *fillColorPicker, *lineColorPicker;
    QToolButton *fillMaterialPicker, *lineMaterialPicker;

    QString noneText = tr("None"), solidText = tr("Solid");
};


#endif //IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H
