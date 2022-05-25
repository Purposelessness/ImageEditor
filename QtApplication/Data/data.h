#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-equals-delete"

#ifndef IMAGEEDITOR_WIDGETDATA_H
#define IMAGEEDITOR_WIDGETDATA_H


#include <QObject>

class IGraphicsView;
class IToolDock;
class IToolBar;
class ToolService;
class QGraphicsPixmapItem;
class EditorWindow;

class Data : public QObject {
Q_OBJECT

public:
    static Data &getInstance();

    void setToolService(ToolService *toolService);
    ToolService *getToolService();

    static QGraphicsPixmapItem *getPixmapItem();

private:
    Data() = default;
    Data(const Data &root) = delete;
    Data &operator=(const Data &) = delete;

    ToolService *toolService = nullptr;
};

class WidgetData : public QObject {
Q_OBJECT

public:
    static WidgetData &getInstance();

    void setEditorWindow(EditorWindow *window);
    EditorWindow *getEditorWindow();

    void setGraphicsView(IGraphicsView *graphicsView);
    IGraphicsView *getGraphicsView();

    void setToolDock(IToolDock *toolDock);
    IToolDock *getToolDock();

    void setTooBar(IToolBar *toolBar);
    IToolBar *getToolBar();

signals:
    void editorWindowUpdated();
    void graphicsViewUpdated();
    void toolDockUpdated();
    void toolBarUpdated();

private:
    WidgetData() = default;
    WidgetData(const WidgetData &root) = delete;
    WidgetData &operator=(const WidgetData &) = delete;

    EditorWindow *editorWindow = nullptr;
    IGraphicsView *graphicsView = nullptr;
    IToolDock *toolDock = nullptr;
    IToolBar *toolBar = nullptr;
};


#endif //IMAGEEDITOR_WIDGETDATA_H