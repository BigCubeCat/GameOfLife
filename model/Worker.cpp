//
// Created by bigcubecat on 19.12.2020.
//
#include "Worker.h"
#include <QDebug>

Worker::Worker(int d, int size, int *b, int *s, bool random_data) : QThread() {
    updateParameters(d, size, b, s, random_data);
    D = d;
    SIZE = size;
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}

Worker::Worker() {
    D = 3;
    SIZE = 32;
    connect(this, &QThread::started, this, &Worker::run, Qt::QueuedConnection);
}

void Worker::run() {
    NextGen();
    bool *_render_data = static_cast<bool *>(GetRenderData().data);
    emit generationFinished(_render_data);
}

void Worker::updateParameters(int d, int size, int *b, int *s, bool random_data) {
    GoSlice b_rule{b};
    GoSlice s_rule{s};
    Setup((long long) size, (long long) d, b_rule, s_rule, random_data);
}

bool Worker::getCell(int index) {
    return CheckCell(index);
}