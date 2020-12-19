//
// Created by bigcubecat on 19.12.2020.
//

#ifndef GAMEOFLIFE_THREAD_H
#define GAMEOFLIFE_THREAD_H

#include <QThread>
#include "Life.h"

class Thread : public QThread {
    Q_OBJECT
public:
    explicit Thread(int n, int s);
    Life *life;
    bool running = false;

    void setDelay(int _delay);
signals:
    void generationFinished();
public slots:
    void main_process();
private:
    int delay = 0;

    void run();
};


#endif //GAMEOFLIFE_THREAD_H
