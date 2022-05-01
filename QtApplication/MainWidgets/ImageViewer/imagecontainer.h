#ifndef IMAGEEDITOR_IMAGECONTAINER_H
#define IMAGEEDITOR_IMAGECONTAINER_H

#include "igraphicsview.h"
#include "../../Service/Painter/painter.h"

#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QEvent>

class ImageContainer : public QGraphicsView, public IGraphicsView {
Q_OBJECT

public:
    explicit ImageContainer(QWidget *parent = nullptr);
    void setImage(const QImage &newImage);
    void scale(float newScaleValue);
    void addItem(QGraphicsItem *item) override;
    QGraphicsScene *getScene() override;
    QGraphicsPixmapItem *getPixmapItem() override;
    QPixmap grab(const QRect &rect) override;
    void focusOn(const QGraphicsItem *item) override;

signals:
    void mousePressed(const QPoint &mousePos);
    void mouseMoved(const QPoint &mousePos);
    void mouseReleased(const QPoint &mousePos);

public slots:
    void mapItemToPixmap(QGraphicsItem *item);

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private slots:
    void onSelectionChanged();

private:
    class : public QGraphicsObject {
    private:
        bool sceneEventFilter(QGraphicsItem *watched, QEvent *event) override {
            if (watched->isSelected())
                return false;

            if (event->type() == QEvent::GraphicsSceneMouseDoubleClick) {
                watched->setSelected(true);
            }
            return true;
        }
        [[nodiscard]] QRectF boundingRect() const final { return QRect(); }
        [[maybe_unused]] void paint(QPainter *qPainter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override {}
    } eventFilter;

    QGraphicsScene *scene;
    QGraphicsPixmapItem *pixmapItem = nullptr;
    QPixmap pixmap;
    QGraphicsItem *focusItem = nullptr;
    Painter painter;
    QGraphicsItem *selectedItem = nullptr;

    float scaleValue = 1;
    bool itemIsSelected = false;
};


#endif //IMAGEEDITOR_IMAGECONTAINER_H
