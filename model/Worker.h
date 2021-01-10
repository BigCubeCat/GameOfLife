//
// Created by bigcubecat on 19.12.2020.
//

#ifndef GAMEOFLIFE_WORKER_H
#define GAMEOFLIFE_WORKER_H

#include <QThread>
#include <vector>
#include "life.h"

class Worker : public QThread {
Q_OBJECT
public:
    Worker(int, int, int *, int *, bool);
    Worker();

    int coord = 0;
    int D;
    int SIZE;
    int generation = 0;

    void updateParameters(int, int, int *, int *, bool);
    bool getCell(int index);

signals:

    void generationFinished(bool*);

public slots:

    void run();
};

#endif //GAMEOFLIFE_WORKER_H
