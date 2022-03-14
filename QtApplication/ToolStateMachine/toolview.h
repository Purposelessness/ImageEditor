#ifndef IMAGEEDITOR_TOOLVIEW_H
#define IMAGEEDITOR_TOOLVIEW_H

#include <QAction>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include <QPixmap>

class ToolView {
public:
    explicit ToolView(const QString& name);
    explicit ToolView(const QPixmap& pixmap, const QString& name);

    QAction *getAction();
    QWidget *getWidget();

protected:
    void addSection(QWidget *section);
    void addSection(const QString& sectionLabel, QWidget *section);

private:
    void setActionIcon(const QPixmap& pixmap);

    QAction *action;
    QVBoxLayout *layout;
    QGroupBox *settingsBox;
};


#endif //IMAGEEDITOR_TOOLVIEW_H
