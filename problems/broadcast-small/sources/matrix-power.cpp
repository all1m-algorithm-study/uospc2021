#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#define MOD 1000000007LL

using Long = long long;
using Matrix = std::vector<std::vector<Long>>;

Matrix multiply(Matrix m1, Matrix m2) {
    int h = m1.size();
    Matrix result(h, std::vector<Long>(h, 0));
    
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < h; ++j) {
            for (int k = 0; k < h; ++k) {
                result[i][j] += m1[i][k] * m2[k][j];
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

Matrix getPower(Matrix m, Long e) {
    if (e == 1) {
        return m;
    } else {
        Matrix sub = getPower(m, e/2);
        Matrix even = multiply(sub, sub);
        return (e % 2 == 0 ? even : multiply(even, m));
    }
}

int main() {
    int v, e;
    Long t;
    scanf("%d %d %lld", &v, &e, &t);

    Matrix coeff(v, std::vector<Long>(v, 0));

    for (int i = 0; i < e; ++i) {
        int u, v;
        scanf("%d %d", &u, &v);
        --u; --v;
        coeff[u][v] += 1;
        coeff[v][u] += 1;
    }

    coeff = getPower(coeff, t);
    Long result = 0;
    for (int i = 0; i < v; ++i) {
        result += coeff[i][0];
        result %= MOD;
    }

    printf("%lld", result);

    return 0;
}