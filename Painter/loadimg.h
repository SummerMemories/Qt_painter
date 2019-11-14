#ifndef LOADIMG_H
#define LOADIMG_H
#include <QThread>
#include <QImage>

class LoadImg :public QThread
{
public:
    LoadImg();

    LoadImg(QImage *img1,QImage *img2);

    void run();

private:
    QImage *m_img1;
    QImage *m_img2;
};

#endif // LOADIMG_H
