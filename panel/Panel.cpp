#include "Panel.h"
#include <QDebug>

Panel::Panel(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Panel) {
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &Panel::applySettings);
    connect(ui->clearButton, &QPushButton::clicked, this, &Panel::clearSettings);

    connect(ui->stop, &QPushButton::clicked, this, &Panel::stopSignal);
    connect(ui->run, &QPushButton::clicked, this, &Panel::playSignal);
    connect(ui->step, &QPushButton::clicked, this, &Panel::stepSignal);

    default_settings.size = ui->SizeSpin->value();  // Default set in qt designer
    default_settings.dimension = 2;
    default_settings.speed = 100;
}

Panel::~Panel() {
    delete ui;
}

void Panel::applySettings() {
    // Read settings
    settings.dimension = ui->DSpin->value();
    settings.size = ui->SizeSpin->value();
    settings.speed = ui->SpeedSpin->value();
    // reading new rules
    QStringList newBList = ui->BInput->text().split(";");
    QStringList newSList = ui->SInput->text().split(";");
    int sSize = newSList.size();
    int bSize = newBList.size();
    int *new_s = new int[sSize];
    int *new_b = new int[bSize];
    for (int i = 0; i < bSize; i++) {
        bool flag = true;
        int _ = newBList[i].toInt(&flag);
        if (!flag) return;
        new_b[i] = _;
    }
    for (int i = 0; i < sSize; i++) {
        bool flag = true;
        int _ = newSList[i].toInt(&flag);
        if (!flag) return;
        new_s[i] = _;
    }
    settings.B = new_b; settings.S = new_s;
    // emit signal to canvas
    emit updateData();
}

void Panel::clearSettings() {
    settings = default_settings;
    ui->BInput->setText(QString::fromStdString("3"));
    ui->SInput->setText(QString::fromStdString("2;3"));
    ui->SizeSpin->setValue(default_settings.size);
    ui->SpeedSpin->setValue(default_settings.speed);
    ui->DSpin->setValue(default_settings.dimension);
    emit updateData();
}

void Panel::updateGeneration() {
    int value = ui->lcdNumber->intValue() + 1;
    ui->lcdNumber->display(value);
}
