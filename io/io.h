#ifndef GAMEOFLIFE_IO_H
#define GAMEOFLIFE_IO_H

#include <QString>
#include <QFile>
#include "model/Life.h"
#include <vector>
#include <QJsonDocument>
#include <QJsonObject>

struct fileData {

    Life    model;
    QString B;
    QString S;
};

fileData readFile(QString fileName);

vector<int> getRules(QString rule);

vector<bool> rleDecode(std::string);

void saveToFile(QString filename, QString data);

#endif
