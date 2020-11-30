#ifndef GAMEOFLIFE_LIFE_H
#define GAMEOFLIFE_LIFE_H

#include <vector>
using namespace std;

class Life {
public:
    int N{};
    int SIZE{};
    int arraySize{};
    bool* data{};
    bool* new_data{};
    vector<int> B;
    vector<int> S;
    long long int generation{};
    explicit Life(int n, int s);
    void setNewParams(int n, int s);
    void setRules(vector<int> b, vector<int> s);
    void nextGeneration();
    int getGlobalIndex(const vector<int>& coords) const;
    bool getCell(int index) const;
    bool getNewCell(int countN, bool cell);
    int getCountNeighbours(int index);
    void clear_data() const;

private:
    int countNeighboursOnCell(const vector<int>& coords, int index);
    vector<int> getCoords(int index) const;
    int getSize() const;
};


#endif //GAMEOFLIFE_LIFE_H
