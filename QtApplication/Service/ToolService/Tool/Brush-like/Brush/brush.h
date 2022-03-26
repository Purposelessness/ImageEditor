#ifndef IMAGEEDITOR_BRUSH_H
#define IMAGEEDITOR_BRUSH_H

#include "../../tool.h"
#include "brushview.h"
#include "brushmodel.h"

class Brush : public Tool {
public:
    explicit Brush(const QString& name = "Brush");
};


#endif //IMAGEEDITOR_BRUSH_H
