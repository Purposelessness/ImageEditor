#include "shapeparametersinterface.h"

#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QColorDialog>

ShapeParametersInterface::ShapeParametersInterface(const QString &name, QObject *parent, QWidget *widget)
        : QObject(parent), ToolUnitView(name, widget),
          fillColorPicker(new QPushButton()),
          fillMaterialPicker(new QToolButton()),
          lineColorPicker(new QPushButton()),
          lineMaterialPicker(new QToolButton()),
          thicknessSlider(new QSlider()) {
    auto fillMaterialPickerMenu = new QMenu(fillMaterialPicker);
    fillMaterialPickerMenu->addAction(tr("None"), this, SLOT(onNoneFillAction()));
    fillMaterialPickerMenu->addAction(tr("Solid"), this, SLOT(onSolidFillAction()));
    fillMaterialPicker->setMenu(fillMaterialPickerMenu);
    createColorPicker(tr("Fill"), fillColorPicker, fillMaterialPicker);

    auto lineMaterialPickerMenu = new QMenu(lineMaterialPicker);
    lineMaterialPickerMenu->addAction(tr("None"), this, SLOT(onNoneLineAction()));
    lineMaterialPickerMenu->addAction(tr("Solid"), this, SLOT(onSolidLineAction()));
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

void ShapeParametersInterface::resetParameters() {
    onNoneFillAction();
    onSolidLineAction();
    thicknessSlider->setValue(10);
}

void ShapeParametersInterface::pickFillColor() {
    setFillColor(QColorDialog::getColor(fillColor, nullptr, tr("Fill color")));
}

void ShapeParametersInterface::pickLineColor() {
    setLineColor(QColorDialog::getColor(lineColor, nullptr, tr("Line color")));
}

void ShapeParametersInterface::setFillColor(const QColor& color) {
    if (fillColor != QColor())
        prevFillColor = fillColor;
    fillColor = color;
    if (color.isValid()) {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(color.name()));
        fillMaterialPicker->setText(tr("Solid"));
    } else {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        fillMaterialPicker->setText(tr("None"));
    }
    emit fillColorChanged(fillColor);
}

void ShapeParametersInterface::setLineColor(const QColor& color) {
    if (lineColor != QColor())
        prevLineColor = lineColor;
    lineColor = color;
    if (color.isValid()) {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(color.name()));
        lineMaterialPicker->setText(tr("Solid"));
    } else {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        lineMaterialPicker->setText(tr("None"));
    }
    emit lineColorChanged(lineColor);
}

void ShapeParametersInterface::onNoneFillAction() {
    fillMaterialPicker->setText(tr("None"));
    setFillColor(QColor());
}

void ShapeParametersInterface::onSolidFillAction() {
    if (fillColor.isValid())
        return;
    fillMaterialPicker->setText(tr("Solid"));
    if (prevFillColor.isValid()) {
        setFillColor(prevFillColor);
    } else {
        setFillColor(defaultFillColor);
    }
}

void ShapeParametersInterface::onNoneLineAction() {
    lineMaterialPicker->setText(tr("None"));
    setLineColor(QColor());
}

void ShapeParametersInterface::onSolidLineAction() {
    if (lineColor.isValid())
        return;
    lineMaterialPicker->setText(tr("Solid"));
    if (prevLineColor.isValid()) {
        setLineColor(prevLineColor);
    } else {
        setLineColor(defaultLineColor);
    }
}

void ShapeParametersInterface::onThicknessChanged(int value) {
    emit thicknessChanged(value);
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

QColor ShapeParametersInterface::getFillColor() const {
    return fillColor;
}

QColor ShapeParametersInterface::getLineColor() const {
    return lineColor;
}

int ShapeParametersInterface::getThicknessValue() const {
    return thickness;
}