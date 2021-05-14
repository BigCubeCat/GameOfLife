#ifndef GAMEOFLIFE_LIFE_H
#define GAMEOFLIFE_LIFE_H

#include <map>
#include <vector>
#include <string>
#include "utils/intpow.h"
using namespace std;

class Life {
public:
    int                         N;
    int                         SIZE;
    int                         dataSize;
    bool*                       data;
    bool*                       new_data;
    int                         generation;
    map<int, bool>              B;
    map<int, bool>              S;
    int                         render_size;
    int*                        steps;
    map<string, vector<int>>    neighbors;
    vector<string>              points;
    vector<int>                 coords;

    Life(int, int, vector<int>, vector<int>, int);          /*init with random arena*/
    Life(int, int, vector<int>, vector<int>, vector<bool>);        /*init with exists data*/
    void                        setRules(vector<int>, vector<int>);
    bool                        getCell(int index) const;
    void                        setCell(int index);
    bool                        inWorld(int index) const;
    bool                        applyRules(int);
    int                         countNeighbors(int index);
    string                      renderData(int coords);
    string                      fileData();
    string                      checkBorders(int);
    void                        nextGeneration();
private:
    void                        setup(int, int, vector<int>, vector<int>);
};

#endif //GAMEOFLIFE_LIFE_H
