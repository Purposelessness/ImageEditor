#ifndef IMAGEEDITOR_OUTLINER_H
#define IMAGEEDITOR_OUTLINER_H


#include "../../tool.h"

class Outliner : public Tool {
Q_OBJECT

public:
    Outliner();

public slots:
    void use();

private:
    void editImage(QImage *image, int width, const QColor &color, const QColor &destColor);
};


#endif //IMAGEEDITOR_OUTLINER_H
