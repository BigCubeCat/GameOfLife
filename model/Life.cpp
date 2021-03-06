#include "Life.h"
#include <QDebug>

using namespace std;


void Life::setup(int d, int size, vector<int> b, vector<int> s) {
    for (auto i : b) {
        B[i] = true;
    }
    for (auto i : s) {
        S[i] = true;
    }
    generation = 0;
    SIZE = size;
    N = d;
    dataSize = intpow(SIZE, N);
    (d > 2) ? render_size = intpow(SIZE, 3) : render_size = intpow(SIZE, 2);
    steps = new int[N];
    for (int i = 0; i <= N; i++) {
        steps[i] = intpow(SIZE, i);
    }
    neighbours.push_back(0);
    for (int i = 0; i < N; i++) {

        vector<int> new_neigh;
        for (int j = 0; j < neighbours.size(); j++) {
            new_neigh.push_back(neighbours[j] - steps[i]);
            new_neigh.push_back(neighbours[j] + steps[i]);
        }
        for (int j = 0; j < new_neigh.size(); j++)
            neighbours.push_back(new_neigh[j]);
    }
}

Life::Life(int d, int size, vector<int> b, vector<int> s, int v) {
    setup(d, size, b, s);
    data = new bool[dataSize];
    new_data = new bool[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = rand() % v == 0;
        new_data[i] = false;
    }
}

Life::Life(int d, int size, vector<int> b, vector<int> s, vector<bool> cells) {
    setup(d, size, b, s);
    new_data = new bool[dataSize];
    data = new bool[dataSize];
    for (int i = 0; i < dataSize; i++) {
        new_data[i] = false;
        data[i] = cells[i];
    }
}

bool Life::getCell(int index) const {
    // get cell data by global index
    if (inWorld(index)) {
        return data[index];
    }
    return false;
}

int Life::countNeighbours(int index) {
    int countN = 0;
    int k = 1;
    for (int i = 1; i < neighbours.size(); i++) {
        /*if (i % 2 == 0) {  // check right
            qDebug() << k <<  k - 1;
            qDebug() << steps[k] <<  steps[k - 1];
            if (!(steps[k] - i % steps[k] < steps[k - 1])) {*/
                if (getCell(index + neighbours[i]))
                    countN++;
            //}
        /*} else {
            if (!(i % steps[k] < steps[k - 1])) {
                if (getCell(index + neighbours[i]) )
                    countN++;
            }
        }
        if ((i - 1) % steps[k] == 0) {
            k++;
            qDebug() << "k = " << k;
        }*/
    }
    //    qDebug() << countN;
    return countN;
}

bool Life::applyRules(int index) {
    // Apply rules to cell with "countN" neighbours
    bool cell = getCell(index);
    if (cell) {
        return S[countNeighbours(index)];
    }
    return B[countNeighbours(index)];
}

bool Life::inWorld(int index) const {
    return (index >= 0 && index < dataSize);
}

void Life::nextGeneration() {
    /*Apply current rules to life data*/
    for (int i = 0; i < dataSize; i++) {
        new_data[i] = applyRules(i);
    }
    swap(data, new_data);
    generation++;
}

std::string Life::fileData() {
    std::string answer;
    for (int i = 0; i < dataSize; i++) {
        if (getCell(i)) {
            answer += 'A';
        } else {
            answer += 'D';
        }
    }
    return answer;
}

std::string Life::renderData(int coords) {
    // Return 3D slice by coords in 4+D
    std::string answer;
    for (int i = coords; i < coords + render_size; i++) {
        if (getCell(i)) {
            answer += 'A';
        } else {
            answer += 'D';
        }
    }
    return answer;
}
