#include "lineparametersinterface.h"
#include "../figurecategory.h"

#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QColorDialog>

LineParametersInterface::LineParametersInterface(const QString &name, QObject *parent, QWidget *widget)
        : ParametersInterface(parent, line), ToolUnitView(name, widget),
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

void LineParametersInterface::update() {
    updateLine();
    updateThickness();
}

void LineParametersInterface::updateLine() {
    colorPicker->setStyleSheet(QString("background-color: %1").arg(data->lineColor.name()));
}

void LineParametersInterface::updateThickness() {
    thicknessSlider->setValue(data->thickness);
}

void LineParametersInterface::pickColor() {
    setColor(QColorDialog::getColor(data->lineColor, nullptr, tr("Line color")));
}

void LineParametersInterface::setColor(const QColor& newColor) {
    if (newColor.isValid()) {
        data->lineColor = newColor;
        updateLine();
        dataUpdated();
    }
}

void LineParametersInterface::onThicknessChanged(int value) {
    thicknessSlider->setToolTip(QString::number(value));
    data->thickness = value;
    dataUpdated();
}

void LineParametersInterface::createColorPicker(const QString &name, QPushButton *colorPickerButton) {
    addWidget(new QLabel(name));

    auto colorPickerWidget = new QWidget();
    auto layout = new QHBoxLayout(colorPickerWidget);
    colorPickerWidget->setLayout(layout);
    layout->addWidget(colorPickerButton);
    addWidget(colorPickerWidget);
}
