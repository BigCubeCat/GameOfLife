//
// Created by bigcubecat on 19.12.2020.
//
#include "Worker.h"
#include <QDebug>
#include <QThread>
#include <utility>

void Worker::updateParameters(int d, int size, vector<int> b, vector<int> s, int v) {
    life = new Life(d, size, std::move(b), std::move(s), v);
    D = d;
    SIZE = size;
    emit updateRender(life->renderData(coord));
}

Worker::Worker() : QThread() {
    D = 3;
    SIZE = 32;
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}

void Worker::run() {
    life->nextGeneration();
    renderData = life->renderData(coord);
    emit updateRender(life->renderData(coord));
}

bool Worker::getCell(int index) {
    return life->getCell(index);
}

