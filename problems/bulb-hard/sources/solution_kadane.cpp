#include <iostream>
using namespace std;
#define SIZE 200002

int n;
int state[SIZE];
int dp_max[SIZE];
int dp_min[SIZE];

int ans = 0;

int main() {
    cin >> n;
    for (int i=1; i<=n; i++) {
        int v; cin >> v;
        state[i] = (v == 1) ? 1 : -1;
    }

    for (int i=1; i<=n; i++) {
        dp_max[i] = max(dp_max[i-1] + state[i], state[i]);
        dp_min[i] = min(dp_min[i-1] + state[i], state[i]);
    }

    int sum = 0;
    for (int i=1; i<=n; i++) sum += state[i];

    for (int i=1; i<=n; i++) {
        ans = max(ans, dp_max[i]);
        ans = max(ans, sum - dp_min[i]);
    }

    cout << ans;
}
