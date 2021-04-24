#include "permutation.h"

using namespace std;

void permutation(vector<char> al, string prefix, int k, vector<string>* a) {
    if (k == 0) {
        a->push_back(prefix);
        return;
    }
    string new_prefix = "";
    for (char ch : al) {
        new_prefix.append(&ch);
        permutation(al, new_prefix, k-1, a);
    }
}
