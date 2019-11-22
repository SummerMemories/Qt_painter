#include "widget.h"
#include "ui_widget.h"
#include <QGraphicsRectItem>
#include <QApplication>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#pragma execution_character_set("utf-8")

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    ADDLogo();
    this->showMaximized();
    m_thread = new LoadImg(&img1, &img2);
    m_thread->start();
}

Widget::~Widget()
{
    m_thread->exit();
    delete ui;
}

void Widget::ADDLogo()
{
    QPixmap *pixmap = new QPixmap(":/resource/3.png");
    pixmap->scaled(ui->label->size(), Qt::KeepAspectRatio);
    ui->label->setScaledContents(true);
    ui->label->setPixmap(*pixmap);
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
    QString path1 = "file:///";
    QString path2 = QApplication::applicationDirPath();
    path2 = path2 + "/定值单.pdf";
    path1 = path1 + path2;
    qDebug()<<path1;
    QDesktopServices::openUrl(QUrl::fromLocalFile(path1));
}

void Widget::on_m_PDF2_clicked()
{
    QString path1 = "file:///";
    QString path2 = QApplication::applicationDirPath();
    path2 = path2 + "/说明书.pdf";
    path1 = path1 + path2;
    qDebug()<<path1;
    QDesktopServices::openUrl(QUrl::fromLocalFile(path1));

    /*
     string s = qstr.toStdString();
     QString qstr2 = QString::fromStdString(s);
    */
}

void Widget::on_m_PDF3_clicked()
{

    QString path1 = "file:///";
    QString path2 = QApplication::applicationDirPath();

    //std::string p = path2.toStdString();
    //std::string::size_type nPos = p.find(flag);
    //p = p.substr(0, nPos);
    //path2 = QString::fromStdString(p);
    path2 = path2 + "/图纸.pdf";
    path1 = path1 + path2;
    qDebug()<<path1;
    QDesktopServices::openUrl(QUrl::fromLocalFile(path1));
}

void Widget::on_m_PDF4_clicked()
{
    QString path1 = "file:///";
    QString path2 = QApplication::applicationDirPath();
    path2 = path2 + "/操作说明.pdf";
    path1 = path1 + path2;
    qDebug()<<path1;
    QDesktopServices::openUrl(QUrl::fromLocalFile(path1));
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
