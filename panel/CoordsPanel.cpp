//
// Created by bigcubecat on 08.12.2020.
//

#include "CoordsPanel.h"
#include <QDebug>
#include "../model/Life.h"


CoordsPanel::CoordsPanel(QWidget *parent) : QWidget(parent), ui(new Ui::CoordsPanel) {
    size = 0;
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &CoordsPanel::calculateIndex);
    connect(ui->clearButton, &QPushButton::clicked, this, &CoordsPanel::clearValues);
}

void CoordsPanel::clearLayout() {
    ui->scrollArea->widget()->deleteLater();
    m_layout = new QHBoxLayout();
    //add buttons to new layout
    auto widget = new QWidget();
    widget->setLayout(m_layout);
    ui->scrollArea->setWidget(widget);
}

CoordsPanel::~CoordsPanel() {
    delete ui;
}

void CoordsPanel::reshape(int d, int s) {
    clearLayout();
    size = s;
    dimension = d;
    coords.clear();
    for (int i = 0; i < d - 3; i++) {
        auto *spin = new QSpinBox();
        spin->setMinimum(0);
        spin->setMaximum(size - 1);
        coords.push_back(spin);
        m_layout->addWidget(spin);
    }
    this->update();
}

int CoordsPanel::pow(int a, int b) {
    int answer = 1;
    for (int i =0; i < b; i++) {
        answer *= a;
    }
    return answer;
}

void CoordsPanel::calculateIndex() {
    qDebug() << dimension;
    int index = 0;
    int j = 0;
    for (int i = dimension - 1; i > 2; i--) {
        index += this->pow(size, i) * coords[j]->value();
    }
    qDebug() << "END";
    emit signalIndex(index);
}

void CoordsPanel::clearValues() {
    for (auto c : coords) {
        c->setValue(0);
    }
}

