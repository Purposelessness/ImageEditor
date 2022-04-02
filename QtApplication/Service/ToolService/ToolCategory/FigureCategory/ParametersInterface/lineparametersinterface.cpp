#include "lineparametersinterface.h"

#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QColorDialog>

LineParametersInterface::LineParametersInterface(const QString &name, QObject *parent, QWidget *widget)
        : ParametersInterface(parent), ToolUnitView(name, widget),
          colorPicker(new QPushButton()),
          thicknessSlider(new QSlider()) {
    createColorPicker(tr("Line color"), colorPicker);

    connect(colorPicker, SIGNAL(pressed()), this, SLOT(pickColor()));

    addWidget(new QLabel(tr("Thickness")));
    thicknessSlider->setRange(1, 100);
    thicknessSlider->setOrientation(Qt::Horizontal);
    connect(thicknessSlider, SIGNAL(valueChanged(int)), this, SLOT(onThicknessChanged(int)));
    addWidget(thicknessSlider);
}

void LineParametersInterface::resetParameters() {
    setColor(defaultColor);
    thicknessSlider->setValue(10);
}

void LineParametersInterface::pickColor() {
    setColor(QColorDialog::getColor(figureData.lineColor, nullptr, tr("Line color")));
}

void LineParametersInterface::setColor(const QColor& newColor) {
    if (newColor == QColor())
        return;
    figureData.lineColor = newColor;
    colorPicker->setStyleSheet(QString("background-color: %1").arg(newColor.name()));
    emit update(&figureData);
}

void LineParametersInterface::onThicknessChanged(int value) {
    thicknessSlider->setToolTip(QString::number(value));
    figureData.thickness = value;
    emit update(&figureData);
}

void LineParametersInterface::createColorPicker(const QString &name, QPushButton *colorPickerButton) {
    addWidget(new QLabel(name));

    auto colorPickerWidget = new QWidget();
    auto layout = new QHBoxLayout(colorPickerWidget);
    colorPickerWidget->setLayout(layout);
    layout->addWidget(colorPickerButton);
    addWidget(colorPickerWidget);
}

QColor LineParametersInterface::getColor() const {
    return figureData.lineColor;
}

int LineParametersInterface::getThicknessValue() const {
    return figureData.thickness;
}