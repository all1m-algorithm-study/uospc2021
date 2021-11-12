#include "testlib.h"
#include <iostream>
#include <algorithm>
#include <vector>

using Long = long long;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int v = atoi(argv[1]);
    int oneCount = rnd.next(1, v-1);
    int extraCount = rnd.next(0, v*(v-1)/2 - oneCount);
    int e = oneCount + extraCount;
    Long t = atoll(argv[2]);
    printf("%d %d %lld\n", v, e, t);

    std::vector<std::pair<int, int>> oneEdges;
    for (int i = 2; i <= v; ++i) {
        oneEdges.emplace_back(1, i);
    }
    std::vector<std::pair<int, int>> extraEdges;
    for (int i = 2; i <= v; ++i) {
        for (int j = i+1; j <= v; ++j) {
            extraEdges.emplace_back(i, j);
        }
    }

    auto indexes = rnd.distinct(oneCount, oneEdges.size());
    for (auto i : indexes) {
        printf("%d %d\n", oneEdges[i].first, oneEdges[i].second);
    }

    indexes = rnd.distinct(extraCount, extraEdges.size());
    for (auto i : indexes) {
        printf("%d %d\n", extraEdges[i].first, extraEdges[i].second);
    }

    return 0;
}