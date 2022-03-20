#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QImage>
#include <QScrollArea>
#include <QGuiApplication>

class IV : public QMainWindow {
Q_OBJECT

public:
    explicit IV(QWidget *parent = Q_NULLPTR);

private slots:
    void open();
    static void saveAs();

private:
    bool loadFile(const QString &fileName);
    void setImage(const QImage &newImage);
    void createActions();
    void createMenus();

    QImage image;
    QLabel *imageLabel;
    QScrollArea *scrollArea;

    QMenu *fileMenu;

    QAction *openAct;
    QAction *saveAsAct;
};

#endif // MAINWINDOW_H
