//
// Created by bigcubecat on 19.12.2020.
//
#include "Worker.h"
#include <QDebug>

Worker::Worker(int n, int s) : QThread() {
    life = new Life(n, s);
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}
void Worker::run() {
    life->nextGeneration();
    emit generationFinished(QVector<bool>::fromStdVector(life->getRenderData(coord)));
}
