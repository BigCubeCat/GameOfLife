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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGridLayout *gridLayout;
    QSpinBox *DSpin;
    QLabel *label_9;
    QLabel *label_8;
    QSpinBox *SizeSpin;
    QLabel *label_4;
    QPushButton *applyButton;
    QLabel *label_6;
    QLineEdit *SInput;
    QLCDNumber *lcdNumber;
    QLabel *label_7;
    QPushButton *clearButton;
    QLineEdit *BInput;
    QSpinBox *SpeedSpin;
    QLabel *label_10;
    QPushButton *playButton;
    QFrame *gridFrame;
    QGridLayout *gridLayout_2;
    QRadioButton *Moore;
    QRadioButton *vonNeumann;
    QLabel *label;
    QVBoxLayout *settingsLayout;
    QGroupBox *formGroupBox;
    QFormLayout *formLayout;
    QLabel *label_11;
    QPushButton *pushButton;
    QLabel *label_12;
    QPushButton *pushButton_2;
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
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        DSpin = new QSpinBox(groupBox);
        DSpin->setObjectName(QString::fromUtf8("DSpin"));
        DSpin->setMinimum(2);
        DSpin->setMaximum(1000000000);

        gridLayout->addWidget(DSpin, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 2, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 5, 0, 1, 1);

        SizeSpin = new QSpinBox(groupBox);
        SizeSpin->setObjectName(QString::fromUtf8("SizeSpin"));
        SizeSpin->setMinimum(9);
        SizeSpin->setMaximum(1280000000);
        SizeSpin->setValue(9);

        gridLayout->addWidget(SizeSpin, 6, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 10, 0, 1, 1);

        applyButton = new QPushButton(groupBox);
        applyButton->setObjectName(QString::fromUtf8("applyButton"));

        gridLayout->addWidget(applyButton, 13, 1, 1, 1);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 0, 1, 1);

        SInput = new QLineEdit(groupBox);
        SInput->setObjectName(QString::fromUtf8("SInput"));

        gridLayout->addWidget(SInput, 5, 1, 1, 1);

        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        gridLayout->addWidget(lcdNumber, 1, 1, 1, 1);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 3, 0, 1, 1);

        clearButton = new QPushButton(groupBox);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));

        gridLayout->addWidget(clearButton, 13, 0, 1, 1);

        BInput = new QLineEdit(groupBox);
        BInput->setObjectName(QString::fromUtf8("BInput"));

        gridLayout->addWidget(BInput, 3, 1, 1, 1);

        SpeedSpin = new QSpinBox(groupBox);
        SpeedSpin->setObjectName(QString::fromUtf8("SpeedSpin"));
        SpeedSpin->setMinimum(1);
        SpeedSpin->setMaximum(1000000000);
        SpeedSpin->setValue(1);

        gridLayout->addWidget(SpeedSpin, 10, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout->addWidget(label_10, 6, 0, 1, 1);

        playButton = new QPushButton(groupBox);
        playButton->setObjectName(QString::fromUtf8("playButton"));

        gridLayout->addWidget(playButton, 16, 0, 1, 2);

        gridFrame = new QFrame(groupBox);
        gridFrame->setObjectName(QString::fromUtf8("gridFrame"));
        gridLayout_2 = new QGridLayout(gridFrame);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        Moore = new QRadioButton(gridFrame);
        Moore->setObjectName(QString::fromUtf8("Moore"));

        gridLayout_2->addWidget(Moore, 1, 0, 1, 1);

        vonNeumann = new QRadioButton(gridFrame);
        vonNeumann->setObjectName(QString::fromUtf8("vonNeumann"));

        gridLayout_2->addWidget(vonNeumann, 1, 1, 1, 1);

        label = new QLabel(gridFrame);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(label, 0, 0, 1, 2);


        gridLayout->addWidget(gridFrame, 15, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout);


        verticalLayout->addWidget(groupBox);

        settingsLayout = new QVBoxLayout();
        settingsLayout->setObjectName(QString::fromUtf8("settingsLayout"));
        formGroupBox = new QGroupBox(Panel);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        formGroupBox->setCheckable(true);
        formGroupBox->setChecked(false);
        formLayout = new QFormLayout(formGroupBox);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_11 = new QLabel(formGroupBox);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_11);

        pushButton = new QPushButton(formGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton);

        label_12 = new QLabel(formGroupBox);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_12);

        pushButton_2 = new QPushButton(formGroupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_2);


        settingsLayout->addWidget(formGroupBox);


        verticalLayout->addLayout(settingsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QCoreApplication::translate("Panel", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Panel", "Info", nullptr));
        label_9->setText(QCoreApplication::translate("Panel", "Dimension", nullptr));
        label_8->setText(QCoreApplication::translate("Panel", "S", nullptr));
        label_4->setText(QCoreApplication::translate("Panel", "speed:", nullptr));
        applyButton->setText(QCoreApplication::translate("Panel", "Apply", nullptr));
        label_6->setText(QCoreApplication::translate("Panel", "Generation", nullptr));
        SInput->setText(QCoreApplication::translate("Panel", "2;3", nullptr));
        label_7->setText(QCoreApplication::translate("Panel", "B", nullptr));
        clearButton->setText(QCoreApplication::translate("Panel", "Clear", nullptr));
        BInput->setText(QCoreApplication::translate("Panel", "3", nullptr));
        label_10->setText(QCoreApplication::translate("Panel", "Size", nullptr));
        playButton->setText(QCoreApplication::translate("Panel", "PLAY", nullptr));
        Moore->setText(QCoreApplication::translate("Panel", "Moore", nullptr));
        vonNeumann->setText(QCoreApplication::translate("Panel", "von Neumann", nullptr));
        label->setText(QCoreApplication::translate("Panel", "Neighborhood type", nullptr));
        formGroupBox->setTitle(QCoreApplication::translate("Panel", "Custom Color", nullptr));
        label_11->setText(QCoreApplication::translate("Panel", "BackGround", nullptr));
        pushButton->setText(QCoreApplication::translate("Panel", "choose", nullptr));
        label_12->setText(QCoreApplication::translate("Panel", "Cell", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Panel", "choose", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Panel: public Ui_Panel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANEL_H
