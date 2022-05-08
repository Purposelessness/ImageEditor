#ifndef IMAGEEDITOR_COMMANDCONTROLLER_H
#define IMAGEEDITOR_COMMANDCONTROLLER_H


#include <QObject>

class Command;
class IImage;
struct CommandInformation;
struct CommandFigureData;
struct CommandLineData;
struct CommandColorInverterData;
struct CommandCropData;
struct Rgb;

enum class ExitCode {
    unknown,
    invalid,
    success,
    fail
};

class CommandController : public QObject {
Q_OBJECT

public:
    explicit CommandController(QString srcFileName, QString destFileName, QVector<Command *> commands);

public slots:
    void start();
    void terminate();

signals:
    void finished(ExitCode code = ExitCode::unknown);

private:
    static ExitCode processImage(IImage *image, const CommandInformation &info);

    static void drawEllipse(IImage *image, const CommandFigureData &data);
    static void drawTriangle(IImage *image, const CommandFigureData &data);
    static void drawLine(IImage *image, const CommandLineData &data);
    static void invertColorsInEllipse(IImage *image, const CommandColorInverterData &data);
    static void cropImage(IImage *image, const CommandCropData &data);
    static Rgb convertQColorToRgb(const QColor &color);

    QString srcFileName, destFileName;
    QVector<Command *> commands;
};


#endif //IMAGEEDITOR_COMMANDCONTROLLER_H
