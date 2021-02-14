#include "io.h"


fileData readFile(QString fileName) {
    qDebug() << fileName;
    QString val;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject object = d.object();
    qDebug() << object;
    int dim = object.value(QString("D")).toInt();
    qDebug() << dim;
    int size = object.value(QString("SIZE")).toInt();
    qDebug() << size;
    auto data = object.value(QString("DATA")).toString();
    QString B = object.value(QString("B")).toString();
    QString S = object.value(QString("S")).toString();

    qDebug() << data;
    vector<bool> vector_cells = rleDecode(data);
    qDebug() << "GGGG";
    if (vector_cells.size() == 0) {
        throw;
    }
    bool *cells = new bool[vector_cells.size()];
    for (int i = 0; i < sizeof(cells); i++) {
        cells[i] = vector_cells[i];
    }

    return fileData{dim, size, getRules(B), getRules(S), B, S};
}

vector<int> getRules(QString rule) {
    vector<int> answer;
    QStringList values = rule.split(",");
    for (const auto& v : values) {
        bool no_errors = true;
        int new_value = v.toInt(&no_errors);
        if (!no_errors) return answer;
        answer.push_back(new_value);
    }
    return answer;
}

vector<bool> rleDecode(QString compressed) {
    vector<bool> original;
    for (int i = 0; i < compressed.size(); i++) {
        qDebug() << compressed.at(i);
        if (compressed.at(i) == 'A') {
            original.push_back(true);
        } else {
            original.push_back(false);
        }
    }
    return original;
}

void saveToFile(QString fileName, QString data) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly)) {
        QTextStream out(&file);
        out << data;
        file.close();
    }
}
