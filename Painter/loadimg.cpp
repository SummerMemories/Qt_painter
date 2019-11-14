#include "loadimg.h"

LoadImg::LoadImg()
{

}

LoadImg::LoadImg(QImage *img1,QImage *img2)
{
    m_img1 = img1;
    m_img2 = img2;
}

void LoadImg::run()
{
    m_img1->load(":/resource/1.jpg");
    m_img2->load(":/resource/2.jpg");
}
