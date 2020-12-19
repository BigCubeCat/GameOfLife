//
// Created by bigcubecat on 19.12.2020.
//
#ifdef _WINDOWS
#include <windows.h>
#else
#include <unistd.h>
#define Sleep(x) usleep((x)*1000)
#endif

#include "Thread.h"
#include <QDebug>

Thread::Thread(int n, int s) : QThread(nullptr) {
    life = new Life(n, s);
    connect(this, &QThread::started, this, &Thread::main_process);
    qDebug() << "Fuckoff";
}

void Thread::setDelay(int _delay) {
    delay = _delay;
}

[[noreturn]] void Thread::main_process() {
    while (true) {
        if (!running) continue;
        life->nextGeneration();
        Sleep(delay);
        emit generationFinished();
    }
}
