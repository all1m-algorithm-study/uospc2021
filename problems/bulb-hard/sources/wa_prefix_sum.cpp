#include <iostream>
using namespace std;
#define SIZE 200002

int n;
int state[SIZE];
int pf_sum[SIZE];
int pf_max[SIZE];
int pf_min[SIZE];
int sf_sum[SIZE];
int sf_max[SIZE];
int sf_min[SIZE];

int ans = 0;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int v; cin >> v;
        state[i] = (v == 1) ? 1 : -1;
    }

    fill(pf_max+1, pf_max+1+n, -n);
    fill(pf_min+1, pf_min+1+n, n);
    fill(sf_max+1, sf_max+1+n, -n);
    fill(sf_min+1, sf_min+1+n, n);

    for (int i=1; i<=n; i++) {
        pf_sum[i] = pf_sum[i-1] + state[i];
        pf_max[i] = max(pf_max[i-1], pf_sum[i]);
        pf_min[i] = min(pf_min[i-1], pf_sum[i]);
    }

    for (int i=n; i>0; i--) {
        sf_sum[i] = sf_sum[i+1] + state[i];
        sf_max[i] = max(sf_max[i-1], sf_sum[i]);
        sf_min[i] = min(sf_min[i-1], sf_sum[i]);
    }

    for (int i=2; i<=n; i++) {
        ans = max(ans, pf_max[i-1] + sf_max[i]);
        ans = max(ans, pf_sum[n] - pf_min[i-1] - sf_min[i]);
    }

    cout << ans;
}
