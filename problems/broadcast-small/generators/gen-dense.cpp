#include "testlib.h"
#include <iostream>
#include <algorithm>

using Long = long long;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int v = atoi(argv[1]);
    Long t = atoll(argv[2]);
    printf("%d %d %lld\n", v, v*(v-1)/2, t);

    for (int i = 1; i <= v; ++i) {
        for (int j = i+1; j <= v; ++j) {
            printf("%d %d\n", i, j);
        }
    }

    return 0;
}