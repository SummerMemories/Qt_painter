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
    PositionX1 = -231.121;
    PositionX2 = 987.892;
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
    QFont font1("宋体",30,QFont::Normal,true);
    font1.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    painter->setPen(RGB(250,206,135));
    painter->setFont(font1);
    /***********************左边图纸显示文字**********************/
    if(judge[0] == 1 && ClickCount[0] % 2 == 1)
    {
        //painter->setPen(QPen(Qt::white,4,Qt::SolidLine));
        //painter->drawRoundRect(20,20,210,160,50,50);
        //painter->drawRoundRect(-280,-1710,-140,-1670,0,0);
        //painter->setPen(RGB(250,206,135));
        painter->drawText(-231.121,-1675,QString::fromLocal8Bit("直流电源"));
    }
    else if(judge[1] == 1 && ClickCount[1] % 2 == 1)
    {
        painter->drawText(PositionX1,-1646.74,QString::fromLocal8Bit("1"));
    }
    else if(judge[2] == 1 && ClickCount[2] % 2 == 1)
    {
        painter->drawText(PositionX1,-1562.11,QString::fromLocal8Bit("3"));
    }
    else if(judge[3] == 1 && ClickCount[3] % 2 == 1)
    {
        painter->drawText(PositionX1,-1515.47,QString::fromLocal8Bit("强电开入"));
    }
    else if(judge[4] == 1 && ClickCount[4] % 2 == 1)
    {
        painter->drawText(PositionX1,-1489.33,QString::fromLocal8Bit("装置电源正"));
    }
    else if(judge[5] == 1 && ClickCount[5] % 2 == 1)
    {
        painter->drawText(PositionX1,-1407.79,QString::fromLocal8Bit("变低联跳开入"));
    }
    else if(judge[6] == 1 && ClickCount[6] % 2 == 1)
    {
        painter->drawText(PositionX1,-1387.29,QString::fromLocal8Bit("变低联跳开入2"));
    }
    else if(judge[7] == 1 && ClickCount[7] % 2 == 1)
    {
        painter->drawText(PositionX1,-1341.9,QString::fromLocal8Bit("装置电源负"));
    }
    else if(judge[8] == 1 && ClickCount[8] % 2 == 1)
    {
        painter->drawText(PositionX1,-1321.4,QString::fromLocal8Bit("装置电源负"));
    }
    else if(judge[9] == 1 && ClickCount[9] % 2 == 1)
    {
        painter->drawText(PositionX1,-1273.39,QString::fromLocal8Bit("支路2出口"));
    }
    else if(judge[10] == 1 && ClickCount[10] % 2 == 1)
    {
        painter->drawText(PositionX1,-1254.16,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[11] == 1 && ClickCount[11] % 2 == 1)
    {
        painter->drawText(PositionX1,-1215.7,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[12] == 1 && ClickCount[12] % 2 == 1)
    {
        painter->drawText(PositionX1,-1187.43,QString::fromLocal8Bit("支路3出口"));
    }
    else if(judge[13] == 1 && ClickCount[13] % 2 == 1)
    {
        painter->drawText(PositionX1,-1166.07,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[14] == 1 && ClickCount[14] % 2 == 1)
    {
        painter->drawText(PositionX1,-1128.27,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[15] == 1 && ClickCount[15] % 2 == 1)
    {
        painter->drawText(PositionX1,-1106.9,QString::fromLocal8Bit("支路4出口"));
    }
    else if(judge[16] == 1 && ClickCount[16] % 2 == 1)
    {
        painter->drawText(PositionX1,-1085.54,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[17] == 1 && ClickCount[17] % 2 == 1)
    {
        painter->drawText(PositionX1,-1041.17,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[18] == 1 && ClickCount[18] % 2 == 1)
    {
        painter->drawText(PositionX1,-1012.41,QString::fromLocal8Bit("支路5出口"));
    }
    else if(judge[19] == 1 && ClickCount[19] % 2 == 1)
    {
        painter->drawText(PositionX1,-996.825,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[20] == 1 && ClickCount[20] % 2 == 1)
    {
        painter->drawText(PositionX1,-957.874,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[21] == 1 && ClickCount[21] % 2 == 1)
    {
        painter->drawText(PositionX1,-928.011,QString::fromLocal8Bit("支路6出口"));
    }
    else if(judge[22] == 1 && ClickCount[22] % 2 == 1)
    {
        painter->drawText(PositionX1,-911.132,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[23] == 1 && ClickCount[23] % 2 == 1)
    {
        painter->drawText(PositionX1,-869.584,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[24] == 1 && ClickCount[24] % 2 == 1)
    {
        painter->drawText(PositionX1,-847.511,QString::fromLocal8Bit("支路7出口"));
    }
    else if(judge[25] == 1 && ClickCount[25] % 2 == 1)
    {
        painter->drawText(PositionX1,-824.14,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[26] == 1 && ClickCount[26] % 2 == 1)
    {
        painter->drawText(PositionX1,-779.221,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[27] == 1 && ClickCount[27] % 2 == 1)
    {
        painter->drawText(PositionX1,-759.221,QString::fromLocal8Bit("支路8出口"));
    }
    else if(judge[28] == 1 && ClickCount[28] % 2 == 1)
    {
        painter->drawText(PositionX1,-737.149,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[29] == 1 && ClickCount[29] % 2 == 1)
    {
        painter->drawText(PositionX1,-699.496,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[30] == 1 && ClickCount[30] % 2 == 1)
    {
        painter->drawText(PositionX1,-672.23,QString::fromLocal8Bit("支路9出口"));
    }
    else if(judge[31] == 1 && ClickCount[31] % 2 == 1)
    {
        painter->drawText(PositionX1,-654.053,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[32] == 1 && ClickCount[32] % 2 == 1)
    {
        painter->drawText(PositionX1,-611.206,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[33] == 1 && ClickCount[33] % 2 == 1)
    {
        painter->drawText(PositionX1,-583.94,QString::fromLocal8Bit("支路10出口"));
    }
    else if(judge[34] == 1 && ClickCount[34] % 2 == 1)
    {
        painter->drawText(PositionX1,-569.658,QString::fromLocal8Bit("跳闸+"));
    }
    else if(judge[35] == 1 && ClickCount[35] % 2 == 1)
    {
        painter->drawText(PositionX1,-525.513,QString::fromLocal8Bit("跳闸-"));
    }
    else if(judge[36] == 1 && ClickCount[36] % 2 == 1)
    {
        painter->drawText(PositionX1,-499.545,QString::fromLocal8Bit("备用端子"));
    }


    /***********************右边图纸显示文字**********************/
    else if(judge[37] == 1 && ClickCount[37] % 2 == 1)
    {
        painter->drawText(PositionX2,-1671.56,QString::fromLocal8Bit("交流电压"));
    }
    else if(judge[38] == 1 && ClickCount[38] % 2 == 1)
    {
        painter->drawText(PositionX2,-1651,QString::fromLocal8Bit("UA空开前"));
    }
    else if(judge[39] == 1 && ClickCount[39] % 2 == 1)
    {
        painter->drawText(PositionX2,-1629.72,QString::fromLocal8Bit("UB"));
    }
    else if(judge[40] == 1 && ClickCount[40] % 2 == 1)
    {
        painter->drawText(PositionX2,-1606.14,QString::fromLocal8Bit("UC"));
    }
    else if(judge[41] == 1 && ClickCount[41] % 2 == 1)
    {
        painter->drawText(PositionX2,-1564.41,QString::fromLocal8Bit("UN"));
    }
    else if(judge[42] == 1 && ClickCount[42] % 2 == 1)
    {
        painter->drawText(PositionX2,-1522.25,QString::fromLocal8Bit("UA空开后"));
    }
    else if(judge[43] == 1 && ClickCount[43] % 2 == 1)
    {
        painter->drawText(PositionX2,-1501.14,QString::fromLocal8Bit("UB"));
    }
    else if(judge[44] == 1 && ClickCount[44] % 2 == 1)
    {
        painter->drawText(PositionX2,-1478.38,QString::fromLocal8Bit("UC"));
    }

}

void BackImage::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button()== Qt::LeftButton)
    {
        m_startPos = event->pos();//鼠标左击时，获取当前鼠标在图片中的坐标，
        qDebug()<< event->pos().x();
        qDebug()<< event->pos().y();

        /**********************左边图纸点击事件定位******************/
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
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1511.58 && event->pos().y() <= -1491.18)
        {
            judge[4] = 1;
            ClickCount[4]++;
            update();
        }

        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1425.51 && event->pos().y() <= -1405.43)
        {
            judge[5] = 1;
            ClickCount[5]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1404.581 && event->pos().y() <= -1384.58)
        {
            judge[6] = 1;
            ClickCount[6]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1361.11 && event->pos().y() <= -1341.11)
        {
            judge[7] = 1;
            ClickCount[7]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1339.46 && event->pos().y() <= -1319.46)
        {
            judge[8] = 1;
            ClickCount[8]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1295.77 && event->pos().y() <= -1275.77)
        {
            judge[9] = 1;
            ClickCount[9]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1273.4 && event->pos().y() <= -1253.4)
        {
            judge[10] = 1;
            ClickCount[10]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1229.7 && event->pos().y() <= -1209.7)
        {
            judge[11] = 1;
            ClickCount[11]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1209.23 && event->pos().y() <= -1189.23)
        {
            judge[12] = 1;
            ClickCount[12]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1186.4 && event->pos().y() <= -1166.4)
        {
            judge[13] = 1;
            ClickCount[13]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1145.71 && event->pos().y() <= -1125.71)
        {
            judge[14] = 1;
            ClickCount[14]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1123.64 && event->pos().y() <= -1103.64)
        {
            judge[15] = 1;
            ClickCount[15]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1102.89 && event->pos().y() <= -1082.89)
        {
            judge[16] = 1;
            ClickCount[16]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1059.63 && event->pos().y() <= -1039.63)
        {
            judge[17] = 1;
            ClickCount[17]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1038 && event->pos().y() <= -1018)
        {
            judge[18] = 1;
            ClickCount[18]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -1017.26 && event->pos().y() <= -997.26)
        {
            judge[19] = 1;
            ClickCount[19]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -974 && event->pos().y() <= -954)
        {
            judge[20] = 1;
            ClickCount[20]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -952.991 && event->pos().y() <= -932.991)
        {
            judge[21] = 1;
            ClickCount[21]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -931.188 && event->pos().y() <= -911.188)
        {
            judge[22] = 1;
            ClickCount[22]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -888.377 && event->pos().y() <= -868.377)
        {
            judge[23] = 1;
            ClickCount[23]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -866.67 && event->pos().y() <= -846.67)
        {
            judge[24] = 1;
            ClickCount[24]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -845.137 && event->pos().y() <= -825.137)
        {
            judge[25] = 1;
            ClickCount[25]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -802 && event->pos().y() <= -782)
        {
            judge[26] = 1;
            ClickCount[26]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -780 && event->pos().y() <= -760)
        {
            judge[27] = 1;
            ClickCount[27]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -759.683 && event->pos().y() <= -739.683)
        {
            judge[28] = 1;
            ClickCount[28]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -715.943 && event->pos().y() <= -695.943)
        {
            judge[29] = 1;
            ClickCount[29]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -694.29 && event->pos().y() <= -674.29)
        {
            judge[30] = 1;
            ClickCount[30]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -673.286 && event->pos().y() <= -653.286)
        {
            judge[31] = 1;
            ClickCount[31]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -629.33 && event->pos().y() <= -609.33)
        {
            judge[32] = 1;
            ClickCount[32]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -608.109 && event->pos().y() <= -588.109)
        {
            judge[33] = 1;
            ClickCount[33]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -587.106 && event->pos().y() <= -567.106)
        {
            judge[34] = 1;
            ClickCount[34]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -542.716 && event->pos().y() <= -522.716)
        {
            judge[35] = 1;
            ClickCount[35]++;
            update();
        }
        if(event->pos().x()>=-377 && event->pos().x()<=-316 && event->pos().y()>= -521.28 && event->pos().y() <= -501.28)
        {
            judge[36] = 1;
            ClickCount[36]++;
            update();
        }




        /**********************右边图纸点击事件定位******************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -1693.72 && event->pos().y() <= -1670.72)
        {
            judge[37] = 1;
            ClickCount[37]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1669.41 && event->pos().y() <= -1650.41)
        {
            judge[38] = 1;
            ClickCount[38]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1648.43 && event->pos().y() <= -1628.43)
        {
            judge[39] = 1;
            ClickCount[39]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1627.08 && event->pos().y() <= -1607.08)
        {
            judge[40] = 1;
            ClickCount[40]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1583.67 && event->pos().y() <= -1563.67)
        {
            judge[41] = 1;
            ClickCount[41]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1541.31 && event->pos().y() <= -1521.31)
        {
            judge[42] = 1;
            ClickCount[42]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1520.12 && event->pos().y() <= -1500.12)
        {
            judge[43] = 1;
            ClickCount[43]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1498.4 && event->pos().y() <= -1478.4)
        {
            judge[44] = 1;
            ClickCount[44]++;
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

