//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"

using namespace std;

int int_pow(int a, int b) {
    // Возведение в степень в формате int
    int answer = 1;
    for (int i = 0; i < b; i++) {
        answer *= a;
    }
    return answer;
}

Life::Life(int d, int size, vector<int> b, vector<int> s) {
    for (auto i : b) {
        B[i] = true;
    }
    for (auto i : s) {
        S[i] = true;
    }
    SIZE = size;
    N = d;
    arraySize = int_pow(SIZE, N);

    data = new bool[arraySize];
    new_data = new bool[arraySize];
    for (int i = 0; i < arraySize; i++) {
        data[i] = false;
        new_data[i] = false;
    }
}

bool Life::getCell(int index) const {
    // get cell data by global index
    if (inWorld(index))
        return data[index];
    return false;
}

bool Life::applyRules(int countN, bool cell) {
    // Apply rules to cell with "countN" neighbours
    if (cell) {
        return S[countN];
    }
    return B[countN];
}

bool Life::inWorld(int index) const {
    return (index >= 0 && index < arraySize);
}

bool Life::getNewCell(int index) {
    /*return count living neighbours*/
    vector<int> coords;
    coords.push_back(index);
    int step;
    bool cell = getCell(index);
    int countN = 0;
    int left, right;
    for (int i = 0; i < N; i++) {
        step = int_pow(SIZE, i);
        vector<int> added_coords;
        for (auto a : coords) {
            left = a - step;
            right = a + step;
            if (inWorld(left)) {
                if (getCell(left))
                    countN++;
                added_coords.push_back(left);
            }
            if (inWorld(right)) {
                if (getCell(right))
                    countN++;
                added_coords.push_back(right);
            }
        }
        coords.insert(coords.end(), added_coords.begin(), added_coords.end());
    }
    return applyRules(countN, cell);
}

void Life::nextGeneration() {
    /*Apply current rules to life data*/
    for (int i = 0; i < arraySize; i++) {
        new_data[i] = getNewCell(i);
    }
    swap(data, new_data);
}

bool* Life::getRenderData(int coords) const {
    // Return 3D array by coords in 4+D
    bool* answer = new bool[arraySize];
    int j = 0;
    for (int i = coords; i < render_size + coords; i++) {
        answer[j] = getCell(i);
        j++;
    }
    return answer;
}
