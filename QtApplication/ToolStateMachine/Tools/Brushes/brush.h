#ifndef IMAGEEDITOR_BRUSH_H
#define IMAGEEDITOR_BRUSH_H

#include "../../tool.h"
#include "../defaulttoolview.h"
#include "brushcore.h"

class Brush : public Tool {
public:
    explicit Brush(const QString& name = tr("Brush"));
};


#endif //IMAGEEDITOR_BRUSH_H
