//
// Created by bigcubecat on 19.12.2020.
//

#ifndef GAMEOFLIFE_WORKER_H
#define GAMEOFLIFE_WORKER_H

#include <QThread>
#include <vector>
#include "Life.h"

class Worker : public QThread {
Q_OBJECT
public:
    Worker();

    Life    *life;
    int     coord = 0;
    int     D;
    int     SIZE;
    int     generation = 0;

    bool    getCell(int index);
    void    updateParameters(int, int, vector<int>, vector<int>);

signals:

    void updateRender(bool*);

public slots:

    void run();
};

#endif //GAMEOFLIFE_WORKER_H
