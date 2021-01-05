//
// Created by bigcubecat on 19.12.2020.
//

#ifndef GAMEOFLIFE_WORKER_H
#define GAMEOFLIFE_WORKER_H

#include <QThread>
#include "Life.h"
#include <vector>

class Worker : public QThread {
    Q_OBJECT
public:
    Worker(int n, int s);
    Life *life;
    bool running = false;
    int coord = 0;
signals:
    void generationFinished(QVector<bool>);
public slots:
    void run();
};

#endif //GAMEOFLIFE_WORKER_H
