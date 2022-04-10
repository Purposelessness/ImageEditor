#include "shapeparametersinterface.h"
#include "../figurecategory.h"

#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QColorDialog>

ShapeParametersInterface::ShapeParametersInterface(const QString &name, QObject *parent, QWidget *widget)
        : ParametersInterface(parent, shape), ToolUnitView(name, widget),
          fillColorPicker(new QPushButton()),
          fillMaterialPicker(new QToolButton()),
          lineColorPicker(new QPushButton()),
          lineMaterialPicker(new QToolButton()),
          thicknessSlider(new QSlider()) {
    auto fillMaterialPickerMenu = new QMenu(fillMaterialPicker);
    fillMaterialPickerMenu->addAction(noneText, this, SLOT(onNoneFillAction()));
    fillMaterialPickerMenu->addAction(solidText, this, SLOT(onSolidFillAction()));
    fillMaterialPicker->setMenu(fillMaterialPickerMenu);
    createColorPicker(tr("Fill"), fillColorPicker, fillMaterialPicker);

    auto lineMaterialPickerMenu = new QMenu(lineMaterialPicker);
    lineMaterialPickerMenu->addAction(noneText, this, SLOT(onNoneLineAction()));
    lineMaterialPickerMenu->addAction(solidText, this, SLOT(onSolidLineAction()));
    lineMaterialPicker->setMenu(lineMaterialPickerMenu);
    createColorPicker(tr("Line type"), lineColorPicker, lineMaterialPicker);

    connect(fillColorPicker, SIGNAL(pressed()), this, SLOT(pickFillColor()));
    connect(lineColorPicker, SIGNAL(pressed()), this, SLOT(pickLineColor()));

    addWidget(new QLabel(tr("Thickness")));
    thicknessSlider->setRange(1, 100);
    thicknessSlider->setOrientation(Qt::Horizontal);
    connect(thicknessSlider, SIGNAL(valueChanged(int)), this, SLOT(onThicknessChanged(int)));
    addWidget(thicknessSlider);
}

void ShapeParametersInterface::update() {
    updateFillButton();
    updateLineButton();
    updateThicknessSlider();
}

void ShapeParametersInterface::updateFillButton() {
    if (data->fillEnabled) {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(data->fillColor.name()));
        fillMaterialPicker->setText(solidText);
    } else {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        fillMaterialPicker->setText(noneText);
    }
}

void ShapeParametersInterface::updateLineButton() {
    if (data->lineEnabled) {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(data->lineColor.name()));
        lineMaterialPicker->setText(solidText);
    } else {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        lineMaterialPicker->setText(noneText);
    }
}

void ShapeParametersInterface::updateThicknessSlider() {
    thicknessSlider->setValue(data->thickness);
}

void ShapeParametersInterface::pickFillColor() {
    setFillColor(QColorDialog::getColor(data->fillColor, nullptr, tr("Fill color")));
}

void ShapeParametersInterface::pickLineColor() {
    setLineColor(QColorDialog::getColor(data->lineColor, nullptr, tr("Line color")));
}

void ShapeParametersInterface::setFillColor(const QColor& color) {
    if (color.isValid()) {
        data->fillEnabled = true;
        data->fillColor = color;
    } else {
        data->fillEnabled = false;
    }
    updateFillButton();
    dataUpdated();
}

void ShapeParametersInterface::setLineColor(const QColor& color) {
    if (color.isValid()) {
        data->lineEnabled = true;
        data->lineColor = color;
    } else {
        data->lineEnabled = false;
    }
    updateLineButton();
    dataUpdated();
}

void ShapeParametersInterface::onNoneFillAction() {
    data->fillEnabled = false;
    updateFillButton();
    dataUpdated();
}

void ShapeParametersInterface::onSolidFillAction() {
    data->fillEnabled = true;
    updateFillButton();
    dataUpdated();
}

void ShapeParametersInterface::onNoneLineAction() {
    data->lineEnabled = false;
    updateLineButton();
    dataUpdated();
}

void ShapeParametersInterface::onSolidLineAction() {
    data->lineEnabled = true;
    updateLineButton();
    dataUpdated();
}

void ShapeParametersInterface::onThicknessChanged(int value) {
    thicknessSlider->setToolTip(QString::number(value));
    data->thickness = value;
    dataUpdated();
}

void ShapeParametersInterface::createColorPicker(const QString& name, QPushButton *colorPickerButton, QToolButton *materialPickerButton) {
    addWidget(new QLabel(name));

    materialPickerButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
    materialPickerButton->setPopupMode(QToolButton::InstantPopup);

    auto colorPicker = new QWidget();
    auto layout = new QHBoxLayout(colorPicker);
    colorPicker->setLayout(layout);
    layout->addWidget(colorPickerButton);
    layout->addWidget(materialPickerButton);
    addWidget(colorPicker);
}
