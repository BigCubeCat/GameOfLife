#include "reader.h"

#include <QJsonDocument>

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
    QString data = object.value(QString("DATA")).toString();
    QString B = object.value(QString("B")).toString();
    QString S = object.value(QString("S")).toString();

    vector<bool> vector_cells = rleDecode(data.toStdString());
    bool *cells = new bool[vector_cells.size()];
    for (int i = 0; i < sizeof(cells); i++) {
        cells[i] = vector_cells[i];
    }

    Life model = Life(dim, size, getRules(B), getRules(S), cells);

    return fileData{model, B, S};
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

vector<bool> rleDecode(std::string compressed) {
    vector<bool> original;
    size_t i = 0;
    size_t repeat;
    while (i < compressed.length())
    {
        while (isalpha(compressed[i]))
            original.push_back(compressed[i++]);

        // repeat number
        repeat = 0;
        while (isdigit(compressed[i]))
            repeat = 10 * repeat + (compressed[i++] - '0');

        // unroll releat charachters
        auto char_to_unroll = compressed[i++];
        while (repeat--) {
            if (char_to_unroll == 'A') {
                original.push_back(true);
            } else { 
                original.push_back(false);
            }
        }
            original.push_back(char_to_unroll);
    }
    return original;
}
