#ifndef IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H
#define IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H

#include "../../toolunitview.h"

#include <QSlider>
#include <QPushButton>
#include <QToolButton>

class ShapeParametersInterface : public QObject, public ToolUnitView {
Q_OBJECT

public:
    explicit ShapeParametersInterface(const QString& name, QObject *parent = nullptr, QWidget *widget = new QWidget());

    [[nodiscard]] QColor getFillColor() const;
    [[nodiscard]] QColor getLineColor() const;
    [[nodiscard]] int getThicknessValue() const;

signals:
    void fillColorChanged(const QColor& color);
    void lineColorChanged(const QColor& color);
    void thicknessValueChanged(const int& value);

private slots:
    void onNoneFillAction();
    void onSolidFillAction();
    void onNoneLineAction();
    void onSolidLineAction();
    void pickFillColor();
    void pickLineColor();

private:
    void createColorPicker(const QString& name, QPushButton *colorPickerButton, QToolButton *materialPickerButton);
    void setFillColor(const QColor& color);
    void setLineColor(const QColor& color);

    QSlider *thicknessSlider;
    QPushButton *fillColorPicker, *lineColorPicker;
    QToolButton *fillMaterialPicker, *lineMaterialPicker;
    QColor defaultFillColor = QColor(0, 168, 243), defaultLineColor = QColor(Qt::black);
    QColor fillColor = QColor(), prevFillColor = QColor();
    QColor lineColor = QColor(), prevLineColor = QColor();
    int thicknessValue = 1;
};


#endif //IMAGEEDITOR_SHAPEPARAMETERSINTERFACE_H
