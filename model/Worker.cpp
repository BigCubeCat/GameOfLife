//
// Created by bigcubecat on 19.12.2020.
//
#include "Worker.h"
#include <QDebug>
#include <utility>

void Worker::updateParameters(int d, int size, vector<int> b, vector<int> s) {
    life = new Life(d, size, std::move(b), std::move(s));
    D = d;
    SIZE = size;
    emit updateRender(life->getRenderData(coord));
}

Worker::Worker() : QThread() {
    D = 3;
    SIZE = 32;
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}

void Worker::run() {
    life->nextGeneration();
    qDebug() << "OK";
    emit updateRender(life->getRenderData(coord));
}

bool Worker::getCell(int index) {
    return life->getCell(index);
}