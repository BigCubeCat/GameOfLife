//
// Created by bigcubecat on 19.12.2020.
//
#ifndef GAMEOFLIFE_WORKER_H
#define GAMEOFLIFE_WORKER_H

#include <QThread>
#include <vector>
#include "Life.h"
#include "io/io.h"

class Worker : public QThread {
Q_OBJECT
public:
    Worker();
    void changeCoord();
    std::string renderData;  // unencoding data like "AAADAA" where A: alive; D: dead

    Life    *life;
    int     coord = 0;
    int     D;
    int     SIZE;
    int     generation = 0;
    bool    isBusy;
    bool    lifeExists = false;

    bool    getCell(int index);
    void    updateParameters(int, int, vector<int>, vector<int>, int);
    void    setLife(fileData);
    QString getData(QString, QString);

signals:

    void updateRender(std::string);

public slots:
    void step();

    void run();
};

#endif //GAMEOFLIFE_WORKER_H
