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
#include <QtWidgets/QSlider>
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
    QLabel *label_6;
    QLabel *label_10;
    QLCDNumber *lcdNumber;
    QLabel *label_9;
    QSlider *speedSlider;
    QLineEdit *BInput;
    QSpinBox *SizeSpin;
    QLineEdit *SInput;
    QLabel *label_8;
    QLabel *label_7;
    QLabel *label_4;
    QSpinBox *DSpin;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *lobanovButton;
    QPushButton *recommendedButton;
    QPushButton *applyButton;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSlider *aliveSlider;
    QLabel *pLabel;
    QPushButton *generateButton;
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
        Panel->resize(300, 636);
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Panel->sizePolicy().hasHeightForWidth());
        Panel->setSizePolicy(sizePolicy);
        Panel->setMinimumSize(QSize(300, 0));
        Panel->setStyleSheet(QString::fromUtf8(""));
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
        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font;
        font.setPointSize(11);
        label_6->setFont(font);
        label_6->setLineWidth(1);

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Hack"));
        font1.setPointSize(16);
        lcdNumber->setFont(font1);
        lcdNumber->setStyleSheet(QString::fromUtf8(""));
        lcdNumber->setSegmentStyle(QLCDNumber::Flat);

        gridLayout->addWidget(lcdNumber, 1, 2, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        speedSlider = new QSlider(groupBox);
        speedSlider->setObjectName(QString::fromUtf8("speedSlider"));
        speedSlider->setMinimum(1);
        speedSlider->setMaximum(1000);
        speedSlider->setValue(900);
        speedSlider->setOrientation(Qt::Horizontal);

        gridLayout->addWidget(speedSlider, 9, 2, 1, 1);

        BInput = new QLineEdit(groupBox);
        BInput->setObjectName(QString::fromUtf8("BInput"));
        BInput->setFont(font);

        gridLayout->addWidget(BInput, 3, 2, 1, 1);

        SizeSpin = new QSpinBox(groupBox);
        SizeSpin->setObjectName(QString::fromUtf8("SizeSpin"));
        SizeSpin->setFont(font);
        SizeSpin->setMinimum(1);
        SizeSpin->setMaximum(1280000000);
        SizeSpin->setValue(16);

        gridLayout->addWidget(SizeSpin, 6, 2, 1, 1);

        SInput = new QLineEdit(groupBox);
        SInput->setObjectName(QString::fromUtf8("SInput"));
        SInput->setFont(font);

        gridLayout->addWidget(SInput, 5, 2, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        gridLayout->addWidget(label_4, 9, 0, 1, 1);

        DSpin = new QSpinBox(groupBox);
        DSpin->setObjectName(QString::fromUtf8("DSpin"));
        DSpin->setFont(font);
        DSpin->setMinimum(2);
        DSpin->setMaximum(1984);
        DSpin->setValue(3);

        gridLayout->addWidget(DSpin, 2, 2, 1, 1);


        verticalLayout_3->addLayout(gridLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        lobanovButton = new QPushButton(groupBox);
        lobanovButton->setObjectName(QString::fromUtf8("lobanovButton"));
        lobanovButton->setFont(font);
        lobanovButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(lobanovButton);

        recommendedButton = new QPushButton(groupBox);
        recommendedButton->setObjectName(QString::fromUtf8("recommendedButton"));
        recommendedButton->setFont(font);
        recommendedButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(recommendedButton);

        applyButton = new QPushButton(groupBox);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));
        applyButton->setFont(font);
        applyButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_3->addWidget(applyButton);


        verticalLayout_3->addLayout(horizontalLayout_3);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        aliveSlider = new QSlider(groupBox);
        aliveSlider->setObjectName(QString::fromUtf8("aliveSlider"));
        aliveSlider->setMaximum(100);
        aliveSlider->setValue(25);
        aliveSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(aliveSlider);

        pLabel = new QLabel(groupBox);
        pLabel->setObjectName(QString::fromUtf8("pLabel"));
        pLabel->setFont(font);

        horizontalLayout_2->addWidget(pLabel);


        verticalLayout_4->addLayout(horizontalLayout_2);

        generateButton = new QPushButton(groupBox);
        generateButton->setObjectName(QString::fromUtf8("generateButton"));
        generateButton->setFont(font);

        verticalLayout_4->addWidget(generateButton);


        verticalLayout_3->addLayout(verticalLayout_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        stop = new QPushButton(groupBox);
        stop->setObjectName(QString::fromUtf8("stop"));
        stop->setFont(font);
        stop->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(stop);

        step = new QPushButton(groupBox);
        step->setObjectName(QString::fromUtf8("step"));
        step->setFont(font);
        step->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout->addWidget(step);

        run = new QPushButton(groupBox);
        run->setObjectName(QString::fromUtf8("run"));
        run->setFont(font);
        run->setStyleSheet(QString::fromUtf8(""));

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
        colorButton->setFont(font);
        colorButton->setStyleSheet(QString::fromUtf8(""));

        colorLayout->addWidget(colorButton, 0, 0, 1, 1);

        borderCheck = new QCheckBox(gridGroupBox);
        borderCheck->setObjectName(QString::fromUtf8("borderCheck"));
        borderCheck->setFont(font);
        borderCheck->setChecked(true);

        colorLayout->addWidget(borderCheck, 4, 0, 1, 1);

        bgButton = new QPushButton(gridGroupBox);
        bgButton->setObjectName(QString::fromUtf8("bgButton"));
        bgButton->setFont(font);
        bgButton->setStyleSheet(QString::fromUtf8(""));

        colorLayout->addWidget(bgButton, 1, 0, 1, 1);

        shadeCheck = new QCheckBox(gridGroupBox);
        shadeCheck->setObjectName(QString::fromUtf8("shadeCheck"));
        shadeCheck->setFont(font);
        shadeCheck->setChecked(true);

        colorLayout->addWidget(shadeCheck, 2, 0, 1, 1);

        mapCheck = new QCheckBox(gridGroupBox);
        mapCheck->setObjectName(QString::fromUtf8("mapCheck"));
        mapCheck->setFont(font);

        colorLayout->addWidget(mapCheck, 6, 0, 1, 1);

        axisCheck = new QCheckBox(gridGroupBox);
        axisCheck->setObjectName(QString::fromUtf8("axisCheck"));
        axisCheck->setFont(font);
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
        groupBox->setTitle(QString());
        label_6->setText(QCoreApplication::translate("Panel", "Generation", nullptr));
        label_10->setText(QCoreApplication::translate("Panel", "Size", nullptr));
        label_9->setText(QCoreApplication::translate("Panel", "Dimension", nullptr));
        BInput->setText(QCoreApplication::translate("Panel", "3", nullptr));
        SInput->setText(QCoreApplication::translate("Panel", "2,3", nullptr));
        label_8->setText(QCoreApplication::translate("Panel", "S", nullptr));
        label_7->setText(QCoreApplication::translate("Panel", "B", nullptr));
        label_4->setText(QCoreApplication::translate("Panel", "Speed:", nullptr));
#if QT_CONFIG(tooltip)
        lobanovButton->setToolTip(QCoreApplication::translate("Panel", "set Lobanov's rules", nullptr));
#endif // QT_CONFIG(tooltip)
        lobanovButton->setText(QCoreApplication::translate("Panel", "Lobanov's", nullptr));
#if QT_CONFIG(tooltip)
        recommendedButton->setToolTip(QCoreApplication::translate("Panel", "set \"relative\" rules", nullptr));
#endif // QT_CONFIG(tooltip)
        recommendedButton->setText(QCoreApplication::translate("Panel", "Relative", nullptr));
#if QT_CONFIG(tooltip)
        applyButton->setToolTip(QCoreApplication::translate("Panel", "Apply rules", nullptr));
#endif // QT_CONFIG(tooltip)
        applyButton->setText(QCoreApplication::translate("Panel", "Apply", nullptr));
        label->setText(QCoreApplication::translate("Panel", "alive: ", nullptr));
        pLabel->setText(QCoreApplication::translate("Panel", "%", nullptr));
        generateButton->setText(QCoreApplication::translate("Panel", "Generate random world", nullptr));
#if QT_CONFIG(tooltip)
        stop->setToolTip(QCoreApplication::translate("Panel", "stop", nullptr));
#endif // QT_CONFIG(tooltip)
        stop->setText(QString());
#if QT_CONFIG(tooltip)
        step->setToolTip(QCoreApplication::translate("Panel", "step", nullptr));
#endif // QT_CONFIG(tooltip)
        step->setText(QString());
#if QT_CONFIG(tooltip)
        run->setToolTip(QCoreApplication::translate("Panel", "play", nullptr));
#endif // QT_CONFIG(tooltip)
#if QT_CONFIG(statustip)
        run->setStatusTip(QCoreApplication::translate("Panel", "play", nullptr));
#endif // QT_CONFIG(statustip)
        run->setText(QString());
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
