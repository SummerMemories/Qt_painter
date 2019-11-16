#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsRectItem>

#include <QFileDialog>
#include <QLabel>
#pragma execution_character_set("utf-8")

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    this->showMaximized();
    m_thread = new LoadImg(&img1, &img2);
    m_thread->start();
}

Widget::~Widget()
{
    m_thread->exit();
    delete ui;
}

void Widget::on_m_FontPicture_clicked()
{
    recvShowPicSignal(1,img1);
}

void Widget::on_m_BackPicture_clicked()
{
    recvShowPicSignal(2,img2);
}

void Widget::on_m_PDF1_clicked()
{
    QString filename = "file:///C:/Users/Administrator/Desktop/Qt_painter/Painter/resource/说明书.pdf";
    QDesktopServices::openUrl(QUrl::fromLocalFile(filename));

    /*
     string s = qstr.toStdString();
     QString qstr2 = QString::fromStdString(s);
    */
}

void Widget::on_m_PDF2_clicked()
{

    QString path1 = "file:///";

    std::string flag = "build";
    QString path2 = QDir::currentPath();
    std::string p = path2.toStdString();
    std::string::size_type nPos = p.find(flag);
    p = p.substr(0, nPos);
    path2 = QString::fromStdString(p);
    path2 = path2 + "Painter/resource/恒凯电子科技数据采集卡选型手册2019.pdf";
    path1 = path1 + path2;
    qDebug()<<path1;
    QString filename = "file:///C:/Users/Administrator/Desktop/Qt_painter/Painter/resource/图纸.pdf";
    QDesktopServices::openUrl(QUrl::fromLocalFile(filename));
}

void Widget::recvShowPicSignal(int num,QImage image)
{
    //The QPixmap class is an off-screen image representation that can be used as a paint device
    QPixmap ConvertPixmap=QPixmap::fromImage(image);

    //要用QGraphicsView就必须要有QGraphicsScene搭配着用
    QGraphicsScene  *qgraphicsScene = new QGraphicsScene;

    //获取界面控件Graphics View的宽度和高度
    int nwith = ui->ImageGraphic->width();
    int nheight = ui->ImageGraphic->height();

    //实例化类ImageWidget的对象m_Image，该类继承自QGraphicsItem，是自己写的类
    if(num == 1)
    {
        m_Image = new ImageWidget(&ConvertPixmap);
        //将界面控件Graphics View的width和height传进类m_Image中
        m_Image->setQGraphicsViewWH(nwith,nheight);
        //将QGraphicsItem类对象放进QGraphicsScene中
        qgraphicsScene->addItem(m_Image);
    }
    else
    {
        m_Bimage = new BackImage(&ConvertPixmap);
        m_Bimage->setQGraphicsViewWH(nwith,nheight);
        //将QGraphicsItem类对象放进QGraphicsScene中
        qgraphicsScene->addItem(m_Bimage);
    }

    //使视窗的大小固定在原始大小，不会随图片的放大而放大（默认状态下图片放大的时候视窗两边会自动出现滚动条，并且视窗内的视野会变大），防止图片放大后重新缩小的时候视窗太大而不方便观察图片
    ui->ImageGraphic->setSceneRect(QRectF(-(nwith/2),-(nheight/2),nwith,nheight));

    //Sets the current scene to scene. If scene is already being viewed, this function does nothing.
    ui->ImageGraphic->setScene(qgraphicsScene);

    //将界面的焦点设置到当前Graphics View控件
    ui->ImageGraphic->setFocus();
}
