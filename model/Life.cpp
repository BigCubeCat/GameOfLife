//
// Created by bigcubecat on 21.11.2020.
//
#include "Life.h"
#include "../utils/permutation.h"

using namespace std;


void Life::setup(int d, int size, vector<int> b, vector<int> s) {
    for (auto i : b) {
        B[i] = true;
    }
    for (auto i : s) {
        S[i] = true;
    }
    SIZE = size;
    N = d;
    dataSize = intpow(SIZE, N);
    (d > 2) ? render_size = intpow(SIZE, 3) : render_size = intpow(SIZE, 2);
    steps = new int[N];
    for (int i = 0; i <= N; i++) {
        steps[i] = intpow(SIZE, i);
    }
    int left, right;
    map<int, string> points;
    points[0] = "";
    coords.push_back(0);
    for (int i = 0; i < N; i++) {
        auto s = steps[i];
        vector<int> new_coords;
        for (auto a : coords) {
            left = a - s;
            right = a + s;
            new_coords.push_back(left);
            new_coords.push_back(right);
            points[left] = points[a] + "L";
            points[right] = points[a] + "R";
        }
        for (auto a : coords) {
            points[a] += "M";
        }
        coords.insert(coords.end(), new_coords.begin(), new_coords.end());
        new_coords.clear();
    }
    vector<char> al;
    al.push_back('L'); al.push_back('M'); al.push_back('R'); 
    vector<string> *per;
    permutation(al, "", N, per);
    for (auto p : *per) {
        map<string, int> coo;
        for (auto k : points) {
            coo[k.second] = k.first;
        }
        for (int index = 0; index < p.length(); index++) {
            char c = p[index];
            for (auto& key : coo) {
                if (key.first[index] == c) {
                    int diff = 0;
                    switch (c) {
                        case 'L':
                            diff = 1;
                        case 'R':
                            diff = -1;
                    }
                    coo[key.first] += diff * steps[index+1];
                }
            }
        }
        vector<int> _list;
        for (auto k : coo) {
            _list.push_back(k.second);
        }
        neighbors[p] = _list;
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
    vector<int> coords;
    vector<int> new_coords;
    int left, right;
    bool isLeft, isRight;
    coords.push_back(0);
    for (int i = 0; i < N; i++) {
        isLeft = index % SIZE == 0;
        isRight == (index + steps[i]) % SIZE == 0;
        if (isLeft || isRight) 
            continue;
        for (auto a : coords) {
            if (!isLeft) {
                left = a - steps[i];
                if (inWorld(index + left)) {
                    new_coords.push_back(left);
                    if (getCell(index + left)) {
                        countN++;
                    }
                }
            }

            if (!isRight) {
                right = a + steps[i];
                if (inWorld(index + right)) {
                    new_coords.push_back(right);
                    if (getCell(index + right)) {
                        countN++;
                    }
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
    for (int i = coords; i < coords + render_size; i++) {
        if (getCell(i)) {
            answer += 'A';
        } else {
            answer += 'D';
        }
    }
    return answer;
}
