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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *m_FontPicture;
    QPushButton *m_BackPicture;
    QPushButton *m_PDF1;
    QPushButton *m_PDF2;
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
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        widget->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"                   background-color:rgba(100,240,100,150);\n"
"                   border-style:outset;\n"
"                   border-width:4px;\n"
"                   border-radius:10px;\n"
"                   border-color:rgba(255,255,255,100);\n"
"                   font: 30px;\n"
"                   color:rgb(0,0,0);\n"
"                   padding:20px;\n"
"}\n"
"\n"
"QPushButton:pressed\n"
"{\n"
"	background-color:rgba(100,255,80,250);\n"
"    border-color:rgba(255,255,255,30);\n"
"    border-style:inset;\n"
"    color:rgb(0,0,0);\n"
"}\n"
"\n"
"QPushButton:hover\n"
"{\n"
"	background-color:rgba(100,255,100,200);\n"
"	border-color:rgba(255,255,255,30);\n"
"	color:rgb(0,0,0);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(10);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        m_FontPicture = new QPushButton(widget);
        m_FontPicture->setObjectName(QString::fromUtf8("m_FontPicture"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_FontPicture->sizePolicy().hasHeightForWidth());
        m_FontPicture->setSizePolicy(sizePolicy1);
        m_FontPicture->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(m_FontPicture);

        m_BackPicture = new QPushButton(widget);
        m_BackPicture->setObjectName(QString::fromUtf8("m_BackPicture"));
        sizePolicy1.setHeightForWidth(m_BackPicture->sizePolicy().hasHeightForWidth());
        m_BackPicture->setSizePolicy(sizePolicy1);
        m_BackPicture->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(m_BackPicture);

        m_PDF1 = new QPushButton(widget);
        m_PDF1->setObjectName(QString::fromUtf8("m_PDF1"));
        sizePolicy1.setHeightForWidth(m_PDF1->sizePolicy().hasHeightForWidth());
        m_PDF1->setSizePolicy(sizePolicy1);
        m_PDF1->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(m_PDF1);

        m_PDF2 = new QPushButton(widget);
        m_PDF2->setObjectName(QString::fromUtf8("m_PDF2"));
        sizePolicy1.setHeightForWidth(m_PDF2->sizePolicy().hasHeightForWidth());
        m_PDF2->setSizePolicy(sizePolicy1);
        m_PDF2->setMinimumSize(QSize(0, 50));

        verticalLayout->addWidget(m_PDF2);


        horizontalLayout->addWidget(widget);

        ImageGraphic = new QGraphicsView(Widget);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));
        ImageGraphic->setStyleSheet(QString::fromUtf8("border-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 0, 0, 255), stop:0.166 rgba(255, 255, 0, 255), stop:0.333 rgba(0, 255, 0, 255), stop:0.5 rgba(0, 255, 255, 255), stop:0.666 rgba(0, 0, 255, 255), stop:0.833 rgba(255, 0, 255, 255), stop:1 rgba(255, 0, 0, 255));"));

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
        m_PDF1->setText(QCoreApplication::translate("Widget", "\350\257\264\346\230\216\344\271\246", nullptr));
        m_PDF2->setText(QCoreApplication::translate("Widget", "\345\233\276\347\272\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
