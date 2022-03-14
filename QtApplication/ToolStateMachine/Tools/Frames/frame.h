#ifndef IMAGEEDITOR_FRAME_H
#define IMAGEEDITOR_FRAME_H

#include "../../tool.h"
#include "../defaulttoolview.h"
#include "framecore.h"

class Frame : public Tool {
public:
    explicit Frame(const QString& name = tr("Frame"));
};


#endif //IMAGEEDITOR_FRAME_H
