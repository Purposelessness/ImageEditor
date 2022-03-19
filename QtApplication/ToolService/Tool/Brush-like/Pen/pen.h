#ifndef IMAGEEDITOR_PEN_H
#define IMAGEEDITOR_PEN_H

#include "../../tool.h"
#include "penmodel.h"

class Pen : public Tool {
public:
    explicit Pen(const QString& name = "Pen");
};


#endif //IMAGEEDITOR_PEN_H
