#ifndef IMAGEEDITOR_COMMANDCONTROLLER_H
#define IMAGEEDITOR_COMMANDCONTROLLER_H


#include <QObject>

namespace Bitmap {
    class Image;
}
class Command;
struct CommandInformation;
struct CommandFigureData;
struct CommandLineData;
struct CommandColorInverterData;
struct CommandCropData;
struct CommandRotatorData;
struct CommandOutlinerData;
struct CommandGlueData;
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
    static ExitCode processImage(Bitmap::Image *image, const CommandInformation &info);

    static void drawEllipse(Bitmap::Image *image, CommandFigureData data);
    static void drawTriangle(Bitmap::Image *image, CommandFigureData data);
    static void drawLine(Bitmap::Image *image, CommandLineData data);
    static void invertColorsInEllipse(Bitmap::Image *image, CommandColorInverterData data);
    static void cropImage(Bitmap::Image *image, CommandCropData data);
    static void rotateTriangle(Bitmap::Image *image, CommandRotatorData data);
    static void outline(Bitmap::Image *image, CommandOutlinerData data);
    static void glue(Bitmap::Image *image, CommandGlueData data);
    static Rgb convertQColorToRgb(const QColor &color);

    QString srcFileName, destFileName;
    QVector<Command *> commands;
};


#endif //IMAGEEDITOR_COMMANDCONTROLLER_H
