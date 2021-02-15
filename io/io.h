#ifndef GAMEOFLIFE_IO_H
#define GAMEOFLIFE_IO_H

#include <QString>
#include <QFile>
#include <vector>
#include <QJsonDocument>
#include <QJsonObject>

struct fileData {
    int         D;
    int         SIZE;
    std::vector<int> B;
    std::vector<int> S;
    QString     stringB;
    QString     stringS;
};

fileData readFile(QString fileName);

std::vector<int> getRules(QString rule);

std::vector<bool> rleDecode(QString);

void saveToFile(QString filename, QString data);

#endif
