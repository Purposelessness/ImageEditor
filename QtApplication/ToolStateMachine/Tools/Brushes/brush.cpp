#include "brush.h"

Brush::Brush(const QString& name) : Tool(name, new DefaultToolView(name), new BrushCore()) {

}