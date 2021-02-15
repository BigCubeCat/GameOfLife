#include "Panel.h"
#include <QDebug>

Panel::Panel(QWidget *parent) : QWidget(parent),
    ui(new Ui::Panel) {
        ui->setupUi(this);
        connect(ui->applyButton, &QPushButton::clicked, this, &Panel::applySettings);
        connect(ui->clearButton, &QPushButton::clicked, this, &Panel::clearSettings);
        connect(ui->recomendedButton, &QPushButton::clicked, this, &Panel::recomendedSettings);

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
    vector<int> new_b = getRules(ui->BInput->text());
    vector<int> new_s = getRules(ui->SInput->text());
    settings.B = new_b; settings.S = new_s;
    // emit signal to canvas
    emit updateData();
}

void Panel::recomendedSettings() {
    int c, d;
    d = ui->DSpin->value();
    c = intpow(3, d);
    QString newB = QString::number(c / 3) + "." + QString::number(4 * c / 9 - 1);
    QString newS = QString::number(2 * c / 9) + "." + QString::number(4 * c / 9 - 1);
    ui->BInput->setText(newB);
    ui->SInput->setText(newS);
    applySettings();
}

void Panel::clearSettings() {
    settings = default_settings;
    ui->BInput->setText(QString::fromStdString("3"));
    ui->SInput->setText(QString::fromStdString("2,3"));
    ui->SizeSpin->setValue(default_settings.size);
    ui->SpeedSpin->setValue(default_settings.speed);
    ui->DSpin->setValue(default_settings.dimension);
}

void Panel::updateGeneration(int value) {
    ui->lcdNumber->display(value);
}

void Panel::updateSettings(int d, int s, QString b_rule, QString s_rule) {
    ui->BInput->setText(b_rule);
    ui->SInput->setText(s_rule);
    ui->SizeSpin->setValue(s);
    ui->DSpin->setValue(d);
}

QString Panel::getB() {
    return ui->BInput->text();
}

QString Panel::getS() {
    return ui->SInput->text();
}
