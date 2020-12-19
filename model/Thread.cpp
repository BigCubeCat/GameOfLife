//
// Created by bigcubecat on 19.12.2020.
//
#include "Thread.h"
#include <QDebug>

Thread::Thread(int n, int s) : QThread() {
    life = new Life(n, s);
    connect(this, &QThread::started, this, &Thread::main_process, Qt::QueuedConnection);
    qDebug() << "Fuckoff";
}

void Thread::main_process() {
    qDebug() << "fuuuu";
    life->nextGeneration();
    emit generationFinished();
}

void Thread::run() {
    qDebug() << "run";
    life->nextGeneration();
}
