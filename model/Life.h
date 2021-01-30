#ifndef GAMEOFLIFE_LIFE_H
#define GAMEOFLIFE_LIFE_H

#include <map>
#include <vector>
#include <string>
using namespace std;

class Life {
public:
    int                     N;
    int                     SIZE;
    int                     dataSize;
    bool*                   data;
    bool*                   new_data;
    map<int, bool>          B;
    map<int, bool>          S;
    int                     render_size;
    int*                    steps;

    Life(int, int, vector<int>, vector<int>, int);
    bool                    getCell(int index) const;
    bool                    inWorld(int index) const;
    bool                    applyRules(int);
    int                     countNeighbours(int index);
    string                  renderData(int coords);
    void                    nextGeneration();
};

#endif //GAMEOFLIFE_LIFE_H
