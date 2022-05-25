#include "data.h"
#include "../MainWidgets/ImageViewer/igraphicsview.h"

Data &Data::getInstance() {
    static Data instance;
    return instance;
}

void Data::setToolService(ToolService *newToolService) {
    toolService = newToolService;
}

ToolService *Data::getToolService() {
    return toolService;
}

QGraphicsPixmapItem *Data::getPixmapItem() {
    return WidgetData::getInstance().getGraphicsView()->getPixmapItem();
}

WidgetData &WidgetData::getInstance() {
    static WidgetData instance;
    return instance;
}

void WidgetData::setGraphicsView(IGraphicsView *newGraphicsView) {
    graphicsView = newGraphicsView;
    emit graphicsViewUpdated();
}

IGraphicsView *WidgetData::getGraphicsView() {
    return graphicsView;
}

void WidgetData::setToolDock(IToolDock *newToolDock) {
    toolDock = newToolDock;
    emit toolDockUpdated();
}

IToolDock *WidgetData::getToolDock() {
    return toolDock;
}

void WidgetData::setTooBar(IToolBar *newToolBar) {
    toolBar = newToolBar;
    emit toolBarUpdated();
}

IToolBar *WidgetData::getToolBar() {
    return toolBar;
}

void WidgetData::setEditorWindow(EditorWindow *newWindow) {
    editorWindow = newWindow;
    emit editorWindowUpdated();
}

EditorWindow *WidgetData::getEditorWindow() {
    return editorWindow;
}
