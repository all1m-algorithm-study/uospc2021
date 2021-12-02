#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <set>

typedef long long Long;

int main() {
    int n;
    scanf("%d", &n);

    std::vector<std::pair<Long, int>> x;
    std::set<std::pair<Long, int>> y;
    for (int i = 1; i <= n; ++i) {
        Long v;
        scanf("%lld", &v);
        x.emplace_back(v*i, i);
    }
    for (int i = 1; i <= n; ++i) {
        Long v;
        scanf("%lld", &v);
        y.emplace(v*i, i);
    }

    int count = 0;
    for (int i = 0; i < n; ++i) {
        auto found = y.lower_bound(std::make_pair(x[i].first, 0));
        if (found != y.end() && found->first == x[i].first) {
            ++count;
            y.erase(found);
        }
    }

    printf("%d", count);

    return 0;
}
