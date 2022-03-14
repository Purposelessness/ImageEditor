#ifndef IMAGEEDITOR_DEFAULTTOOLVIEW_H
#define IMAGEEDITOR_DEFAULTTOOLVIEW_H

#include "../toolview.h"

class DefaultToolView : public ToolView {
public:
    explicit DefaultToolView(const QString& name);
    explicit DefaultToolView(const QPixmap& pixmap, const QString& name);
};


#endif //IMAGEEDITOR_DEFAULTTOOLVIEW_H
