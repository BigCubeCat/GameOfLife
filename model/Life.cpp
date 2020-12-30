//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"
#include <malloc.h>
#include <random>
#include <string>
#include <QString>

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
    S.push_back(2);
    S.push_back(3);
    B.push_back(3);

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
    return data[index];
}

bool Life::getNewCell(int countN, bool cell) {
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

int Life::getCountNeighbours(int index) {
    /*return count living neighbours*/
    vector<int> coords;
    if ((index + 1) % SIZE != 0) // проверяем что не скраю
        coords.push_back(index + 1);
    coords.push_back(index);
    if (index % SIZE != 0)
        coords.push_back(index - 1);
    int step;
    int left, center, right;
    for (int i = 1; i < N; i++) {
        step = int_pow(SIZE, i);
        vector<int> added_coords;
        for (auto a : coords) {
            left = a - step;
            right = a + step;
            if (inWorld(left)) {
                added_coords.push_back(left);
            }
            if (inWorld(right)) {
                added_coords.push_back(right);
            }
        }
        coords.insert(coords.end(), added_coords.begin(), added_coords.end());
    }
    int countN = 0;
    for (auto a : coords) {
        if (getCell(a)) {
            countN++;
        }
    }
    return countN - ((getCell(index) ? 1 : 0));
}

void Life::nextGeneration() {
    /*Apply current rules to life data*/
    for (int i = 0; i < arraySize; i++) {
        bool cell = getCell(i);
        int count = getCountNeighbours(i);
        new_data[i] = getNewCell(count, cell);
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
    //qDebug() << QString::fromStdString(printVector(answer));
    return answer;
}

vector<bool> Life::getRenderData(int coords) const {
    // Return 3D array by coords in 4+D
    vector<bool> answer;
    for (int i = coords; i < render_size + coords; i++)
        answer.push_back(data[i]);
    return answer;
}
