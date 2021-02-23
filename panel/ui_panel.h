/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout;
    QLineEdit *BInput;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *SInput;
    QLabel *label_8;
    QLabel *label_4;
    QLabel *label_9;
    QSpinBox *SpeedSpin;
    QLCDNumber *lcdNumber;
    QSpinBox *DSpin;
    QSpinBox *SizeSpin;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *clearButton;
    QPushButton *recomendedButton;
    QPushButton *applyButton;
    QHBoxLayout *horizontalLayout;
    QPushButton *stop;
    QPushButton *step;
    QPushButton *run;
    QGroupBox *gridGroupBox;
    QGridLayout *colorLayout;
    QPushButton *colorButton;
    QCheckBox *borderCheck;
    QPushButton *bgButton;
    QCheckBox *shadeCheck;
    QCheckBox *mapCheck;
    QCheckBox *axisCheck;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(245, 636);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Panel->sizePolicy().hasHeightForWidth());
        Panel->setSizePolicy(sizePolicy);
        Panel->setMinimumSize(QSize(245, 0));
        verticalLayout = new QVBoxLayout(Panel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        groupBox = new QGroupBox(Panel);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        BInput = new QLineEdit(groupBox);
        BInput->setObjectName(QString::fromUtf8("BInput"));

        gridLayout->addWidget(BInput, 3, 2, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        SInput = new QLineEdit(groupBox);
        SInput->setObjectName(QString::fromUtf8("SInput"));

        gridLayout->addWidget(SInput, 5, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 10, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        SpeedSpin = new QSpinBox(groupBox);
        SpeedSpin->setObjectName(QString::fromUtf8("SpeedSpin"));
        SpeedSpin->setMinimum(1);
        SpeedSpin->setMaximum(1000000000);
        SpeedSpin->setValue(100);

        gridLayout->addWidget(SpeedSpin, 10, 2, 1, 1);

        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 1, 2, 1, 1);

        DSpin = new QSpinBox(groupBox);
        DSpin->setObjectName(QString::fromUtf8("DSpin"));
        DSpin->setMinimum(2);
        DSpin->setMaximum(1984);
        DSpin->setValue(3);

        gridLayout->addWidget(DSpin, 2, 2, 1, 1);

        SizeSpin = new QSpinBox(groupBox);
        SizeSpin->setObjectName(QString::fromUtf8("SizeSpin"));
        SizeSpin->setMinimum(1);
        SizeSpin->setMaximum(1280000000);
        SizeSpin->setValue(16);

        gridLayout->addWidget(SizeSpin, 6, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        horizontalLayout_3->addWidget(clearButton);

        recomendedButton = new QPushButton(groupBox);
        recomendedButton->setObjectName(QString::fromUtf8("recomendedButton"));

        horizontalLayout_3->addWidget(recomendedButton);

        applyButton = new QPushButton(groupBox);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        horizontalLayout_3->addWidget(applyButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stop = new QPushButton(groupBox);
        stop->setObjectName(QString::fromUtf8("stop"));

        horizontalLayout->addWidget(stop);

        step = new QPushButton(groupBox);
        step->setObjectName(QString::fromUtf8("step"));

        horizontalLayout->addWidget(step);

        run = new QPushButton(groupBox);
        run->setObjectName(QString::fromUtf8("run"));

        horizontalLayout->addWidget(run);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout_3);


        verticalLayout->addWidget(groupBox);

        gridGroupBox = new QGroupBox(Panel);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridGroupBox->setCheckable(false);
        colorLayout = new QGridLayout(gridGroupBox);
        colorLayout->setObjectName(QString::fromUtf8("colorLayout"));
        colorButton = new QPushButton(gridGroupBox);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        colorLayout->addWidget(colorButton, 0, 0, 1, 1);

        borderCheck = new QCheckBox(gridGroupBox);
        borderCheck->setObjectName(QString::fromUtf8("borderCheck"));
        borderCheck->setChecked(true);

        colorLayout->addWidget(borderCheck, 4, 0, 1, 1);

        bgButton = new QPushButton(gridGroupBox);
        bgButton->setObjectName(QString::fromUtf8("bgButton"));

        colorLayout->addWidget(bgButton, 1, 0, 1, 1);

        shadeCheck = new QCheckBox(gridGroupBox);
        shadeCheck->setObjectName(QString::fromUtf8("shadeCheck"));
        shadeCheck->setChecked(true);

        colorLayout->addWidget(shadeCheck, 2, 0, 1, 1);

        mapCheck = new QCheckBox(gridGroupBox);
        mapCheck->setObjectName(QString::fromUtf8("mapCheck"));

        colorLayout->addWidget(mapCheck, 6, 0, 1, 1);

        axisCheck = new QCheckBox(gridGroupBox);
        axisCheck->setObjectName(QString::fromUtf8("axisCheck"));
        axisCheck->setChecked(true);
        axisCheck->setTristate(false);

        colorLayout->addWidget(axisCheck, 3, 0, 1, 1);


        verticalLayout->addWidget(gridGroupBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QCoreApplication::translate("Panel", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Panel", "Info", nullptr));
        BInput->setText(QCoreApplication::translate("Panel", "3", nullptr));
        label_10->setText(QCoreApplication::translate("Panel", "Size", nullptr));
        label_6->setText(QCoreApplication::translate("Panel", "Generation", nullptr));
        label_7->setText(QCoreApplication::translate("Panel", "B", nullptr));
        SInput->setText(QCoreApplication::translate("Panel", "2,3", nullptr));
        label_8->setText(QCoreApplication::translate("Panel", "S", nullptr));
        label_4->setText(QCoreApplication::translate("Panel", "Speed:", nullptr));
        label_9->setText(QCoreApplication::translate("Panel", "Dimension", nullptr));
        clearButton->setText(QCoreApplication::translate("Panel", "Default", nullptr));
        recomendedButton->setText(QCoreApplication::translate("Panel", "Recomend", nullptr));
        applyButton->setText(QCoreApplication::translate("Panel", "Apply", nullptr));
        stop->setText(QCoreApplication::translate("Panel", "stop", nullptr));
        step->setText(QCoreApplication::translate("Panel", "step", nullptr));
        run->setText(QCoreApplication::translate("Panel", "play", nullptr));
        gridGroupBox->setTitle(QCoreApplication::translate("Panel", "Color", nullptr));
        colorButton->setText(QCoreApplication::translate("Panel", "Cell Color", nullptr));
        borderCheck->setText(QCoreApplication::translate("Panel", "Cell Borders", nullptr));
        bgButton->setText(QCoreApplication::translate("Panel", "BG Color", nullptr));
        shadeCheck->setText(QCoreApplication::translate("Panel", "Shade Color", nullptr));
        mapCheck->setText(QCoreApplication::translate("Panel", "Map Borders", nullptr));
        axisCheck->setText(QCoreApplication::translate("Panel", "Axis", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
