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
    PositionX1 = -231;
    PositionX2 = 987;
    for(int i = 0; i < 150; i++)
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
    QFont font1("宋体",30,100);
    font1.setLetterSpacing(QFont::AbsoluteSpacing, 5);
    painter->setPen(Qt::black);
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
    if(judge[1] == 1 && ClickCount[1] % 2 == 1)
    {
        painter->drawText(PositionX1,-1646,QString::fromLocal8Bit("1"));
    }
    if(judge[2] == 1 && ClickCount[2] % 2 == 1)
    {
        painter->drawText(PositionX1,-1562,QString::fromLocal8Bit("3"));
    }
    if(judge[3] == 1 && ClickCount[3] % 2 == 1)
    {
        painter->drawText(PositionX1,-1515,QString::fromLocal8Bit("强电开入"));
    }
    if(judge[4] == 1 && ClickCount[4] % 2 == 1)
    {
        painter->drawText(PositionX1,-1489,QString::fromLocal8Bit("装置电源正"));
    }
    else if(judge[5] == 1 && ClickCount[5] % 2 == 1)
    {
        painter->drawText(PositionX1,-1407,QString::fromLocal8Bit("变低联跳开入"));
    }
    if(judge[6] == 1 && ClickCount[6] % 2 == 1)
    {
        painter->drawText(PositionX1,-1387.29,QString::fromLocal8Bit("变低联跳开入2"));
    }
    if(judge[7] == 1 && ClickCount[7] % 2 == 1)
    {
        painter->drawText(PositionX1,-1341,QString::fromLocal8Bit("装置电源负"));
    }
    if(judge[8] == 1 && ClickCount[8] % 2 == 1)
    {
        painter->drawText(PositionX1,-1321,QString::fromLocal8Bit("装置电源负"));
    }
    if(judge[9] == 1 && ClickCount[9] % 2 == 1)
    {
        painter->drawText(PositionX1,-1273,QString::fromLocal8Bit("支路2出口"));
    }
    if(judge[10] == 1 && ClickCount[10] % 2 == 1)
    {
        painter->drawText(PositionX1,-1254,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[11] == 1 && ClickCount[11] % 2 == 1)
    {
        painter->drawText(PositionX1,-1215,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[12] == 1 && ClickCount[12] % 2 == 1)
    {
        painter->drawText(PositionX1,-1187,QString::fromLocal8Bit("支路3出口"));
    }
    if(judge[13] == 1 && ClickCount[13] % 2 == 1)
    {
        painter->drawText(PositionX1,-1166.07,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[14] == 1 && ClickCount[14] % 2 == 1)
    {
        painter->drawText(PositionX1,-1128,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[15] == 1 && ClickCount[15] % 2 == 1)
    {
        painter->drawText(PositionX1,-1106,QString::fromLocal8Bit("支路4出口"));
    }
    if(judge[16] == 1 && ClickCount[16] % 2 == 1)
    {
        painter->drawText(PositionX1,-1085,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[17] == 1 && ClickCount[17] % 2 == 1)
    {
        painter->drawText(PositionX1,-1041,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[18] == 1 && ClickCount[18] % 2 == 1)
    {
        painter->drawText(PositionX1,-1012,QString::fromLocal8Bit("支路5出口"));
    }
    if(judge[19] == 1 && ClickCount[19] % 2 == 1)
    {
        painter->drawText(PositionX1,-996,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[20] == 1 && ClickCount[20] % 2 == 1)
    {
        painter->drawText(PositionX1,-957,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[21] == 1 && ClickCount[21] % 2 == 1)
    {
        painter->drawText(PositionX1,-928,QString::fromLocal8Bit("支路6出口"));
    }
    if(judge[22] == 1 && ClickCount[22] % 2 == 1)
    {
        painter->drawText(PositionX1,-911,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[23] == 1 && ClickCount[23] % 2 == 1)
    {
        painter->drawText(PositionX1,-869,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[24] == 1 && ClickCount[24] % 2 == 1)
    {
        painter->drawText(PositionX1,-847,QString::fromLocal8Bit("支路7出口"));
    }
    if(judge[25] == 1 && ClickCount[25] % 2 == 1)
    {
        painter->drawText(PositionX1,-824,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[26] == 1 && ClickCount[26] % 2 == 1)
    {
        painter->drawText(PositionX1,-779,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[27] == 1 && ClickCount[27] % 2 == 1)
    {
        painter->drawText(PositionX1,-759,QString::fromLocal8Bit("支路8出口"));
    }
    if(judge[28] == 1 && ClickCount[28] % 2 == 1)
    {
        painter->drawText(PositionX1,-737,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[29] == 1 && ClickCount[29] % 2 == 1)
    {
        painter->drawText(PositionX1,-699,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[30] == 1 && ClickCount[30] % 2 == 1)
    {
        painter->drawText(PositionX1,-672,QString::fromLocal8Bit("支路9出口"));
    }
    if(judge[31] == 1 && ClickCount[31] % 2 == 1)
    {
        painter->drawText(PositionX1,-654,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[32] == 1 && ClickCount[32] % 2 == 1)
    {
        painter->drawText(PositionX1,-611,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[33] == 1 && ClickCount[33] % 2 == 1)
    {
        painter->drawText(PositionX1,-583,QString::fromLocal8Bit("支路10出口"));
    }
    if(judge[34] == 1 && ClickCount[34] % 2 == 1)
    {
        painter->drawText(PositionX1,-569,QString::fromLocal8Bit("跳闸+"));
    }
    if(judge[35] == 1 && ClickCount[35] % 2 == 1)
    {
        painter->drawText(PositionX1,-525,QString::fromLocal8Bit("跳闸-"));
    }
    if(judge[36] == 1 && ClickCount[36] % 2 == 1)
    {
        painter->drawText(PositionX1,-499,QString::fromLocal8Bit("备用端子"));
    }


    /***********************右边图纸显示文字**********************/

    if(judge[37] == 1 && ClickCount[37] % 2 == 1)
    {
        painter->drawText(PositionX2,-1671,QString::fromLocal8Bit("交流电压"));
    }
    if(judge[38] == 1 && ClickCount[38] % 2 == 1)
    {
        painter->drawText(PositionX2,-1651,QString::fromLocal8Bit("UA空开前"));
    }
    if(judge[39] == 1 && ClickCount[39] % 2 == 1)
    {
        painter->drawText(PositionX2,-1629,QString::fromLocal8Bit("UB"));
    }
    if(judge[40] == 1 && ClickCount[40] % 2 == 1)
    {
        painter->drawText(PositionX2,-1606,QString::fromLocal8Bit("UC"));
    }
    if(judge[41] == 1 && ClickCount[41] % 2 == 1)
    {
        painter->drawText(PositionX2,-1564,QString::fromLocal8Bit("UN"));
    }
    if(judge[42] == 1 && ClickCount[42] % 2 == 1)
    {
        painter->drawText(PositionX2,-1522,QString::fromLocal8Bit("UA空开后"));
    }
    if(judge[43] == 1 && ClickCount[43] % 2 == 1)
    {
        painter->drawText(PositionX2,-1501,QString::fromLocal8Bit("UB"));
    }
    if(judge[44] == 1 && ClickCount[44] % 2 == 1)
    {
        painter->drawText(PositionX2,-1478,QString::fromLocal8Bit("UC"));
    }


    if(judge[45] == 1 && ClickCount[45] % 2 == 1)
    {
        painter->drawText(PositionX2,-1450,QString::fromLocal8Bit("支路2交流电流"));
    }
    if(judge[46] == 1 && ClickCount[46] % 2 == 1)
    {
        painter->drawText(PositionX2,-1430,QString::fromLocal8Bit("IA"));
    }
    if(judge[47] == 1 && ClickCount[47] % 2 == 1)
    {
        painter->drawText(PositionX2,-1410,QString::fromLocal8Bit("IB"));
    }
    if(judge[48] == 1 && ClickCount[48] % 2 == 1)
    {
        painter->drawText(PositionX2,-1390,QString::fromLocal8Bit("IC"));
    }
    if(judge[49] == 1 && ClickCount[49] % 2 == 1)
    {
        painter->drawText(PositionX2,-1370,QString::fromLocal8Bit("IA'"));
    }
    if(judge[50] == 1 && ClickCount[50] % 2 == 1)
    {
        painter->drawText(PositionX2,-1345,QString::fromLocal8Bit("IB'"));
    }
    if(judge[51] == 1 && ClickCount[51] % 2 == 1)
    {
        painter->drawText(PositionX2,-1325,QString::fromLocal8Bit("IC'"));
    }


    if(judge[52] == 1 && ClickCount[52] % 2 == 1)
    {
        painter->drawText(PositionX2,-1305,QString::fromLocal8Bit("支路3交流电流"));
    }
    if(judge[53] == 1 && ClickCount[53] % 2 == 1)
    {
        painter->drawText(PositionX2,-1280,QString::fromLocal8Bit("IA"));
    }
    if(judge[54] == 1 && ClickCount[54] % 2 == 1)
    {
        painter->drawText(PositionX2,-1260,QString::fromLocal8Bit("IB"));
    }
    if(judge[55] == 1 && ClickCount[55] % 2 == 1)
    {
        painter->drawText(PositionX2,-1230,QString::fromLocal8Bit("IC"));
    }
    if(judge[56] == 1 && ClickCount[56] % 2 == 1)
    {
        painter->drawText(PositionX2,-1210,QString::fromLocal8Bit("IA' "));
    }
    if(judge[57] == 1 && ClickCount[57] % 2 == 1)
    {
        painter->drawText(PositionX2,-1200,QString::fromLocal8Bit("IB' "));
    }
    if(judge[58] == 1 && ClickCount[58] % 2 == 1)
    {
        painter->drawText(PositionX2,-1175,QString::fromLocal8Bit("IC' "));
    }





    if(judge[59] == 1 && ClickCount[59] % 2 == 1)
    {
        painter->drawText(PositionX2,-95,QString::fromLocal8Bit("中央信号"));
    }
    if(judge[60] == 1 && ClickCount[60] % 2 == 1)
    {
        painter->drawText(PositionX2,-78,QString::fromLocal8Bit("+XM"));
    }
    if(judge[61] == 1 && ClickCount[61] % 2 == 1)
    {
        painter->drawText(PositionX2,34,QString::fromLocal8Bit("母线差动动作"));
    }
    if(judge[62] == 1 && ClickCount[62] % 2 == 1)
    {
        painter->drawText(PositionX2,55,QString::fromLocal8Bit("CT/PT短线警告"));
    }
    if(judge[63] == 1 && ClickCount[63] % 2 == 1)
    {
        painter->drawText(PositionX2,75,QString::fromLocal8Bit("隔离开关位置警告"));
    }
    if(judge[64] == 1 && ClickCount[64] % 2 == 1)
    {
        painter->drawText(PositionX2,95,QString::fromLocal8Bit("运行异常警告"));
    }
    if(judge[65] == 1 && ClickCount[65] % 2 == 1)
    {
        painter->drawText(PositionX2,119,QString::fromLocal8Bit("装置故障警告"));
    }
    if(judge[66] == 1 && ClickCount[66] % 2 == 1)
    {
        painter->drawText(PositionX2,139,QString::fromLocal8Bit("装置故障警告"));
    }


    if(judge[67] == 1 && ClickCount[67] % 2 == 1)
    {
        painter->drawText(PositionX2,499,QString::fromLocal8Bit("遥信"));
    }
    if(judge[68] == 1 && ClickCount[68] % 2 == 1)
    {
        painter->drawText(PositionX2,515,QString::fromLocal8Bit("公共端"));
    }
    if(judge[69] == 1 && ClickCount[69] % 2 == 1)
    {
        painter->drawText(PositionX2,632,QString::fromLocal8Bit("母线差动动作"));
    }
    if(judge[70] == 1 && ClickCount[70] % 2 == 1)
    {
        painter->drawText(PositionX2,649,QString::fromLocal8Bit("CT/PT断线警告"));
    }
    if(judge[71] == 1 && ClickCount[71] % 2 == 1)
    {
        painter->drawText(PositionX2,689,QString::fromLocal8Bit("运行异常警告"));
    }
    if(judge[72] == 1 && ClickCount[72] % 2 == 1)
    {
        painter->drawText(PositionX2,715,QString::fromLocal8Bit("装置故障警告"));
    }
    if(judge[73] == 1 && ClickCount[73] % 2 == 1)
    {
        painter->drawText(PositionX2,735,QString::fromLocal8Bit("装置故障警告"));
    }
    if(judge[74] == 1 && ClickCount[74] % 2 == 1)
    {
        painter->drawText(PositionX2,755,QString::fromLocal8Bit("直流1消0"));
    }
    if(judge[75] == 1 && ClickCount[75] % 2 == 1)
    {
        painter->drawText(PositionX2,775,QString::fromLocal8Bit("直流2消0"));
    }


    if(judge[76] == 1 && ClickCount[76] % 2 == 1)
    {
        painter->drawText(PositionX2,199,QString::fromLocal8Bit("遥信"));
    }
    if(judge[77] == 1 && ClickCount[77] % 2 == 1)
    {
        painter->drawText(PositionX2,215,QString::fromLocal8Bit("公共端"));
    }
    if(judge[78] == 1 && ClickCount[78] % 2 == 1)
    {
        painter->drawText(PositionX2,326,QString::fromLocal8Bit("母线差动动作"));
    }
    if(judge[79] == 1 && ClickCount[79] % 2 == 1)
    {
        painter->drawText(PositionX2,349,QString::fromLocal8Bit("CT/PT断线警告"));
    }
    if(judge[80] == 1 && ClickCount[80] % 2 == 1)
    {
        painter->drawText(PositionX2,389,QString::fromLocal8Bit("运行异常警告"));
    }
    if(judge[81] == 1 && ClickCount[81] % 2 == 1)
    {
        painter->drawText(PositionX2,415,QString::fromLocal8Bit("装置故障警告"));
    }
    if(judge[82] == 1 && ClickCount[82] % 2 == 1)
    {
        painter->drawText(PositionX2,435,QString::fromLocal8Bit("装置故障警告"));
    }
    if(judge[83] == 1 && ClickCount[83] % 2 == 1)
    {
        painter->drawText(PositionX2,455,QString::fromLocal8Bit("直流1消0"));
    }
    if(judge[84] == 1 && ClickCount[84] % 2 == 1)
    {
        painter->drawText(PositionX2,475,QString::fromLocal8Bit("直流2消0"));
    }


    if(judge[85] == 1 && ClickCount[85] % 2 == 1)
    {
        painter->drawText(PositionX2,802,QString::fromLocal8Bit("录波"));
    }
    if(judge[86] == 1 && ClickCount[86] % 2 == 1)
    {
        painter->drawText(PositionX2,826,QString::fromLocal8Bit("公共端"));
    }
    if(judge[87] == 1 && ClickCount[87] % 2 == 1)
    {
        painter->drawText(PositionX2,888,QString::fromLocal8Bit("母线差动动作"));
    }


    if(judge[88] == 1 && ClickCount[88] % 2 == 1)
    {
        painter->drawText(PositionX2,909,QString::fromLocal8Bit("监控通信"));
    }
    if(judge[89] == 1 && ClickCount[89] % 2 == 1)
    {
        painter->drawText(PositionX2,927,QString::fromLocal8Bit("打印发"));
    }
    if(judge[90] == 1 && ClickCount[90] % 2 == 1)
    {
        painter->drawText(PositionX2,950,QString::fromLocal8Bit("打印收"));
    }
    if(judge[91] == 1 && ClickCount[91] % 2 == 1)
    {
        painter->drawText(PositionX2,978,QString::fromLocal8Bit("打印地"));
    }
    if(judge[92] == 1 && ClickCount[92] % 2 == 1)
    {
        painter->drawText(PositionX2,1014,QString::fromLocal8Bit("485-1A"));
    }
    if(judge[93] == 1 && ClickCount[93] % 2 == 1)
    {
        painter->drawText(PositionX2,1036,QString::fromLocal8Bit("485-1B"));
    }
    if(judge[94] == 1 && ClickCount[94] % 2 == 1)
    {
        painter->drawText(PositionX2,1122,QString::fromLocal8Bit("B码对时+"));
    }
    if(judge[95] == 1 && ClickCount[95] % 2 == 1)
    {
        painter->drawText(PositionX2,1162,QString::fromLocal8Bit("B码对时-"));
    }

    if(judge[96] == 1 && ClickCount[96] % 2 == 1)
    {
        painter->drawText(PositionX2,1185,QString::fromLocal8Bit("交流电源"));
    }
    if(judge[97] == 1 && ClickCount[97] % 2 == 1)
    {
        painter->drawText(PositionX2,1206,QString::fromLocal8Bit("~220V火线"));
    }
    if(judge[98] == 1 && ClickCount[98] % 2 == 1)
    {
        painter->drawText(PositionX2,1275,QString::fromLocal8Bit("~220V零线"));
    }
    if(judge[99] == 1 && ClickCount[99] % 2 == 1)
    {
        painter->drawText(PositionX2,1336,QString::fromLocal8Bit("接地"));
    }


    if(judge[100] == 1 && ClickCount[100] % 2 == 1)
    {
        painter->drawText(PositionX2,1377,QString::fromLocal8Bit("备用端子"));
    }


    if(judge[101] == 1 && ClickCount[101] % 2 == 1)
    {
        painter->drawText(PositionX2,-1155,QString::fromLocal8Bit("支路4交流电流"));
    }
    if(judge[102] == 1 && ClickCount[102] % 2 == 1)
    {
        painter->drawText(PositionX2,-1133,QString::fromLocal8Bit("IA"));
    }
    if(judge[103] == 1 && ClickCount[103] % 2 == 1)
    {
        painter->drawText(PositionX2,-1110,QString::fromLocal8Bit("IB"));
    }
    if(judge[104] == 1 && ClickCount[104] % 2 == 1)
    {
        painter->drawText(PositionX2,-1088,QString::fromLocal8Bit("IC"));
    }
    if(judge[105] == 1 && ClickCount[105] % 2 == 1)
    {
        painter->drawText(PositionX2,-1065,QString::fromLocal8Bit("IA'"));
    }
    if(judge[106] == 1 && ClickCount[106] % 2 == 1)
    {
        painter->drawText(PositionX2,-1045,QString::fromLocal8Bit("IB'"));
    }
    if(judge[107] == 1 && ClickCount[107] % 2 == 1)
    {
        painter->drawText(PositionX2,-1023,QString::fromLocal8Bit("IC'"));
    }


    if(judge[108] == 1 && ClickCount[108] % 2 == 1)
    {
        painter->drawText(PositionX2,-1001,QString::fromLocal8Bit("支路5交流电流"));
    }
    if(judge[109] == 1 && ClickCount[109] % 2 == 1)
    {
        painter->drawText(PositionX2,-981,QString::fromLocal8Bit("IA"));
    }
    if(judge[110] == 1 && ClickCount[110] % 2 == 1)
    {
        painter->drawText(PositionX2,-961,QString::fromLocal8Bit("IB"));
    }
    if(judge[111] == 1 && ClickCount[111] % 2 == 1)
    {
        painter->drawText(PositionX2,-935,QString::fromLocal8Bit("IC"));
    }
    if(judge[112] == 1 && ClickCount[112] % 2 == 1)
    {
        painter->drawText(PositionX2,-916,QString::fromLocal8Bit("IA'"));
    }
    if(judge[113] == 1 && ClickCount[113] % 2 == 1)
    {
        painter->drawText(PositionX2,-894,QString::fromLocal8Bit("IB'"));
    }
    if(judge[114] == 1 && ClickCount[114] % 2 == 1)
    {
        painter->drawText(PositionX2,-874,QString::fromLocal8Bit("IC'"));
    }


    if(judge[115] == 1 && ClickCount[115] % 2 == 1)
    {
        painter->drawText(PositionX2,-852,QString::fromLocal8Bit("支路6交流电流"));
    }
    if(judge[116] == 1 && ClickCount[116] % 2 == 1)
    {
        painter->drawText(PositionX2,-832,QString::fromLocal8Bit("IA"));
    }
    if(judge[117] == 1 && ClickCount[117] % 2 == 1)
    {
        painter->drawText(PositionX2,-810,QString::fromLocal8Bit("IB"));
    }
    if(judge[118] == 1 && ClickCount[118] % 2 == 1)
    {
        painter->drawText(PositionX2,-788,QString::fromLocal8Bit("IC"));
    }
    if(judge[119] == 1 && ClickCount[119] % 2 == 1)
    {
        painter->drawText(PositionX2,-766,QString::fromLocal8Bit("IA'"));
    }
    if(judge[120] == 1 && ClickCount[120] % 2 == 1)
    {
        painter->drawText(PositionX2,-746,QString::fromLocal8Bit("IB'"));
    }
    if(judge[121] == 1 && ClickCount[121] % 2 == 1)
    {
        painter->drawText(PositionX2,-724,QString::fromLocal8Bit("IC'"));
    }

    if(judge[122] == 1 && ClickCount[122] % 2 == 1)
    {
        painter->drawText(PositionX2,-701,QString::fromLocal8Bit("支路7交流电流"));
    }
    if(judge[123] == 1 && ClickCount[123] % 2 == 1)
    {
        painter->drawText(PositionX2,-681,QString::fromLocal8Bit("IA"));
    }
    if(judge[124] == 1 && ClickCount[124] % 2 == 1)
    {
        painter->drawText(PositionX2,-660,QString::fromLocal8Bit("IB"));
    }
    if(judge[125] == 1 && ClickCount[125] % 2 == 1)
    {
        painter->drawText(PositionX2,-638,QString::fromLocal8Bit("IC"));
    }
    if(judge[126] == 1 && ClickCount[126] % 2 == 1)
    {
        painter->drawText(PositionX2,-618,QString::fromLocal8Bit("IA'"));
    }
    if(judge[127] == 1 && ClickCount[127] % 2 == 1)
    {
        painter->drawText(PositionX2,-598,QString::fromLocal8Bit("IB'"));
    }
    if(judge[128] == 1 && ClickCount[128] % 2 == 1)
    {
        painter->drawText(PositionX2,-578,QString::fromLocal8Bit("IC'"));
    }


    if(judge[129] == 1 && ClickCount[129] % 2 == 1)
    {
        painter->drawText(PositionX2,-552,QString::fromLocal8Bit("支路8交流电流"));
    }
    if(judge[130] == 1 && ClickCount[130] % 2 == 1)
    {
        painter->drawText(PositionX2,-532,QString::fromLocal8Bit("IA"));
    }
    if(judge[131] == 1 && ClickCount[131] % 2 == 1)
    {
        painter->drawText(PositionX2,-510,QString::fromLocal8Bit("IB"));
    }
    if(judge[132] == 1 && ClickCount[132] % 2 == 1)
    {
        painter->drawText(PositionX2,-488,QString::fromLocal8Bit("IC"));
    }
    if(judge[133] == 1 && ClickCount[133] % 2 == 1)
    {
        painter->drawText(PositionX2,-466,QString::fromLocal8Bit("IA'"));
    }
    if(judge[134] == 1 && ClickCount[134] % 2 == 1)
    {
        painter->drawText(PositionX2,-445,QString::fromLocal8Bit("IB'"));
    }
    if(judge[135] == 1 && ClickCount[135] % 2 == 1)
    {
        painter->drawText(PositionX2,-424,QString::fromLocal8Bit("IC'"));
    }

    if(judge[136] == 1 && ClickCount[136] % 2 == 1)
    {
        painter->drawText(PositionX2,-401,QString::fromLocal8Bit("支路9交流电流"));
    }
    if(judge[137] == 1 && ClickCount[137] % 2 == 1)
    {
        painter->drawText(PositionX2,-381,QString::fromLocal8Bit("IA"));
    }
    if(judge[138] == 1 && ClickCount[138] % 2 == 1)
    {
        painter->drawText(PositionX2,-359,QString::fromLocal8Bit("IB"));
    }
    if(judge[139] == 1 && ClickCount[139] % 2 == 1)
    {
        painter->drawText(PositionX2,-339,QString::fromLocal8Bit("IC"));
    }
    if(judge[140] == 1 && ClickCount[140] % 2 == 1)
    {
        painter->drawText(PositionX2,-318,QString::fromLocal8Bit("IA'"));
    }
    if(judge[141] == 1 && ClickCount[141] % 2 == 1)
    {
        painter->drawText(PositionX2,-297,QString::fromLocal8Bit("IB'"));
    }
    if(judge[142] == 1 && ClickCount[142] % 2 == 1)
    {
        painter->drawText(PositionX2,-277,QString::fromLocal8Bit("IC'"));
    }

    if(judge[143] == 1 && ClickCount[143] % 2 == 1)
    {
        painter->drawText(PositionX2,-251,QString::fromLocal8Bit("支路10交流电流"));
    }
    if(judge[144] == 1 && ClickCount[144] % 2 == 1)
    {
        painter->drawText(PositionX2,-231,QString::fromLocal8Bit("IA"));
    }
    if(judge[145] == 1 && ClickCount[145] % 2 == 1)
    {
        painter->drawText(PositionX2,-210,QString::fromLocal8Bit("IB"));
    }
    if(judge[146] == 1 && ClickCount[146] % 2 == 1)
    {
        painter->drawText(PositionX2,-189,QString::fromLocal8Bit("IC"));
    }
    if(judge[147] == 1 && ClickCount[147] % 2 == 1)
    {
        painter->drawText(PositionX2,-167,QString::fromLocal8Bit("IA'"));
    }
    if(judge[148] == 1 && ClickCount[148] % 2 == 1)
    {
        painter->drawText(PositionX2,-147,QString::fromLocal8Bit("IB'"));
    }
    if(judge[149] == 1 && ClickCount[149] % 2 == 1)
    {
        painter->drawText(PositionX2,-126,QString::fromLocal8Bit("IC'"));
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


        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -1476.49 && event->pos().y() <= -1456.49)
        {
            judge[45] = 1;
            ClickCount[45]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1455.2 && event->pos().y() <= -1435.2)
        {
            judge[46] = 1;
            ClickCount[46]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1434.71 && event->pos().y() <= -1413.71)
        {
            judge[47] = 1;
            ClickCount[47]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1412.85 && event->pos().y() <= -1392.85)
        {
            judge[48] = 1;
            ClickCount[48]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1392 && event->pos().y() <= -1371.73)
        {
            judge[49] = 1;
            ClickCount[49]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1369.41 && event->pos().y() <= -1350.01)
        {
            judge[50] = 1;
            ClickCount[50]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1348.85 && event->pos().y() <= -1328.85)
        {
            judge[51] = 1;
            ClickCount[51]++;
            update();
        }


        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -1326.8 && event->pos().y() <= -1306.14)
        {
            judge[52] = 1;
            ClickCount[52]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1305.32 && event->pos().y() <= -1285.84)
        {
            judge[53] = 1;
            ClickCount[53]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1284.26 && event->pos().y() <= -1264.26)
        {
            judge[54] = 1;
            ClickCount[54]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1262.41 && event->pos().y() <= -1242.41)
        {
            judge[55] = 1;
            ClickCount[55]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1241.61 && event->pos().y() <= -1221.61)
        {
            judge[56] = 1;
            ClickCount[56]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1220.02 && event->pos().y() <= -1200.02)
        {
            judge[57] = 1;
            ClickCount[57]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1198.43 && event->pos().y() <= -1178.43)
        {
            judge[58] = 1;
            ClickCount[58]++;
            update();
        }





        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= -125.673 && event->pos().y() <= -105.354)
        {
            judge[59] = 1;
            ClickCount[59]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= -103.835 && event->pos().y() <= -84.1954)
        {
            judge[60] = 1;
            ClickCount[60]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 2.6543 && event->pos().y() <= 24.7851)
        {
            judge[61] = 1;
            ClickCount[61]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 24.7311 && event->pos().y() <= 44.703)
        {
            judge[62] = 1;
            ClickCount[62]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 46.4915 && event->pos().y() <= 66.1653)
        {
            judge[63] = 1;
            ClickCount[63]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 67.0596 && event->pos().y() <= 87.6276)
        {
            judge[64] = 1;
            ClickCount[64]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 88.9189 && event->pos().y() <= 108.108)
        {
            judge[65] = 1;
            ClickCount[65]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 110.121 && event->pos().y() <= 130.121)
        {
            judge[66] = 1;
            ClickCount[66]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 475.121 && event->pos().y() <= 494.121)
        {
            judge[67] = 1;
            ClickCount[67]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 495.121 && event->pos().y() <= 516.121)
        {
            judge[68] = 1;
            ClickCount[68]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 604.121 && event->pos().y() <= 624.121)
        {
            judge[69] = 1;
            ClickCount[69]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 625.121 && event->pos().y() <= 645.121)
        {
            judge[70] = 1;
            ClickCount[70]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 669.121 && event->pos().y() <= 689.121)
        {
            judge[71] = 1;
            ClickCount[71]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 690.121 && event->pos().y() <= 709.121)
        {
            judge[72] = 1;
            ClickCount[72]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 711.121 && event->pos().y() <= 731.121)
        {
            judge[73] = 1;
            ClickCount[73]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 733.121 && event->pos().y() <= 753.121)
        {
            judge[74] = 1;
            ClickCount[74]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 755.121 && event->pos().y() <= 775.121)
        {
            judge[75] = 1;
            ClickCount[75]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 174.121 && event->pos().y() <= 194.121)
        {
            judge[76] = 1;
            ClickCount[76]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 196.121 && event->pos().y() <= 216.121)
        {
            judge[77] = 1;
            ClickCount[77]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 302.121 && event->pos().y() <= 322.121)
        {
            judge[78] = 1;
            ClickCount[78]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 324.121 && event->pos().y() <= 344.121)
        {
            judge[79] = 1;
            ClickCount[79]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 367.121 && event->pos().y() <= 387.121)
        {
            judge[80] = 1;
            ClickCount[80]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 389.121 && event->pos().y() <= 409.121)
        {
            judge[81] = 1;
            ClickCount[81]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 411.121 && event->pos().y() <= 431.121)
        {
            judge[82] = 1;
            ClickCount[82]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 433.121 && event->pos().y() <= 453.121)
        {
            judge[83] = 1;
            ClickCount[83]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 455.121 && event->pos().y() <= 475.121)
        {
            judge[84] = 1;
            ClickCount[84]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 776.121 && event->pos().y() <= 796.121)
        {
            judge[85] = 1;
            ClickCount[85]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 798.121 && event->pos().y() <= 818.121)
        {
            judge[86] = 1;
            ClickCount[86]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 861.121 && event->pos().y() <= 881.121)
        {
            judge[87] = 1;
            ClickCount[87]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 885.121 && event->pos().y() <= 905.121)
        {
            judge[88] = 1;
            ClickCount[88]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 907.121 && event->pos().y() <= 927.121)
        {
            judge[89] = 1;
            ClickCount[89]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 927.121 && event->pos().y() <= 947.121)
        {
            judge[90] = 1;
            ClickCount[90]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 949.121 && event->pos().y() <= 969.121)
        {
            judge[91] = 1;
            ClickCount[91]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 992.121 && event->pos().y() <= 1012.121)
        {
            judge[92] = 1;
            ClickCount[92]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1014.121 && event->pos().y() <= 1034.121)
        {
            judge[93] = 1;
            ClickCount[93]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1098.121 && event->pos().y() <= 1118.121)
        {
            judge[94] = 1;
            ClickCount[94]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1141.121 && event->pos().y() <= 1161.121)
        {
            judge[95] = 1;
            ClickCount[95]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 1162.121 && event->pos().y() <= 1182.121)
        {
            judge[96] = 1;
            ClickCount[96]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1183.121 && event->pos().y() <= 1203.121)
        {
            judge[97] = 1;
            ClickCount[97]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1247.121 && event->pos().y() <= 1267.121)
        {
            judge[98] = 1;
            ClickCount[98]++;
            update();
        }
        if(event->pos().x()>=812 && event->pos().x()<=873 && event->pos().y()>= 1312.121 && event->pos().y() <= 1332.121)
        {
            judge[99] = 1;
            ClickCount[99]++;
            update();
        }


        if(event->pos().x()>=789 && event->pos().x()<=898 && event->pos().y()>= 1355.121 && event->pos().y() <= 1375.121)
        {
            judge[100] = 1;
            ClickCount[100]++;
            update();
        }

        /*************************支路4**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -1176.8 && event->pos().y() <= -1156.14)
        {
            judge[101] = 1;
            ClickCount[101]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1154.32 && event->pos().y() <= -1134.84)
        {
            judge[102] = 1;
            ClickCount[102]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1133.26 && event->pos().y() <= -1113.26)
        {
            judge[103] = 1;
            ClickCount[103]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1112.41 && event->pos().y() <= -1092.41)
        {
            judge[104] = 1;
            ClickCount[104]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1090.61 && event->pos().y() <= -1070.61)
        {
            judge[105] = 1;
            ClickCount[105]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1069.02 && event->pos().y() <= -1049.02)
        {
            judge[106] = 1;
            ClickCount[106]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1048.43 && event->pos().y() <= -1027.43)
        {
            judge[107] = 1;
            ClickCount[107]++;
            update();
        }

        /*************************支路5**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -1024.8 && event->pos().y() <= -1004.14)
        {
            judge[108] = 1;
            ClickCount[108]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -1003.32 && event->pos().y() <= -983.84)
        {
            judge[109] = 1;
            ClickCount[109]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -982.26 && event->pos().y() <= -962.26)
        {
            judge[110] = 1;
            ClickCount[110]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -960.41 && event->pos().y() <= -940.41)
        {
            judge[111] = 1;
            ClickCount[111]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -939.61 && event->pos().y() <= -919.61)
        {
            judge[112] = 1;
            ClickCount[112]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -917.02 && event->pos().y() <= -897.02)
        {
            judge[113] = 1;
            ClickCount[113]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -896.43 && event->pos().y() <= -876.43)
        {
            judge[114] = 1;
            ClickCount[114]++;
            update();
        }

        /*************************支路6**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -874.8 && event->pos().y() <= -854.14)
        {
            judge[115] = 1;
            ClickCount[115]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -853.32 && event->pos().y() <= -833.84)
        {
            judge[116] = 1;
            ClickCount[116]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -832.26 && event->pos().y() <= -812.26)
        {
            judge[117] = 1;
            ClickCount[117]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -811.41 && event->pos().y() <= -791.41)
        {
            judge[118] = 1;
            ClickCount[118]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -789.61 && event->pos().y() <= -769.61)
        {
            judge[119] = 1;
            ClickCount[119]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -767.02 && event->pos().y() <= -747.02)
        {
            judge[120] = 1;
            ClickCount[120]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -746.43 && event->pos().y() <= -726.43)
        {
            judge[121] = 1;
            ClickCount[121]++;
            update();
        }

        /*************************支路7**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -724.8 && event->pos().y() <= -704.14)
        {
            judge[122] = 1;
            ClickCount[122]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -703.32 && event->pos().y() <= -683.84)
        {
            judge[123] = 1;
            ClickCount[123]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -682.26 && event->pos().y() <= -662.26)
        {
            judge[124] = 1;
            ClickCount[124]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -661.41 && event->pos().y() <= -641.41)
        {
            judge[125] = 1;
            ClickCount[125]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -639.61 && event->pos().y() <= -619.61)
        {
            judge[126] = 1;
            ClickCount[126]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -617.02 && event->pos().y() <= -597.02)
        {
            judge[127] = 1;
            ClickCount[127]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -597.43 && event->pos().y() <= -577.43)
        {
            judge[128] = 1;
            ClickCount[128]++;
            update();
        }

        /*************************支路8**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -575.8 && event->pos().y() <= -555.14)
        {
            judge[129] = 1;
            ClickCount[129]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -553.32 && event->pos().y() <= -533.84)
        {
            judge[130] = 1;
            ClickCount[130]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -532.26 && event->pos().y() <= -512.26)
        {
            judge[131] = 1;
            ClickCount[131]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -511.41 && event->pos().y() <= -491.41)
        {
            judge[132] = 1;
            ClickCount[132]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -489.61 && event->pos().y() <= -469.61)
        {
            judge[133] = 1;
            ClickCount[133]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -467.02 && event->pos().y() <= -447.02)
        {
            judge[134] = 1;
            ClickCount[134]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -446.43 && event->pos().y() <= -426.43)
        {
            judge[135] = 1;
            ClickCount[135]++;
            update();
        }




        /*************************支路9**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -423.8 && event->pos().y() <= -403.14)
        {
            judge[136] = 1;
            ClickCount[136]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -402.32 && event->pos().y() <= -382.84)
        {
            judge[137] = 1;
            ClickCount[137]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -381.26 && event->pos().y() <= -361.26)
        {
            judge[138] = 1;
            ClickCount[138]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -360.41 && event->pos().y() <= -340.41)
        {
            judge[139] = 1;
            ClickCount[139]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -338.61 && event->pos().y() <= -318.61)
        {
            judge[140] = 1;
            ClickCount[140]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -317.02 && event->pos().y() <= -297.02)
        {
            judge[141] = 1;
            ClickCount[141]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -296.43 && event->pos().y() <= -276.43)
        {
            judge[142] = 1;
            ClickCount[142]++;
            update();
        }

        /*************************支路10**************************/
        if(event->pos().x()>=787 && event->pos().x()<=898 && event->pos().y()>= -274.8 && event->pos().y() <= -254.14)
        {
            judge[143] = 1;
            ClickCount[143]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -253.32 && event->pos().y() <= -233.84)
        {
            judge[144] = 1;
            ClickCount[144]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -231.26 && event->pos().y() <= -211.26)
        {
            judge[145] = 1;
            ClickCount[145]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -211.41 && event->pos().y() <= -191.41)
        {
            judge[146] = 1;
            ClickCount[146]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -189.61 && event->pos().y() <= -169.61)
        {
            judge[147] = 1;
            ClickCount[147]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -168.02 && event->pos().y() <= -148.02)
        {
            judge[148] = 1;
            ClickCount[148]++;
            update();
        }
        if(event->pos().x()>=822 && event->pos().x()<=865 && event->pos().y()>= -146.43 && event->pos().y() <= -126.43)
        {
            judge[149] = 1;
            ClickCount[149]++;
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

