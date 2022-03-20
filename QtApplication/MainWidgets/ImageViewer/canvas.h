#ifndef IMAGEEDITOR_CANVAS_H
#define IMAGEEDITOR_CANVAS_H

#include <QWidget>
#include <QLabel>

class Canvas : public QWidget {
public:
    explicit Canvas(QWidget *parent = Q_NULLPTR);

private:
    bool loadFile(const QString &fileName);
    void setImage(const QImage &newImage);

    QImage image;
    QLabel *imageLabel;
};


#endif //IMAGEEDITOR_CANVAS_H
