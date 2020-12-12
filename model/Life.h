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
    int render_size;
    long long int generation{};
    explicit Life(int n, int s);
    void setNewParams(int n, int s);
    void nextGeneration();
    int getGlobalIndex(const vector<int>& coords) const;
    bool getCell(int index) const;
    bool getNewCell(int countN, bool cell);
    int getCountNeighbours(int index);
    void clear_data() const;
    bool inWorld(int index);
    vector<bool> getRenderData(vector<int> coords);

private:
    int countNeighboursOnCell(const vector<int>& coords, int index);
    vector<int> getCoords(int index) const;
};


#endif //GAMEOFLIFE_LIFE_H
