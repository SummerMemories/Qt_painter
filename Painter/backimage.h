#ifndef BACKIMAGE_H
#define BACKIMAGE_H


#include <QWidget>
#include <QtGui>
#include <QPixmap>
#include <QPainter>
#include <QRectF>
#include <QMouseEvent>
#include <QPointF>
#include <QDragEnterEvent>
#include <QGraphicsSceneWheelEvent>
#include <QGraphicsItem>

// class ImageWidget :public QObject, QGraphicsItem
class BackImage :public QGraphicsItem
{
    //Q_OBJECT
public:
    BackImage(QPixmap *pixmap);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void wheelEvent(QGraphicsSceneWheelEvent *event);
    void ResetItemPos();
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
    void paintEvent(QPaintEvent*);
    qreal getScaleValue() const;
    void setQGraphicsViewWH(int nwidth,int nheight);
private:
    qreal m_scaleValue;
    qreal m_scaleDafault;
    QPixmap m_pix;
    int m_zoomState;
    bool m_isMove;
    QPointF m_startPos;

    QFont font;
    int judge[50];
    int ClickCount[50];
};

#endif // BACKIMAGE_H
