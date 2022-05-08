#ifndef IMAGEEDITOR_COMMANDCONTROLLER_H
#define IMAGEEDITOR_COMMANDCONTROLLER_H


#include <QObject>

class ICommand;
class IImage;
struct CommandInformation;
struct FigureData;
struct LineData;
struct ColorInverterData;
struct CropData;
struct Rgb;

enum ExitCode {
    unknown,
    invalid,
    success,
    fail
};

class CommandController : public QObject {
Q_OBJECT

public slots:
    explicit CommandController(QString srcFileName, QString destFileName, QVector<ICommand *> commands);

    void start();
    void terminate();

signals:
    void finished(ExitCode code = unknown);

private:
    static ExitCode processImage(IImage *image, const CommandInformation &info);

    static void drawEllipse(IImage *image, const FigureData &data);
    static void drawTriangle(IImage *image, const FigureData &data);
    static void drawLine(IImage *image, const LineData &data);
    static void invertColorsInEllipse(IImage *image, const ColorInverterData &data);
    static void cropImage(IImage *image, const CropData &data);
    static Rgb convertQColorToRgb(const QColor &color);

    QString srcFileName, destFileName;
    QVector<ICommand *> commands;
};


#endif //IMAGEEDITOR_COMMANDCONTROLLER_H
