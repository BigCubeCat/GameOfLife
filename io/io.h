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
    vector<int> B;
    vector<int> S;
    QString     stringB;
    QString     stringS;
};

fileData readFile(QString fileName);

vector<int> getRules(QString rule);

vector<bool> rleDecode(QString);

void saveToFile(QString filename, QString data);

#endif
