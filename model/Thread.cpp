//
// Created by bigcubecat on 19.12.2020.
//
#include "Thread.h"
#include <QDebug>

Thread::Thread(int n, int s) : QThread() {
    life = new Life(n, s);
    connect(this, &QThread::started, this, &Thread::run, Qt::QueuedConnection);
}
void Thread::run() {
    life->nextGeneration();
    emit generationFinished(QVector<bool>::fromStdVector(life->getRenderData(coord)));
}
