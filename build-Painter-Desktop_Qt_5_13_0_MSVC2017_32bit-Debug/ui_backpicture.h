/********************************************************************************
** Form generated from reading UI file 'backpicture.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BACKPICTURE_H
#define UI_BACKPICTURE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BackPicture
{
public:
    QPushButton *m_Return;
    QGraphicsView *ImageGraphic;

    void setupUi(QWidget *BackPicture)
    {
        if (BackPicture->objectName().isEmpty())
            BackPicture->setObjectName(QString::fromUtf8("BackPicture"));
        BackPicture->resize(737, 570);
        m_Return = new QPushButton(BackPicture);
        m_Return->setObjectName(QString::fromUtf8("m_Return"));
        m_Return->setGeometry(QRect(620, 170, 101, 41));
        ImageGraphic = new QGraphicsView(BackPicture);
        ImageGraphic->setObjectName(QString::fromUtf8("ImageGraphic"));
        ImageGraphic->setGeometry(QRect(50, 50, 561, 441));

        retranslateUi(BackPicture);

        QMetaObject::connectSlotsByName(BackPicture);
    } // setupUi

    void retranslateUi(QWidget *BackPicture)
    {
        BackPicture->setWindowTitle(QCoreApplication::translate("BackPicture", "Form", nullptr));
        m_Return->setText(QCoreApplication::translate("BackPicture", "\350\277\224\345\233\236\344\270\273\347\225\214\351\235\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class BackPicture: public Ui_BackPicture {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BACKPICTURE_H
