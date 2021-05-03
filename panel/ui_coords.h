/********************************************************************************
** Form generated from reading UI file 'coords.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COORDS_H
#define UI_COORDS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CoordsPanel
{
public:
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton;
    QPushButton *clearButton;

    void setupUi(QWidget *CoordsPanel)
    {
        if (CoordsPanel->objectName().isEmpty())
            CoordsPanel->setObjectName(QString::fromUtf8("CoordsPanel"));
        CoordsPanel->resize(521, 88);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CoordsPanel->sizePolicy().hasHeightForWidth());
        CoordsPanel->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(CoordsPanel);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        scrollArea = new QScrollArea(CoordsPanel);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        QFont font;
        font.setPointSize(11);
        scrollArea->setFont(font);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 413, 68));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        pushButton = new QPushButton(CoordsPanel);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        clearButton = new QPushButton(CoordsPanel);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        sizePolicy1.setHeightForWidth(clearButton->sizePolicy().hasHeightForWidth());
        clearButton->setSizePolicy(sizePolicy1);
        clearButton->setFont(font);

        verticalLayout->addWidget(clearButton);


        horizontalLayout->addLayout(verticalLayout);


        retranslateUi(CoordsPanel);

        QMetaObject::connectSlotsByName(CoordsPanel);
    } // setupUi

    void retranslateUi(QWidget *CoordsPanel)
    {
        CoordsPanel->setWindowTitle(QCoreApplication::translate("CoordsPanel", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("CoordsPanel", "ok", nullptr));
        clearButton->setText(QCoreApplication::translate("CoordsPanel", "clear", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CoordsPanel: public Ui_CoordsPanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COORDS_H
