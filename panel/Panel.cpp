#include "Panel.h"

Panel::Panel(QWidget *parent) : QWidget(parent),
                                ui(new Ui::Panel) {
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &Panel::applyRules);
    connect(ui->lobanovButton, &QPushButton::clicked, this, &Panel::lobanovRules);
    connect(ui->recommendedButton, &QPushButton::clicked, this, &Panel::relativeRules);
    connect(ui->generateButton, &QPushButton::clicked, this, &Panel::generateWorld);

    connect(ui->stop, &QPushButton::clicked, this, &Panel::stopSignal);
    connect(ui->run, &QPushButton::clicked, this, &Panel::playSignal);
    connect(ui->step, &QPushButton::clicked, this, &Panel::stepSignal);

    connect(ui->colorButton, &QPushButton::clicked, this, &Panel::changeColor);

    connect(ui->shadeCheck, &QCheckBox::toggled, this, &Panel::checkShade);
    connect(ui->borderCheck, &QCheckBox::toggled, this, &Panel::checkEdge);
    connect(ui->mapCheck, &QCheckBox::toggled, this, &Panel::checkMap);
    connect(ui->axisCheck, &QCheckBox::toggled, this, &Panel::checkAxis);

    connect(ui->speedSlider, &QSlider::valueChanged, this, &Panel::setSpeed);
    connect(ui->aliveSlider, &QSlider::valueChanged, this, &Panel::aliveSliderChanged);

    connect(ui->bgButton, &QPushButton::clicked, this, &Panel::changeBG);
    
    connect(ui->setbutton, &QPushButton::clicked, this, &Panel::setCell);

    ui->run->setIcon(QIcon("icons/play.svg"));
    ui->stop->setIcon(QIcon("icons/pause.svg"));
    ui->step->setIcon(QIcon("icons/step.svg"));

    default_settings.size = ui->SizeSpin->value();  // Default set in qt designer
    default_settings.dimension = 2;
    default_settings.speed = 100;
}

Panel::~Panel() {
    delete ui;
}

void Panel::generateWorld() {
    settings.probability = ui->aliveSlider->value();
    settings.dimension = ui->DSpin->value();
    settings.size = ui->SizeSpin->value();
    emit updateData();
}

void Panel::applyRules() {
    // reading new rules
    vector<int> new_b = getRules(ui->BInput->text());
    vector<int> new_s = getRules(ui->SInput->text());
    settings.B = new_b;
    settings.S = new_s;
    ui->xSpin->setMaximum(settings.size - 1);
    ui->ySpin->setMaximum(settings.size - 1);
    ui->zSpin->setMaximum(settings.size - 1);
    // emit signal to canvas
    emit updateRules();
}

void Panel::setCell() {
    settings.x = ui->xSpin->value();
    settings.y = ui->ySpin->value();
    settings.z = ui->zSpin->value();
    emit setCellSignal();
}

void Panel::setSpeed() {
    settings.speed = 1000 - ui->speedSlider->value();
    emit updateSpeed();
}

void Panel::relativeRules() {
    int c, d;
    d = ui->DSpin->value();
    c = intpow(3, d);
    ui->BInput->setText(QString::number(c / 3) + "." + QString::number(4 * c / 9 - 1));
    ui->SInput->setText(QString::number(2 * c / 9) + "." + QString::number(4 * c / 9 - 1));
    applyRules();
}

void Panel::lobanovRules() {
    settings = default_settings;
    int d = ui->DSpin->value();
    ui->BInput->setText(QString::number(intpow(2, d - 1) + intpow(2, d - 2)) + "." + QString::number(intpow(2, d) - 1));
    ui->SInput->setText(QString::number(intpow(2, d - 1)) + "." + QString::number(intpow(2, d) - 1));
    applyRules();
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

void Panel::changeColor() {
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;
    r = (float) color.red() / (float) 256;
    g = (float) color.green() / (float) 256;
    b = (float) color.blue() / (float) 256;
    QPalette pal = ui->colorButton->palette();
    pal.setColor(QPalette::Button, color);
    ui->colorButton->setAutoFillBackground(true);
    ui->colorButton->setPalette(pal);
    ui->colorButton->update();
}

void Panel::changeBG() {
    QColor color = QColorDialog::getColor();
    if (!color.isValid()) return;
    R = (float) color.red() / (float) 256;
    G = (float) color.green() / (float) 256;
    B = (float) color.blue() / (float) 256;
    QPalette pal = ui->bgButton->palette();
    pal.setColor(QPalette::Button, color);
    ui->bgButton->setAutoFillBackground(true);
    ui->bgButton->setPalette(pal);
    ui->bgButton->update();
}

void Panel::checkShade() {
    shadeColor = ui->shadeCheck->isChecked();
}

void Panel::checkEdge() {
    showEdges = ui->borderCheck->isChecked();
}

void Panel::checkMap() {
    showMap = ui->mapCheck->isChecked();
}

void Panel::checkAxis() {
    showAxis = ui->axisCheck->isChecked();
}
void Panel::aliveSliderChanged() {
    ui->pLabel->setText(QString::number(ui->aliveSlider->value()) + QString("%"));
}
