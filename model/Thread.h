//
// Created by bigcubecat on 19.12.2020.
//

#ifndef GAMEOFLIFE_THREAD_H
#define GAMEOFLIFE_THREAD_H

#include <QThread>
#include "Life.h"
#include <vector>

class Thread : public QThread {
    Q_OBJECT
public:
    Thread(int n, int s);
    Life *life;
    bool running = false;
    int coord = 0;
signals:
    void generationFinished(QVector<bool>);
public slots:
    void run();
};

#endif //GAMEOFLIFE_THREAD_H
