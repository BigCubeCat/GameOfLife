#ifndef GAMEOFLIFE_LIFE_H
#define GAMEOFLIFE_LIFE_H

#include <map>
#include <vector>
#include <string>
#include "../intpow.h"
using namespace std;

class Life {
public:
    int                     N;
    int                     SIZE;
    int                     dataSize;
    int                     generation;
    bool*                   data;
    bool*                   new_data;
    map<int, bool>          B;
    map<int, bool>          S;
    int                     render_size;
    int*                    steps;

    Life(int, int, vector<int>, vector<int>, int);          /*init with random arena*/
    Life(int, int, vector<int>, vector<int>, vector<bool>);        /*init with exists data*/
    bool                    getCell(int index) const;
    bool                    inWorld(int index) const;
    bool                    applyRules(int);
    int                     countNeighbours(int index);
    string                  renderData(int coords);
    string                  fileData();
    void                    nextGeneration();
private:
    void                    setup(int, int, vector<int>, vector<int>);
};

#endif //GAMEOFLIFE_LIFE_H
