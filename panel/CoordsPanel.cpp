//
// Created by bigcubecat on 08.12.2020.
//

#include "CoordsPanel.h"

CoordsPanel::CoordsPanel(QWidget *parent) : QWidget(parent), ui(new Ui::CoordsPanel) {
    size = 0;
    ui->setupUi(this);
    m_layout = new QHBoxLayout();
    ui->scrollArea->setLayout(m_layout);
    connect(ui->pushButton, &QPushButton::clicked, this, &CoordsPanel::calculateIndex);
}

CoordsPanel::~CoordsPanel() {
    delete ui;
}

void CoordsPanel::reshape(int s, int ls) {
    size = s;
    life_size = ls;
    coords.clear();
    for (int i = 0; i < size; i++) {
        auto *spin = new QSpinBox();
        spin->setMinimum(1);
        spin->setMaximum(life_size);
        coords.push_back(spin);
        m_layout->addWidget(spin);
    }
}

void CoordsPanel::calculateIndex() {
    int N = coords.size();
    INDEX = 0;
    for (int i = 0; i < N; i++) {
        int n = coords[i]->value();
        INDEX += n * (N - i - 1);
    }
    emit signalIndex(INDEX);
}
