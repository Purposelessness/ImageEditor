#ifndef IMAGEEDITOR_TOOLCATEGORYVIEW_H
#define IMAGEEDITOR_TOOLCATEGORYVIEW_H

#include "../Generics/toolunitview.h"
#include <QHBoxLayout>
#include <QGroupBox>

class ToolCategoryView : public ToolUnitView {
public:
    explicit ToolCategoryView(const QString& name);
    explicit ToolCategoryView(const QString& name, const QIcon& icon);

    void addToolAction(QAction *action);

private:
    void createWidget(const QString& name);

    QHBoxLayout *toolLayout = nullptr;
    QGroupBox *toolBox = nullptr;
};


#endif //IMAGEEDITOR_TOOLCATEGORYVIEW_H
