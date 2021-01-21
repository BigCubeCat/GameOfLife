#ifndef GAMEOFLIFE_LIFE_H
#define GAMEOFLIFE_LIFE_H

#include <map>
#include <vector>
using namespace std;

class Life {
public:
    int                     N;
    int                     SIZE;
    int                     arraySize;
    bool*                   data;
    bool*                   new_data;
    map<int, bool>          B;
    map<int, bool>          S;
    int                     render_size;

    Life(int, int, vector<int>, vector<int>);
    bool                    getCell(int index) const;
    bool                    inWorld(int index) const;
    bool                    applyRules(int, bool);
    bool                    getNewCell(int index);
    bool*                   getRenderData(int coords) const;
    void                    nextGeneration();
};

#endif //GAMEOFLIFE_LIFE_H
