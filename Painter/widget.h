#ifndef WIDGET_H
#define WIDGET_H
#include "imagewidget.h"
#include "backimage.h"
#include "loadimg.h"
#include <QUrl>
#include <QDebug>
#include <QDir>
#include <QWidget>
#include <QGraphicsScene>
#include <QDesktopServices>

QT_BEGIN_NAMESPACE
class QGraphicsScene;
QT_END_NAMESPACE

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

    void recvShowPicSignal(int num, QImage image);

    void ADDLogo();

private slots:
    void on_m_FontPicture_clicked();

    void on_m_BackPicture_clicked();

    void on_m_PDF2_clicked();

    void on_m_PDF3_clicked();

    void on_m_PDF1_clicked();

    void on_m_PDF4_clicked();

private:
    Ui::Widget *ui;
    ImageWidget *m_Image;
    BackImage *m_Bimage;

    QImage img1;
    QImage img2;
    LoadImg *m_thread;
};

#endif // WIDGET_H
