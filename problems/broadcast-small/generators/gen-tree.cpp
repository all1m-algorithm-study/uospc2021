#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>

class DisjointSet
{
private:
    std::vector<int> parent;
public:
    DisjointSet(int count) {
        parent.resize(count);
        for (int i = 0; i < count; ++i) {
            parent[i] = i;
        }
    }

    int findParent(int x){
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = findParent(parent[x]);
    }

    void unionNodes(int x, int y) {
        int xPar = findParent(x);
        int yPar = findParent(y);
        parent[xPar] = yPar;
    }
};

using Long = long long;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int v = atoi(argv[1]);
    Long t = atoll(argv[2]);
    printf("%d %d %lld\n", v, v-1, t);

    std::vector<std::pair<int, int>> allEdges;
    for (int i = 1; i <= v; ++i) {
        for (int j = i+1; j <= v; ++j) {
            allEdges.emplace_back(i, j);
        }
    }

    auto indexes = rnd.perm(allEdges.size());
    DisjointSet dsu(v+1);
    for (auto i : indexes) {
        int a = allEdges[i].first;
        int b = allEdges[i].second;
        if (dsu.findParent(a) != dsu.findParent(b)) {
            dsu.unionNodes(a, b);
            printf("%d %d\n", a, b);
        }
    }

    return 0;
}