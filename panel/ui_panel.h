/********************************************************************************
** Form generated from reading UI file 'panel.ui'
**
** Created by: Qt User Interface Compiler version 5.15.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANEL_H
#define UI_PANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Panel
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *formGroupBox;
    QFormLayout *infoLayout;
    QLabel *label_6;
    QLCDNumber *lcdNumber;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QSpinBox *spinBox_4;
    QLabel *label_10;
    QSpinBox *spinBox_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label_4;
    QWidget *horizontalWidget;
    QHBoxLayout *speedWGT;
    QSpinBox *spinBox;
    QLabel *label_5;
    QVBoxLayout *settingsLayout;
    QGroupBox *formGroupBox1;
    QFormLayout *rotationLayout;
    QLabel *label;
    QSpinBox *XSpeed;
    QLabel *label_2;
    QSpinBox *YSpeed;
    QLabel *label_3;
    QSpinBox *ZSpeed;
    QGroupBox *formGroupBox2;
    QFormLayout *formLayout;
    QLabel *label_11;
    QPushButton *pushButton;
    QLabel *label_12;
    QPushButton *pushButton_2;

    void setupUi(QWidget *Panel)
    {
        if (Panel->objectName().isEmpty())
            Panel->setObjectName(QString::fromUtf8("Panel"));
        Panel->resize(202, 600);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Panel->sizePolicy().hasHeightForWidth());
        Panel->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Panel);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formGroupBox = new QGroupBox(Panel);
        formGroupBox->setObjectName(QString::fromUtf8("formGroupBox"));
        formGroupBox->setFlat(false);
        formGroupBox->setCheckable(false);
        infoLayout = new QFormLayout(formGroupBox);
        infoLayout->setObjectName(QString::fromUtf8("infoLayout"));
        label_6 = new QLabel(formGroupBox);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        infoLayout->setWidget(0, QFormLayout::LabelRole, label_6);

        lcdNumber = new QLCDNumber(formGroupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        infoLayout->setWidget(0, QFormLayout::FieldRole, lcdNumber);

        label_7 = new QLabel(formGroupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        infoLayout->setWidget(1, QFormLayout::LabelRole, label_7);

        label_8 = new QLabel(formGroupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        infoLayout->setWidget(2, QFormLayout::LabelRole, label_8);

        label_9 = new QLabel(formGroupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        infoLayout->setWidget(3, QFormLayout::LabelRole, label_9);

        spinBox_4 = new QSpinBox(formGroupBox);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));

        infoLayout->setWidget(3, QFormLayout::FieldRole, spinBox_4);

        label_10 = new QLabel(formGroupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        infoLayout->setWidget(4, QFormLayout::LabelRole, label_10);

        spinBox_5 = new QSpinBox(formGroupBox);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));

        infoLayout->setWidget(4, QFormLayout::FieldRole, spinBox_5);

        lineEdit = new QLineEdit(formGroupBox);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        infoLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        lineEdit_2 = new QLineEdit(formGroupBox);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        infoLayout->setWidget(2, QFormLayout::FieldRole, lineEdit_2);

        label_4 = new QLabel(formGroupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        infoLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        horizontalWidget = new QWidget(formGroupBox);
        horizontalWidget->setObjectName(QString::fromUtf8("horizontalWidget"));
        speedWGT = new QHBoxLayout(horizontalWidget);
        speedWGT->setObjectName(QString::fromUtf8("speedWGT"));
        spinBox = new QSpinBox(horizontalWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        speedWGT->addWidget(spinBox);

        label_5 = new QLabel(horizontalWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        speedWGT->addWidget(label_5);


        infoLayout->setWidget(5, QFormLayout::FieldRole, horizontalWidget);


        verticalLayout->addWidget(formGroupBox);

        settingsLayout = new QVBoxLayout();
        settingsLayout->setObjectName(QString::fromUtf8("settingsLayout"));
        formGroupBox1 = new QGroupBox(Panel);
        formGroupBox1->setObjectName(QString::fromUtf8("formGroupBox1"));
        formGroupBox1->setCheckable(true);
        formGroupBox1->setChecked(false);
        rotationLayout = new QFormLayout(formGroupBox1);
        rotationLayout->setObjectName(QString::fromUtf8("rotationLayout"));
        label = new QLabel(formGroupBox1);
        label->setObjectName(QString::fromUtf8("label"));

        rotationLayout->setWidget(0, QFormLayout::LabelRole, label);

        XSpeed = new QSpinBox(formGroupBox1);
        XSpeed->setObjectName(QString::fromUtf8("XSpeed"));
        XSpeed->setMinimum(0);

        rotationLayout->setWidget(0, QFormLayout::FieldRole, XSpeed);

        label_2 = new QLabel(formGroupBox1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        rotationLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        YSpeed = new QSpinBox(formGroupBox1);
        YSpeed->setObjectName(QString::fromUtf8("YSpeed"));

        rotationLayout->setWidget(1, QFormLayout::FieldRole, YSpeed);

        label_3 = new QLabel(formGroupBox1);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        rotationLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        ZSpeed = new QSpinBox(formGroupBox1);
        ZSpeed->setObjectName(QString::fromUtf8("ZSpeed"));

        rotationLayout->setWidget(2, QFormLayout::FieldRole, ZSpeed);


        settingsLayout->addWidget(formGroupBox1);

        formGroupBox2 = new QGroupBox(Panel);
        formGroupBox2->setObjectName(QString::fromUtf8("formGroupBox2"));
        formGroupBox2->setCheckable(true);
        formGroupBox2->setChecked(false);
        formLayout = new QFormLayout(formGroupBox2);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_11 = new QLabel(formGroupBox2);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_11);

        pushButton = new QPushButton(formGroupBox2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton);

        label_12 = new QLabel(formGroupBox2);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_12);

        pushButton_2 = new QPushButton(formGroupBox2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButton_2);


        settingsLayout->addWidget(formGroupBox2);


        verticalLayout->addLayout(settingsLayout);


        retranslateUi(Panel);

        QMetaObject::connectSlotsByName(Panel);
    } // setupUi

    void retranslateUi(QWidget *Panel)
    {
        Panel->setWindowTitle(QCoreApplication::translate("Panel", "Form", nullptr));
        formGroupBox->setTitle(QCoreApplication::translate("Panel", "Info", nullptr));
        label_6->setText(QCoreApplication::translate("Panel", "Generation", nullptr));
        label_7->setText(QCoreApplication::translate("Panel", "B", nullptr));
        label_8->setText(QCoreApplication::translate("Panel", "S", nullptr));
        label_9->setText(QCoreApplication::translate("Panel", "Dimensions:", nullptr));
        label_10->setText(QCoreApplication::translate("Panel", "Size", nullptr));
        label_4->setText(QCoreApplication::translate("Panel", "speed:", nullptr));
        label_5->setText(QCoreApplication::translate("Panel", "gen/sec", nullptr));
        formGroupBox1->setTitle(QCoreApplication::translate("Panel", "Rotate", nullptr));
        label->setText(QCoreApplication::translate("Panel", "X", nullptr));
        label_2->setText(QCoreApplication::translate("Panel", "Y", nullptr));
        label_3->setText(QCoreApplication::translate("Panel", "Z", nullptr));
        formGroupBox2->setTitle(QCoreApplication::translate("Panel", "Custom Color", nullptr));
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
