#ifndef IMAGEEDITOR_GLUE_H
#define IMAGEEDITOR_GLUE_H


#include "../../tool.h"

class Glue : public Tool {
Q_OBJECT

public:
    Glue();

public slots:
    void use();

private:
    void editImage(QImage *image, int width, const QColor &color, const QColor &destColor);
};


#endif //IMAGEEDITOR_GLUE_H
