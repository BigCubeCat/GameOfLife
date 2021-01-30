//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"
#include <string>
#include <QDebug>
using namespace std;

int int_pow(int a, int b) {
    // Возведение в степень в формате int
    int answer = 1;
    for (int i = 0; i < b; i++) {
        answer *= a;
    }
    return answer;
}

Life::Life(int d, int size, vector<int> b, vector<int> s, int v) {
    for (auto i : b) {
        B[i] = true;
    }
    for (auto i : s) {
        S[i] = true;
    }
    SIZE = size;
    N = d;
    dataSize = int_pow(SIZE, N);
    (d > 2) ? render_size = int_pow(SIZE, 3) : render_size = int_pow(SIZE, 2);

    data = new bool[dataSize];
    new_data = new bool[dataSize];
    for (int i = 0; i < dataSize; i++) {
        data[i] = rand() % v == 0;
        new_data[i] = false;
    }
    steps = new int[N];
    for (int i = 0; i < N; i++) {
        steps[i] = int_pow(SIZE, i);
    }
}

bool Life::getCell(int index) const {
    // get cell data by global index
    if (inWorld(index))
        return data[index];
    return false;
}

int Life::countNeighbours(int index) {
    int countN = 0;
    vector<int> coords;
    vector<int> new_coords;
    int left, right;
    coords.push_back(0);
    for (int i = 0; i < N; i++) {
        for (auto a : coords) {
            left = a - steps[i];
            right = a + steps[i];
            
            if (inWorld(index + left)) {
                new_coords.push_back(left);
                if (getCell(index + left)) {
                    countN++;
                }
            }
            if (inWorld(index + right)) {
                new_coords.push_back(right);
                if (getCell(index + right)) {
                    countN++;
                }
            }
        }
        for (auto a : new_coords) {
            coords.push_back(a);
        }
    }
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
        qDebug() << applyRules(i);
        new_data[i] = applyRules(i);
    }
    swap(data, new_data);
}

std::string Life::renderData(int coords) {
    // Return 3D slice by coords in 4+D
    std::string answer;
    for (int i = coords; i < render_size; i++) {
        if (getCell(i)) {
            answer += 'A';
        } else {
            answer += 'D';
        }
    }
    return answer;
}
