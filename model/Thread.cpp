//
// Created by bigcubecat on 19.12.2020.
//
#include "Thread.h"

Thread::Thread(int n, int s) : QThread() {
    life = new Life(n, s);
    connect(this, &QThread::started, this, &Thread::main_process, Qt::QueuedConnection);
}
void Thread::main_process() {
    life->nextGeneration();
    emit generationFinished();
}
void Thread::run() {
    life->nextGeneration();
}
