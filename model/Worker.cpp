//
// Created by bigcubecat on 19.12.2020.
//
#include "Worker.h"
#include <QDebug>
#include <QThread>
#include <utility>

void Worker::updateParameters(int d, int size, vector<int> b, vector<int> s, int v) {
    life = new Life(d, size, std::move(b), std::move(s), 3);
    D = d;
    SIZE = size;
    emit updateRender(life->renderData(coord));
}

Worker::Worker() : QThread() {
    D = 3;
    SIZE = 32;
    crutch = 0;
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}

void Worker::run() {
    crutch++;
    // Ужасный костыль, мне стыдно за него (
    if (crutch % 2 == 0) 
        return;
    // qDebug() << sender();  // должно помочь убрать костыль)Жц
    life->nextGeneration();
    renderData = life->renderData(coord);
    emit updateRender(renderData);
}

void Worker::step() {
    life->nextGeneration();
    renderData = life->renderData(coord);
    emit updateRender(renderData);
}

bool Worker::getCell(int index) {
    return life->getCell(index);
}

void Worker::setLife(Life newModel) {
    qDebug() << life->N;
    life = &newModel;
    qDebug() << "set Life";
    qDebug() << life->N;
}
