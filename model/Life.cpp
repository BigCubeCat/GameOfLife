//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"
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
    for (int i = 0; i < N; i++) {
        steps[i] = intpow(SIZE, i);
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

Life::Life(int d, int size, vector<int> b, vector<int> s, bool *dat) {
    setup(d, size, b, s);
    data = dat;
    new_data = new bool[dataSize];
    for (int i = 0; i < dataSize; i++) {
        new_data[i] = false;
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
    for (int i = coords; i < render_size; i++) {
        if (getCell(i)) {
            answer += 'A';
        } else {
            answer += 'D';
        }
    }
    return answer;
}
