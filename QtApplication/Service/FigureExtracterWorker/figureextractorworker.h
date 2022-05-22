#ifndef IMAGEEDITOR_FIGUREEXTRACTORWORKER_H
#define IMAGEEDITOR_FIGUREEXTRACTORWORKER_H


#include "../../../Library/figurepoints.h"
#include <QImage>

struct TaskInput {
    TaskInput(const TaskInput &other) : srcImage(other.srcImage), points(other.points), destImage(other.destImage) {}

    TaskInput(const QImage &image, const FigurePoints &points, QImage *destImage)
            : srcImage(image), points(points), destImage(destImage) {}

    TaskInput &operator=(const TaskInput &other) noexcept {
        return *new(this) TaskInput(other.srcImage, other.points, other.destImage);
    }

    TaskInput &operator=(TaskInput &&other) noexcept {
        return *new(this) TaskInput(other.srcImage, other.points, other.destImage);
    }

    const QImage &srcImage = QImage();
    FigurePoints points;
    QImage *destImage = nullptr;
};

class FigureExtractorWorker {
public:
    static QImage start(const FigurePoints &points, const QImage &image);

private:
    static void extractFigure(const TaskInput &input);
};


#endif //IMAGEEDITOR_FIGUREEXTRACTORWORKER_H
