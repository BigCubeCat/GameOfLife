//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"
#include <malloc.h>
#include <random>
#include <string>
#include <QString>
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

Life::Life(int n, int s) {
    /*Initialization. Set dimension { n } and size { s }*/
    setNewParams(n, s);
}

void Life::setNewParams(int n, int s) {
    // Set game params
    SIZE = s;
    N = n;
    arraySize = int_pow(SIZE, N);
    clear_data();
    render_size = int_pow(SIZE, N);
    data = new bool[arraySize];
    new_data = new bool[arraySize];
    for (int i = 0; i < arraySize; i++) {
        data[i] = rand() % 2 != 0;
        new_data[i] = false;
    }
}

void Life::clear_data() const {
    /*free data*/
    free(data);
    free(new_data);
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
        for (auto s : S) {
            if (s == countN)
                return true;
        }
    } else {
        for (auto b : B) {
            if (b == countN)
                return true;
        }
    }
    return false;
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

vector<int> Life::getCoords(int index) const {
    // get array's coords by global index
    vector<int> answer;
    int indx = index;
    int n = N;
    for (int i = 0; i < N - 1; i++) {
        n = int_pow(SIZE, (N - i - 1));
        int coord = indx / n;
        //qDebug() << n;
        indx = indx % n;
        answer.push_back(coord);
    }
    answer.push_back(indx);
    return answer;
}

vector<bool> Life::getRenderData(int coords) const {
    // Return 3D array by coords in 4+D
    vector<bool> answer;
    for (int i = coords; i < render_size + coords; i++)
        answer.push_back(data[i]);
    return answer;
}
