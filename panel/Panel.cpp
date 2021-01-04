#include "Panel.h"
#include <QDebug>

Panel::Panel(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Panel) {
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &Panel::applySettings);
    connect(ui->clearButton, &QPushButton::clicked, this, &Panel::clearSettings);
    connect(ui->playButton, &QPushButton::clicked, this, &Panel::playSignal);
    ui->Moore->setChecked(true);

    default_settings.size = ui->SizeSpin->value();  // Default set in qt designer
    default_settings.dimension = 2;
    default_settings.speed = 100;
    default_settings.B.push_back(3);
    default_settings.S.push_back(2);
    default_settings.S.push_back(3);
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
    vector<int> news;
    vector<int> newb;
    QStringList newBList = ui->BInput->text().split(";");
    QStringList newSList = ui->SInput->text().split(";");
    for (QString b : newBList) {
        bool flag = true;
        int _ = b.toInt(&flag);
        if (!flag) return;  // TODO
        newb.push_back(_);
    }
    for (QString s : newSList) {
        bool flag = true;
        int _ = s.toInt(&flag);
        if (!flag) return;
        news.push_back(_);
    }
    settings.B = newb; settings.S = news;
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
