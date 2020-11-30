//
// Created by egor on 21.11.2020.
//

#include "Life.h"
#include <malloc.h>

using namespace std;

int int_pow(int a, int b) {
    // Возведение в степень в формате int
    int answer = 1;
    for (int i = 0; i < b; i++) {
        answer *= a;
    }
    return answer;
}

int Life::getSize() const {
    // Возращает длинну массива
    return int_pow(SIZE, N);
}

int Life::countNeighboursOnCell(const vector<int>& coords, int index) {
    vector<int> new_coords = coords; int answer = 0;
    bool last = index == (coords.size() - 1);
    for (int i = -1; i < 2; i++) {
        new_coords[index] += i;
        if (last) answer += getCell(getGlobalIndex(new_coords)) ? 1 : 0;
        else {
            answer += countNeighboursOnCell(new_coords, index + 1);
        }
    }
    return answer;
}

void Life::setNewParams(int n, int s) {
    // Задать новые параметры для игры
    SIZE = s;
    N = n;
    arraySize = getSize();
    data = (bool *)malloc(arraySize * sizeof(bool));
    new_data = (bool *)malloc(arraySize * sizeof(bool));
    for (int i = 0; i < arraySize; i++) {
        data[i] = false;
    }
}

void Life::clear_data() const {
    free(data);
    free(new_data);
}

void Life::setRules(vector<int> b, vector<int> s) {
    // Задать правила
    B = b; S = s;
}

bool Life::getCell(int index) const {
    // get cell data by global index
    return data[index];
}

bool Life::getNewCell(int countN, bool cell) {
    // Apply rules to cell with "countN" neighbours
    if (cell) {
        for (auto s : S) {
            if (s == countN) return true;
        }
    } else {
        for (auto b : B) {
            if (b == countN) return true;
        }
    }
    return false;
}

int Life::getCountNeighbours(int index) {
    int answer = 0;
    vector<int> pos = getCoords(index);
    answer = countNeighboursOnCell(pos, 0) - (getCell(index) ? 1 : 0);
    return answer;
}

void Life::nextGeneration() {
    for (int i = 0; i < arraySize; i++) {
        bool cell = getCell(i);
        new_data[i] = getNewCell(getCountNeighbours(i), cell);
    }
    swap(data, new_data);
}

int Life::getGlobalIndex(const vector<int>& coords) const {
    // return global index by array's coords
    int array_length = coords.size();
    int answer = 0;
    for (int i = 0; i < array_length; i++) {
        answer += data[i] * (array_length * (N - i));
    }
    return answer;
}

vector<int> Life::getCoords(int index) const {
    // get array's coords by global index
    vector<int> answer;
    int indx = index;
    for (int i = 0; i < N - 1; i++) {
        int coord = indx / int_pow(SIZE, (N - i));
        indx = indx % N;
        answer.push_back(coord);
    }
    answer.push_back(indx);
    return answer;
}

Life::Life(int n, int s) {
    setNewParams(n, s);
} 

