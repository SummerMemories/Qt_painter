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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
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
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(0, 0));
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_FontPicture = new QPushButton(widget);
        m_FontPicture->setObjectName(QString::fromUtf8("m_FontPicture"));

        verticalLayout->addWidget(m_FontPicture);

        m_BackPicture = new QPushButton(widget);
        m_BackPicture->setObjectName(QString::fromUtf8("m_BackPicture"));

        verticalLayout->addWidget(m_BackPicture);

        m_PDF1 = new QPushButton(widget);
        m_PDF1->setObjectName(QString::fromUtf8("m_PDF1"));

        verticalLayout->addWidget(m_PDF1);

        m_PDF2 = new QPushButton(widget);
        m_PDF2->setObjectName(QString::fromUtf8("m_PDF2"));

        verticalLayout->addWidget(m_PDF2);


        horizontalLayout_2->addLayout(verticalLayout);


        horizontalLayout->addWidget(widget);

        ImageGraphic = new QGraphicsView(Widget);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));

        horizontalLayout->addWidget(ImageGraphic);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        m_FontPicture->setText(QCoreApplication::translate("Widget", "\346\255\243\351\235\242\345\233\276", nullptr));
        m_BackPicture->setText(QCoreApplication::translate("Widget", "\350\203\214\351\235\242\345\233\276", nullptr));
        m_PDF1->setText(QCoreApplication::translate("Widget", "PDF1", nullptr));
        m_PDF2->setText(QCoreApplication::translate("Widget", "PDF2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
