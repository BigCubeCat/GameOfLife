#include "io.h"

#include <vector>

using namespace std;

fileData readFile(QString fileName) {
    QString val;
    QFile file;
    file.setFileName(fileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject object = d.object();
    int dim = object.value(QString("D")).toInt();
    int size = object.value(QString("SIZE")).toInt();
    auto data = object.value(QString("DATA")).toString();
    QString B = object.value(QString("B")).toString();
    QString S = object.value(QString("S")).toString();

    auto vector_cells = rleDecode(data);
    if (vector_cells.empty()) {
        throw;
    }
    bool *cells = new bool[vector_cells.size()];
    for (int i = 0; i < sizeof(cells); i++) {
        cells[i] = vector_cells[i];
    }

    return fileData{dim, size, getRules(B), getRules(S), B, S, vector_cells};
}

vector<int> getRules(QString rule) {
    vector<int> answer;
    QStringList values = rule.split(",");
    for (const auto &v : values) {
        bool no_errors = true;
        int new_value = v.toInt(&no_errors);
        if (!no_errors) {
            QStringList range = v.split(".");
            int s, f;
            s = range.at(0).toInt(&no_errors);
            if (!no_errors) return answer;
            f = range.at(1).toInt(&no_errors);
            if (!no_errors) return answer;
            for (int i = s; i <= f; i++) {
                answer.push_back(i);
            }
        } else {
            answer.push_back(new_value);
        }
    }
    return answer;
}

vector<bool> rleDecode(QString compressed) {
    unsigned int num = 0;
    vector<bool> original;
    auto data = compressed.toStdString();
    int a;
    for (QChar c : data) {
        a = c.digitValue();
        if (a == -1) {
            bool value = (c == 'A');
            while (num--) {
                original.push_back(value);
            }
            num = 0;
        } else {
            num = num * 10 + a;
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
