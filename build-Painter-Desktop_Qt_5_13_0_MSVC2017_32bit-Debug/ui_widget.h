/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QPushButton *m_FontPicture;
    QPushButton *m_BackPicture;
    QPushButton *m_PDF2;
    QPushButton *m_PDF1;
    QGraphicsView *ImageGraphic;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(756, 488);
        horizontalLayout = new QHBoxLayout(Widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 5, 5, 0);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        m_FontPicture = new QPushButton(widget);
        m_FontPicture->setObjectName(QString::fromUtf8("m_FontPicture"));
        m_FontPicture->setGeometry(QRect(30, 230, 93, 28));
        m_BackPicture = new QPushButton(widget);
        m_BackPicture->setObjectName(QString::fromUtf8("m_BackPicture"));
        m_BackPicture->setGeometry(QRect(30, 270, 93, 28));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_BackPicture->sizePolicy().hasHeightForWidth());
        m_BackPicture->setSizePolicy(sizePolicy1);
        m_PDF2 = new QPushButton(widget);
        m_PDF2->setObjectName(QString::fromUtf8("m_PDF2"));
        m_PDF2->setGeometry(QRect(30, 370, 93, 28));
        sizePolicy1.setHeightForWidth(m_PDF2->sizePolicy().hasHeightForWidth());
        m_PDF2->setSizePolicy(sizePolicy1);
        m_PDF1 = new QPushButton(widget);
        m_PDF1->setObjectName(QString::fromUtf8("m_PDF1"));
        m_PDF1->setGeometry(QRect(30, 320, 93, 28));
        sizePolicy1.setHeightForWidth(m_PDF1->sizePolicy().hasHeightForWidth());
        m_PDF1->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(widget);

        ImageGraphic = new QGraphicsView(Widget);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));

        horizontalLayout->addWidget(ImageGraphic);

        horizontalLayout->setStretch(0, 2);
        horizontalLayout->setStretch(1, 8);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        m_FontPicture->setText(QCoreApplication::translate("Widget", "\346\255\243\351\235\242\345\233\276", nullptr));
        m_BackPicture->setText(QCoreApplication::translate("Widget", "\350\203\214\351\235\242\345\233\276", nullptr));
        m_PDF2->setText(QCoreApplication::translate("Widget", "PDF2", nullptr));
        m_PDF1->setText(QCoreApplication::translate("Widget", "PDF1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
