#ifndef IMAGEEDITOR_MARQUEEOBJECT_H
#define IMAGEEDITOR_MARQUEEOBJECT_H


#include <QObject>
#include <QPainterPath>

class MarqueeModelObject;

class IMarquee {
public:
    virtual void marqueePaintedEvent(const QRectF &rect) = 0;
};

class MarqueeObject : public QObject {
Q_OBJECT

public:
explicit MarqueeObject(IMarquee *base, MarqueeModelObject *model, QObject *parent = nullptr);

private slots:
    void onMarqueePainted(const QRectF &rect);

private:
    IMarquee *base;
    MarqueeModelObject *model;
};

class MarqueeModelObject : public QObject {
Q_OBJECT

signals:
    void marqueePainted(const QRectF &rect);
};


#endif //IMAGEEDITOR_MARQUEEOBJECT_H
