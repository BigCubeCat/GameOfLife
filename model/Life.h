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
    explicit Life(int n, int s);
    void setNewParams(int n, int s);
    bool getCell(int index) const;
    bool getNewCell(int countN, bool cell);
    int getCountNeighbours(int index);
    void clear_data() const;
    bool inWorld(int index) const;
    vector<bool> getRenderData(int coords) const;
    void nextGeneration();
private:
    vector<int> getCoords(int index) const;
};


#endif //GAMEOFLIFE_LIFE_H
