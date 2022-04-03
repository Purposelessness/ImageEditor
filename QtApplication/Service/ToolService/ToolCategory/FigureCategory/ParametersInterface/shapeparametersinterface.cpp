#include "shapeparametersinterface.h"

#include <QLabel>
#include <QAction>
#include <QMenu>
#include <QColorDialog>

ShapeParametersInterface::ShapeParametersInterface(const QString &name, QObject *parent, QWidget *widget)
        : ParametersInterface(parent), ToolUnitView(name, widget),
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
    figureData.fillColor = QColor();
    figureData.lineColor = QColor();
    onNoneFillAction();
    onSolidLineAction();
    thicknessSlider->setValue(10);
}

void ShapeParametersInterface::pickFillColor() {
    setFillColor(QColorDialog::getColor(figureData.fillColor, nullptr, tr("Fill color")));
}

void ShapeParametersInterface::pickLineColor() {
    setLineColor(QColorDialog::getColor(figureData.lineColor, nullptr, tr("Line color")));
}

void ShapeParametersInterface::setFillColor(const QColor& color) {
    qDebug() << "Setting fill color to" << color;
    if (figureData.fillColor != QColor())
        prevFillColor = figureData.fillColor;
    figureData.fillColor = color;
    if (color.isValid()) {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(color.name()));
        fillMaterialPicker->setText(tr("Solid"));
    } else {
        fillColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        fillMaterialPicker->setText(tr("None"));
    }
    emit update(&figureData);
}

void ShapeParametersInterface::setLineColor(const QColor& color) {
    if (figureData.lineColor != QColor())
        prevLineColor = figureData.lineColor;
    figureData.lineColor = color;
    if (color.isValid()) {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(color.name()));
        lineMaterialPicker->setText(tr("Solid"));
    } else {
        lineColorPicker->setStyleSheet(QString("background-color: %1").arg(QColor(Qt::lightGray).name()));
        lineMaterialPicker->setText(tr("None"));
    }
    emit update(&figureData);
}

void ShapeParametersInterface::onNoneFillAction() {
    fillMaterialPicker->setText(tr("None"));
    setFillColor(QColor());
}

void ShapeParametersInterface::onSolidFillAction() {
    if (figureData.fillColor.isValid())
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
    if (figureData.lineColor.isValid()) {
        return;
    }
    lineMaterialPicker->setText(tr("Solid"));
    if (prevLineColor.isValid()) {
        setLineColor(prevLineColor);
    } else {
        setLineColor(defaultLineColor);
    }
}

void ShapeParametersInterface::onThicknessChanged(int value) {
    thicknessSlider->setToolTip(QString::number(value));
    figureData.thickness = value;
    emit update(&figureData);
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
    return figureData.fillColor;
}

QColor ShapeParametersInterface::getLineColor() const {
    return figureData.lineColor;
}

int ShapeParametersInterface::getThicknessValue() const {
    return figureData.thickness;
}