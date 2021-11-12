#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#define MOD 1000000007LL

typedef long long Long;

int main() {
    int v, e;
    Long t;
    scanf("%d %d %lld", &v, &e, &t);

    std::vector<std::vector<int>> graph(v+1);

    for (int i = 0; i < e; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    std::vector<Long> prev(v+1, 0), curr(v+1, 0);
    prev[1] = 1;

    for (int i = 1; i <= t; ++i) {
        std::fill(curr.begin(), curr.end(), 0);
        for (int u = 1; u <= v; ++u) {
            for (int v : graph[u]) {
                curr[v] += prev[u];
                curr[v] %= MOD;
            }
        }
        prev = curr;
    }

    printf("%lld", std::accumulate(prev.begin(), prev.end(), 0) % MOD);

    return 0;
}