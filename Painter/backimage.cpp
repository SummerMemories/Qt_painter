#include "backimage.h"
#include "ui_widget.h"
#include <QDebug>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>
#include <QGraphicsSceneDragDropEvent>
#include <QDrag>
#include <QDebug>
#include <QLabel>
#include <math.h>

BackImage::BackImage(QPixmap *pixmap)
{
    m_pix = *pixmap;
    setAcceptDrops(true);//If enabled is true, this item will accept hover events; otherwise, it will ignore them. By default, items do not accept hover events.
    setAcceptHoverEvents(true);
    m_scaleValue = 0;
    m_scaleDafault = 0;
    m_isMove = false;
    for(int i = 0; i < 50; i++)
    {
        judge[i] = 0;
        ClickCount[i] = 0;
    }
}

QRectF BackImage::boundingRect() const
{
    return QRectF(-m_pix.width() / 2, -m_pix.height() / 2,
                  m_pix.width(), m_pix.height());
}

void BackImage::paint(QPainter *painter, const QStyleOptionGraphicsItem *,
                    QWidget *)
{
    painter->drawPixmap(-m_pix.width() / 2, -m_pix.height() / 2, m_pix);
    QFont font1("宋体",20,QFont::Normal,true);
    font1.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    painter->setPen(RGB(250,206,135));
    painter->setFont(font1);
    if(judge[0] == 1 && ClickCount[0] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-293,-1675,QString::fromLocal8Bit("直流电源"));
    }
    else if(judge[1] == 1 && ClickCount[1] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-231.121,-1646.74,QString::fromLocal8Bit("1DK-1"));
    }
    else if(judge[2] == 1 && ClickCount[2] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-236.828,-1562.11,QString::fromLocal8Bit("1DK-3"));
    }
    else if(judge[3] == 1 && ClickCount[3] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("强电开入"));
    }
    else if(judge[4] == 1 && ClickCount[4] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("装置电源正"));
    }
    else if(judge[5] == 1 && ClickCount[5] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("变低联眺开入"));
    }
    else if(judge[6] == 1 && ClickCount[6] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("变低联眺开入2"));
    }
    else if(judge[7] == 1 && ClickCount[7] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("装置电源负"));
    }
    else if(judge[8] == 1 && ClickCount[8] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("装置电源负"));
    }
    else if(judge[9] == 1 && ClickCount[9] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("支路2出口"));
    }
    else if(judge[10] == 1 && ClickCount[10] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[11] == 1 && ClickCount[11] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[12] == 1 && ClickCount[12] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("支路3出口"));
    }
    else if(judge[13] == 1 && ClickCount[13] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[14] == 1 && ClickCount[14] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[15] == 1 && ClickCount[15] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("支路4出口"));
    }
    else if(judge[16] == 1 && ClickCount[16] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[17] == 1 && ClickCount[17] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[18] == 1 && ClickCount[18] % 2 == 0)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-233.859,-1515.47,QString::fromLocal8Bit("支路5出口"));
    }
}

void BackImage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        qDebug()<< event->pos().x();
        qDebug()<< event->pos().y();
        if(event->pos().x()>=-359 && event->pos().x()<=-323 && event->pos().y()>= -1688 && event->pos().y() <= -1665)
        {
            judge[0] = 1;
            ClickCount[0]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-312 && event->pos().y()>= -1662 && event->pos().y() <= -1645)
        {
            judge[1] = 1;
            ClickCount[1]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-312 && event->pos().y()>= -1578.5 && event->pos().y() <= -1559)
        {
            judge[2] = 1;
            ClickCount[2]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1536 && event->pos().y() <= -1514)
        {
            judge[3] = 1;
            ClickCount[3]++;
            update();
        }


        m_isMove = true;//标记鼠标左键被按下
    }
    else if(event->button() == Qt::RightButton)
    {
        ResetItemPos();//右击鼠标重置大小
    }

}

void BackImage::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if(m_isMove)
    {
        QPointF point = (event->pos() - m_startPos)*m_scaleValue;
        moveBy(point.x(), point.y());
    }
}

void BackImage::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    m_isMove = false;//标记鼠标左键已经抬起
}


void BackImage::wheelEvent(QGraphicsSceneWheelEvent *event)//鼠标滚轮事件
{
    if((event->delta() > 0)&&(m_scaleValue >= 50))//最大放大到原始图像的50倍
    {
        return;
    }
    else if((event->delta() < 0)&&(m_scaleValue <= m_scaleDafault))//图像缩小到自适应大小之后就不继续缩小
    {
        ResetItemPos();//重置图片大小和位置，使之自适应控件窗口大小
    }
    else
    {
        qreal qrealOriginScale = m_scaleValue;
        if(event->delta() > 0)//鼠标滚轮向前滚动
        {
            m_scaleValue*=1.1;//每次放大10%
        }
        else
        {
            m_scaleValue*=0.9;//每次缩小10%
        }
        setScale(m_scaleValue);
        if(event->delta() > 0)
        {
            moveBy(-event->pos().x()*qrealOriginScale*0.1, -event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
        else
        {
            moveBy(event->pos().x()*qrealOriginScale*0.1, event->pos().y()*qrealOriginScale*0.1);//使图片缩放的效果看起来像是以鼠标所在点为中心进行缩放的
        }
    }
}

void BackImage::setQGraphicsViewWH(int nwidth, int nheight)//将主界面的控件QGraphicsView的width和height传进本类中，并根据图像的长宽和控件的长宽的比例来使图片缩放到适合控件的大小
{
    int nImgWidth = m_pix.width();
    int nImgHeight = m_pix.height();
    qreal temp1 = nwidth*1.0/nImgWidth;
    qreal temp2 = nheight*1.0/nImgHeight;
    if(temp1>temp2)
    {
        m_scaleDafault = temp2;
    }
    else
    {
        m_scaleDafault = temp1;
    }
    setScale(m_scaleDafault);
    m_scaleValue = m_scaleDafault;
}

void BackImage::ResetItemPos()//重置图片位置
{
    m_scaleValue = m_scaleDafault;//缩放比例回到一开始的自适应比例
    setScale(m_scaleDafault);//缩放到一开始的自适应大小
    setPos(0,0);
}

qreal BackImage::getScaleValue() const
{
    return m_scaleValue;
}

