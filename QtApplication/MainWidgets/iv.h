#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMenu>
#include <QLabel>
#include <QImage>
#include <QScrollArea>
#include "ui_imageviewer.h"

class ImageViewer : public QMainWindow {
Q_OBJECT

public:
    explicit ImageViewer(QWidget *parent = Q_NULLPTR);

    ~ImageViewer() override;

private slots:
    void open();
    static void saveAs();

private:
    Ui::ImageViewer *ui;

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
