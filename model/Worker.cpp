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
    qDebug() << sender();
    if (isBusy) {
        return;
    }
    isBusy = true;
    life->nextGeneration();
    renderData = life->renderData(coord);
    isBusy = false;
    emit updateRender(renderData);
}

void Worker::step() {
    if (isBusy) return;
    isBusy = true;
    life->nextGeneration();
    renderData = life->renderData(coord);
    isBusy = false;
    emit updateRender(renderData);
}

void Worker::changeCoord() {
    renderData = life->renderData(coord);
    emit updateRender(renderData);
}

bool Worker::getCell(int index) {
    return life->getCell(coord + index);
}

void Worker::setLife(Life newModel) {
    isBusy = true;
    life = &newModel;
    isBusy = false;
}

QString Worker::getData(QString b, QString s) {
    QString answer;
    answer = QString("{\n") + QString("\"D\": ") + QString::number(life->N) + QString(",\n");
    answer += QString("\"SIZE\": ") + QString::number(life->SIZE) + QString(",\n");
    answer += QString("\"DATA\": \"") + QString::fromStdString(life->fileData()) + QString("\",\n");
    answer += QString("\"B\": \"") + b + QString("\",\n");
    answer += QString("\"S\": \"") + s + QString("\"\n}");
    return answer;
} 
